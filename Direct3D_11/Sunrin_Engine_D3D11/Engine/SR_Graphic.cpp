#include "SR_PCH.h"

#include "SR_Graphic.h"
#include "SR_App.h"
#include "SR_RenderDescription.h"

namespace SunrinEngine
{

	SR_Graphic::SR_Graphic() noexcept :
		m_isEnableVSync				{ false },
		m_VSyncLevel				{ 0 },
		m_dxgiFactory				{ nullptr },
		m_dxgiAdapter				{ nullptr },
		m_dxgiDevice				{ nullptr },
		m_dxgiSwapChain				{ nullptr },
		m_d3dDebug					{ nullptr },
		m_d3dDevice					{ nullptr },
		m_d3dImmediateContext		{ nullptr },
		m_d3dDeferredContext		{ nullptr, nullptr, nullptr, nullptr },
		m_d2dFactory				{ nullptr },
		m_d2dDevice					{ nullptr },
		m_d2dDeviceContext			{ nullptr },
		m_WICImagingFactory			{ nullptr },
		m_d3dRenderTargetTexture	{ nullptr },
		m_d3dDepthStencilTexture	{ nullptr },
		m_d3dRenderTargetView		{ nullptr },
		m_d3dDepthStencilView		{ nullptr },
		m_d2dTargetSurface			{ nullptr },
		m_d2dTargetBitmap			{ nullptr },
		m_d3dViewport				{}
	{

	}

	SR_Graphic::~SR_Graphic()
	{
		//SR_LOG_HR_AUTO(m_d3dDebug->ReportLiveDeviceObjects(D3D11_RLDO_DETAIL));
	}

	bool SR_Graphic::Initialize()
	{
		// Create Device Interfaces
		SR_RF_BOOL(CreateDeviceInterfaces());

		// Log Adapter
		SR_RF_BOOL(LogAdapter());

		// Create Resources
		SR_RF_BOOL(CreateWindowSizeDependentResources(
			SR_App::GetInstance()->GetClientWidth(),
			SR_App::GetInstance()->GetClientHeight()));

		return true;
	}

	bool SR_Graphic::Present()
	{
		// Present Swap Chain Buffer
		SR_LOG_RF_HR_AUTO(m_dxgiSwapChain->Present((m_isEnableVSync) ? m_VSyncLevel : 0, NULL));

		return true;
	}

	bool SR_Graphic::ResizeTarget(unsigned width, unsigned height)
	{
		// Resize Swap Chain Target
		DXGI_MODE_DESC modeDesc;
		modeDesc.Width = width;
		modeDesc.Height = height;
		modeDesc.RefreshRate.Numerator = 0;
		modeDesc.RefreshRate.Denominator = 1;
		modeDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		modeDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE;
		modeDesc.Scaling = DXGI_MODE_SCALING_STRETCHED;

		SR_LOG_RF_HR_AUTO(m_dxgiSwapChain->ResizeTarget(&modeDesc));

		return true;
	}

	bool SR_Graphic::ResizeBuffers(unsigned width, unsigned height)
	{
		// Empty the Contexts
		m_d3dImmediateContext->ClearState();
		m_d2dDeviceContext->SetTarget(nullptr);

		// Resize Swap Chain Buffer
		SR_LOG_RF_HR_AUTO(m_dxgiSwapChain->ResizeBuffers(1, width, height, DXGI_FORMAT_B8G8R8A8_UNORM, NULL));

		// Re-Create Resources
		SR_RF_BOOL(CreateWindowSizeDependentResources(width, height));

		return true;
	}

	void SR_Graphic::RecordXML()
	{
		SR_App::GetInstance()->GetProgramSettingXML().SetIsEnableVSync(m_isEnableVSync);
		SR_App::GetInstance()->GetProgramSettingXML().SetVSyncLevel(m_VSyncLevel);
	}

