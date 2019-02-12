#pragma once

#include "SR_NonCopyable.h"
#include "SR_Viewport.h"

namespace SunrinEngine
{

	class SR_Graphic : public SR_NonCopyable
	{
	public:
		explicit SR_Graphic() noexcept;
		~SR_Graphic();

		bool Initialize();

		bool Present();
		bool ResizeTarget(unsigned width, unsigned height);
		bool ResizeBuffers(unsigned width, unsigned height);

		void RecordXML();

		void SetIsEnableVSync(bool isEnableVSync) { m_isEnableVSync = isEnableVSync; }
		void SetVSyncLevel(unsigned VSyncLevel) { m_VSyncLevel = VSyncLevel; }

		ID3D11Device * GetD3DDevice() const noexcept { return m_d3dDevice.Get(); }
		ID3D11DeviceContext * GetD3DImmediateContext() const noexcept { return m_d3dImmediateContext.Get(); }
		ID3D11DeviceContext * GetD3DDeferredContext(unsigned index) const { return m_d3dDeferredContext[index].Get(); }
		ID2D1Device * Getd2DDevice() const noexcept { return m_d2dDevice.Get(); }
		ID2D1DeviceContext * GetD2DDeviceContext() const noexcept { return m_d2dDeviceContext.Get(); }
		IWICImagingFactory2 * GetWICImagingFactory() const noexcept { return m_WICImagingFactory.Get(); }

		ID3D11RenderTargetView * GetSwapChainRenderTargetView() const noexcept { return m_d3dRenderTargetView.Get(); }
		ID3D11DepthStencilView * GetSwapChainDepthStencilView() const noexcept { return m_d3dDepthStencilView.Get(); }
		ID2D1Bitmap1 * GetSwapChainTargetBitmap() const noexcept { return m_d2dTargetBitmap.Get(); }
		SR_Viewport * GetSwapChainViewport() noexcept { return &m_d3dViewport; }

	private:
		bool CreateDeviceInterfaces();
		bool CreateWindowSizeDependentResources(unsigned width, unsigned height);

		bool LogAdapter();

	private:
		bool m_isEnableVSync;
		unsigned m_VSyncLevel;

		Microsoft::WRL::ComPtr<IDXGIFactory2> m_dxgiFactory;
		Microsoft::WRL::ComPtr<IDXGIAdapter> m_dxgiAdapter;
		Microsoft::WRL::ComPtr<IDXGIDevice> m_dxgiDevice;
		Microsoft::WRL::ComPtr<IDXGISwapChain1> m_dxgiSwapChain;

		Microsoft::WRL::ComPtr<ID3D11Debug> m_d3dDebug;
		Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_d3dImmediateContext;
		std::array<Microsoft::WRL::ComPtr<ID3D11DeviceContext>, SR_MAX_THREAD_COUNT> m_d3dDeferredContext;

		Microsoft::WRL::ComPtr<ID2D1Factory1> m_d2dFactory;
		Microsoft::WRL::ComPtr<ID2D1Device> m_d2dDevice;
		Microsoft::WRL::ComPtr<ID2D1DeviceContext> m_d2dDeviceContext;
		Microsoft::WRL::ComPtr<IWICImagingFactory2> m_WICImagingFactory;

		Microsoft::WRL::ComPtr<ID3D11Texture2D> m_d3dRenderTargetTexture;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> m_d3dDepthStencilTexture;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_d3dRenderTargetView;
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> m_d3dDepthStencilView;
		Microsoft::WRL::ComPtr<IDXGISurface> m_d2dTargetSurface;
		Microsoft::WRL::ComPtr<ID2D1Bitmap1> m_d2dTargetBitmap;
		SR_Viewport m_d3dViewport;

	};

}