	bool SR_Graphic::CreateDeviceInterfaces()
	{
		// Create DXGI Factory
		UINT createDXGIFactory2Flag{ 0 };
#if defined(DEBUG) || defined(_DEBUG)
		createDXGIFactory2Flag |= DXGI_CREATE_FACTORY_DEBUG;
#endif
		SR_LOG_RF_HR_AUTO(CreateDXGIFactory2(
			createDXGIFactory2Flag,
			IID_PPV_ARGS(&m_dxgiFactory)));

		// Create D2D1 Factory
		D2D1_FACTORY_OPTIONS d2d1FactoryOptions;
		d2d1FactoryOptions.debugLevel = D2D1_DEBUG_LEVEL_INFORMATION;

		SR_LOG_RF_HR_AUTO(D2D1CreateFactory(
			D2D1_FACTORY_TYPE_MULTI_THREADED,
			d2d1FactoryOptions,
			m_d2dFactory.GetAddressOf()));

		// Create D3D Device, Immediate Context and Deferred Contexts
		UINT d3d11CreateDeviceFlag{ 0 };
		d3d11CreateDeviceFlag |= D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#if defined(DEBUG) || defined(_DEBUG)
		d3d11CreateDeviceFlag |= D3D11_CREATE_DEVICE_DEBUG;
#endif
		constexpr unsigned d3dDesiredFeatureLevelCount{ 2 };
		D3D_FEATURE_LEVEL d3dDesiredFeatureLevels[d3dDesiredFeatureLevelCount] = {
			D3D_FEATURE_LEVEL_11_1,
			D3D_FEATURE_LEVEL_11_0
		};
		D3D_FEATURE_LEVEL d3dResultFeatureLevel;

		SR_LOG_RF_HR_AUTO(D3D11CreateDevice(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			0,
			d3d11CreateDeviceFlag,
			d3dDesiredFeatureLevels,
			d3dDesiredFeatureLevelCount,
			D3D11_SDK_VERSION,
			m_d3dDevice.GetAddressOf(),
			&d3dResultFeatureLevel,
			m_d3dImmediateContext.GetAddressOf()));

		for (unsigned i{ 0 }; i < SR_MAX_THREAD_COUNT; ++i)
		{
			SR_LOG_RF_HR_AUTO(m_d3dDevice->CreateDeferredContext(
				0,
				m_d3dDeferredContext[i].GetAddressOf()));
		}

		// Create D3D Debug
		SR_LOG_RF_HR_AUTO(m_d3dDevice->QueryInterface(IID_PPV_ARGS(m_d3dDebug.GetAddressOf())));

		// Create DXGI Device
		SR_LOG_RF_HR_AUTO(m_d3dDevice->QueryInterface(IID_PPV_ARGS(m_dxgiDevice.GetAddressOf())));

		// Create D2D Device and Device Context
		SR_LOG_RF_HR_AUTO(m_d2dFactory->CreateDevice(
			m_dxgiDevice.Get(),
			m_d2dDevice.GetAddressOf()));

		SR_LOG_RF_HR_AUTO(m_d2dDevice->CreateDeviceContext(
			D2D1_DEVICE_CONTEXT_OPTIONS_ENABLE_MULTITHREADED_OPTIMIZATIONS,
			m_d2dDeviceContext.GetAddressOf()));

		// Create WIC Imaging Factory
		SR_LOG_RF_HR_AUTO(CoInitializeEx(NULL, COINIT_MULTITHREADED));
		SR_LOG_RF_HR_AUTO(CoCreateInstance(CLSID_WICImagingFactory2, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_WICImagingFactory)));

		// Create DXGI SwapChain
		DXGI_SWAP_CHAIN_DESC1 swapChainDesc;
		swapChainDesc.Width = 0;
		swapChainDesc.Height = 0;
		swapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		swapChainDesc.Stereo = FALSE;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferCount = 1;
		swapChainDesc.Scaling = DXGI_SCALING_STRETCH;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swapChainDesc.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
		swapChainDesc.Flags = NULL;

		SR_LOG_RF_HR_AUTO(m_dxgiFactory->CreateSwapChainForHwnd(
			m_d3dDevice.Get(),
			SR_App::GetInstance()->GetWindowHandle(),
			&swapChainDesc,
			nullptr,
			nullptr,
			m_dxgiSwapChain.GetAddressOf()));

		return true;
	}

	bool SR_Graphic::CreateWindowSizeDependentResources(unsigned width, unsigned height)
	{
		// Create D3D Render Target Texture
		SR_LOG_RF_HR_AUTO(m_dxgiSwapChain->GetBuffer(
			0,
			IID_PPV_ARGS(m_d3dRenderTargetTexture.ReleaseAndGetAddressOf())));

		// Create D3D Render Target View
		SR_LOG_RF_HR_AUTO(m_d3dDevice->CreateRenderTargetView(
			m_d3dRenderTargetTexture.Get(),
			nullptr,
			m_d3dRenderTargetView.ReleaseAndGetAddressOf()));

		// Create D3D Depth Stencil Texture
		SR_Texture2DDesc DSTextureDesc;
		DSTextureDesc.SetWidth(width);
		DSTextureDesc.SetHeight(height);
		DSTextureDesc.SetFormat(DXGI_FORMAT_R24G8_TYPELESS);
		DSTextureDesc.SetBindFlags(D3D11_BIND_DEPTH_STENCIL);

		SR_LOG_RF_HR_AUTO(m_d3dDevice->CreateTexture2D(
			&DSTextureDesc.m_desc,
			NULL,
			m_d3dDepthStencilTexture.ReleaseAndGetAddressOf()));

		// Create D3D Depth Stencil View
		SR_DepthStencilViewDesc DSViewDesc;
		DSViewDesc.SetFormat(DXGI_FORMAT_D24_UNORM_S8_UINT);
		DSViewDesc.SetViewDimensions(D3D11_DSV_DIMENSION_TEXTURE2D);

		SR_LOG_RF_HR_AUTO(m_d3dDevice->CreateDepthStencilView(
			m_d3dDepthStencilTexture.Get(),
			&DSViewDesc.m_desc,
			m_d3dDepthStencilView.ReleaseAndGetAddressOf()));

		// Create D2D Target Surface
		SR_LOG_RF_HR_AUTO(m_dxgiSwapChain->GetBuffer(
			0,
			IID_PPV_ARGS(m_d2dTargetSurface.ReleaseAndGetAddressOf())));

		// Create D2D Target Bitmap
		D2D1_BITMAP_PROPERTIES1 properties = D2D1::BitmapProperties1(
			D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW,
			D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE));

		SR_LOG_RF_HR_AUTO(m_d2dDeviceContext->CreateBitmapFromDxgiSurface(m_d2dTargetSurface.Get(), &properties, m_d2dTargetBitmap.ReleaseAndGetAddressOf()));

		// Modify Viewport
		m_d3dViewport.m_topLeftX = 0.0f;
		m_d3dViewport.m_topLeftY = 0.0f;
		m_d3dViewport.m_width = static_cast<float>(width);
		m_d3dViewport.m_height = static_cast<float>(height);
		m_d3dViewport.m_minDepth = 0.0f;
		m_d3dViewport.m_maxDepth = 1.0f;

		return true;
	}

	bool SR_Graphic::LogAdapter()
	{
		SR_App::GetInstance()->GetLog().LineOpen();

		Microsoft::WRL::ComPtr<IDXGIAdapter> adapter{ nullptr };
		SR_LOG_RF_HR_AUTO(m_dxgiDevice->GetAdapter(adapter.GetAddressOf()));

		DXGI_ADAPTER_DESC adapterDesc;
		adapter->GetDesc(&adapterDesc);

		SR_App::GetInstance()->GetLog().WriteLine(L">>> Graphic Adapter for D3DDevice");
		SR_App::GetInstance()->GetLog().WriteLine(adapterDesc.Description);

		SR_App::GetInstance()->GetLog().LineClose();

		return true;
	}

}