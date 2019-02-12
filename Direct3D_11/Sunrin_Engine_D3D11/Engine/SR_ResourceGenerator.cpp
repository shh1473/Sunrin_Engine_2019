#include "SR_PCH.h"

#include "SR_ResourceGenerator.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_ResourceGenerator::SR_ResourceGenerator() noexcept :
		m_interfaces	{},
		m_viewports		{},
		m_scissorRects	{},
		m_meshes		{},
		m_shaders		{},
		m_bitmaps		{},
		m_effects		{},
		m_sounds		{},
		m_vector2s		{},
		m_vector3s		{},
		m_vector4s		{}
	{

	}

	SR_ResourceGenerator::~SR_ResourceGenerator() noexcept
	{
		for (auto iter : m_interfaces)
		{
			SR_RELEASE(iter);
		}
	}

	bool SR_ResourceGenerator::CreateBuffer(const D3D11_BUFFER_DESC * desc, const D3D11_SUBRESOURCE_DATA * initialData, ID3D11Buffer ** out_buffer)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateBuffer(desc, initialData, out_buffer));

		m_interfaces.push_back(*out_buffer);

		return true;
	}

	bool SR_ResourceGenerator::CreateTexture1D(const D3D11_TEXTURE1D_DESC * desc, const D3D11_SUBRESOURCE_DATA * initialData, ID3D11Texture1D ** out_texture1D)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateTexture1D(desc, initialData, out_texture1D));

		m_interfaces.push_back(*out_texture1D);

		return true;
	}

	bool SR_ResourceGenerator::CreateTexture2D(const D3D11_TEXTURE2D_DESC * desc, const D3D11_SUBRESOURCE_DATA * initialData, ID3D11Texture2D ** out_texture2D)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateTexture2D(desc, initialData, out_texture2D));

		m_interfaces.push_back(*out_texture2D);

		return true;
	}

	bool SR_ResourceGenerator::CreateTexture3D(const D3D11_TEXTURE3D_DESC * desc, const D3D11_SUBRESOURCE_DATA * initialData, ID3D11Texture3D ** out_texture3D)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateTexture3D(desc, initialData, out_texture3D));

		m_interfaces.push_back(*out_texture3D);

		return true;
	}

	bool SR_ResourceGenerator::CreateRenderTargetView(const D3D11_RENDER_TARGET_VIEW_DESC * desc, ID3D11Resource * resource, ID3D11RenderTargetView ** out_renderTargetView)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateRenderTargetView(resource, desc, out_renderTargetView));

		m_interfaces.push_back(*out_renderTargetView);

		return true;
	}

	bool SR_ResourceGenerator::CreateDepthStencilView(const D3D11_DEPTH_STENCIL_VIEW_DESC * desc, ID3D11Resource * resource, ID3D11DepthStencilView ** out_depthStencilView)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateDepthStencilView(resource, desc, out_depthStencilView));

		m_interfaces.push_back(*out_depthStencilView);

		return true;
	}

	bool SR_ResourceGenerator::CreateShaderResourceView(const D3D11_SHADER_RESOURCE_VIEW_DESC * desc, ID3D11Resource * resource, ID3D11ShaderResourceView ** out_shaderResourceView)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateShaderResourceView(resource, desc, out_shaderResourceView));

		m_interfaces.push_back(*out_shaderResourceView);

		return true;
	}

	bool SR_ResourceGenerator::CreateUnorderedAccessView(const D3D11_UNORDERED_ACCESS_VIEW_DESC * desc, ID3D11Resource * resource, ID3D11UnorderedAccessView ** out_unorderedAccessView)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateUnorderedAccessView(resource, desc, out_unorderedAccessView));

		m_interfaces.push_back(*out_unorderedAccessView);

		return true;
	}

	bool SR_ResourceGenerator::CreateSamplerState(const D3D11_SAMPLER_DESC * desc, ID3D11SamplerState ** out_samplerState)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateSamplerState(desc, out_samplerState));

		m_interfaces.push_back(*out_samplerState);

		return true;
	}

	bool SR_ResourceGenerator::CreateDepthStencilState(const D3D11_DEPTH_STENCIL_DESC * desc, ID3D11DepthStencilState ** out_depthStencilState)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateDepthStencilState(desc, out_depthStencilState));

		m_interfaces.push_back(*out_depthStencilState);

		return true;
	}

	bool SR_ResourceGenerator::CreateBlendState(const D3D11_BLEND_DESC * desc, ID3D11BlendState ** out_blendState)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateBlendState(desc, out_blendState));

		m_interfaces.push_back(*out_blendState);

		return true;
	}

	bool SR_ResourceGenerator::CreateRasterizerState(const D3D11_RASTERIZER_DESC * desc, ID3D11RasterizerState ** out_rasterizerState)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateRasterizerState(desc, out_rasterizerState));

		m_interfaces.push_back(*out_rasterizerState);

		return true;
	}

	bool SR_ResourceGenerator::CreateClassLinkage(ID3D11ClassLinkage ** out_classLinkage)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateClassLinkage(out_classLinkage));

		m_interfaces.push_back(*out_classLinkage);

		return true;
	}

	bool SR_ResourceGenerator::CreateViewport(float topLeftX, float topLeftY, float width, float height, float minDepth, float maxDepth, SR_Viewport ** out_viewport)
	{
		*out_viewport = new SR_Viewport(topLeftX, topLeftY, width, height, minDepth, maxDepth);

		m_viewports.emplace_back(*out_viewport);

		return true;
	}

	bool SR_ResourceGenerator::CreateViewport(const D3D11_VIEWPORT & viewport, SR_Viewport ** out_viewport)
	{
		*out_viewport = new SR_Viewport(viewport);

		m_viewports.emplace_back(*out_viewport);

		return true;
	}

	bool SR_ResourceGenerator::CreateScissorRect(long left, long top, long right, long bottom, SR_Rectangle ** out_scissorRect)
	{
		*out_scissorRect = new SR_Rectangle(left, top, right, bottom);

		m_scissorRects.emplace_back(*out_scissorRect);

		return true;
	}

	bool SR_ResourceGenerator::CreateScissorRect(const D3D11_RECT & scissorRect, SR_Rectangle ** out_scissorRect)
	{
		*out_scissorRect = new SR_Rectangle(scissorRect);

		m_scissorRects.emplace_back(*out_scissorRect);

		return true;
	}

	bool SR_ResourceGenerator::CreateMesh(const std::wstring & filePath, SR_Mesh ** out_mesh)
	{
		*out_mesh = new SR_Mesh();

		SR_RF_BOOL((*out_mesh)->CreateMesh(filePath));

		m_meshes.emplace_back(*out_mesh);

		return true;
	}

	bool SR_ResourceGenerator::CreateVertexShader(const std::wstring & filePath, const std::vector<D3D_SHADER_MACRO>* macros, ID3D11ClassLinkage * classLinkage, const std::vector<D3D11_INPUT_ELEMENT_DESC> & inputElements, SR_VertexShader ** out_vertexShader)
	{
		*out_vertexShader = new SR_VertexShader();

		SR_RF_BOOL((*out_vertexShader)->CreateVertexShader(filePath, classLinkage, macros));
		SR_RF_BOOL((*out_vertexShader)->CreateInputLayout(inputElements));

		m_shaders.emplace_back(*out_vertexShader);

		return true;
	}

	bool SR_ResourceGenerator::CreateHullShader(const std::wstring & filePath, const std::vector<D3D_SHADER_MACRO>* macros, ID3D11ClassLinkage * classLinkage, SR_HullShader ** out_hullShader)
	{
		*out_hullShader = new SR_HullShader();

		SR_RF_BOOL((*out_hullShader)->CreateHullShader(filePath, classLinkage, macros));

		m_shaders.emplace_back(*out_hullShader);

		return true;
	}

	bool SR_ResourceGenerator::CreateDomainShader(const std::wstring & filePath, const std::vector<D3D_SHADER_MACRO>* macros, ID3D11ClassLinkage * classLinkage, SR_DomainShader ** out_domainShader)
	{
		*out_domainShader = new SR_DomainShader();

		SR_RF_BOOL((*out_domainShader)->CreateDomainShader(filePath, classLinkage, macros));

		m_shaders.emplace_back(*out_domainShader);

		return true;
	}

	bool SR_ResourceGenerator::CreateGeometryShader(const std::wstring & filePath, const std::vector<D3D_SHADER_MACRO>* macros, ID3D11ClassLinkage * classLinkage, SR_GeometryShader ** out_geometryShader)
	{
		*out_geometryShader = new SR_GeometryShader();

		SR_RF_BOOL((*out_geometryShader)->CreateGeometryShader(filePath, classLinkage, macros));

		m_shaders.emplace_back(*out_geometryShader);

		return true;
	}

	bool SR_ResourceGenerator::CreatePixelShader(const std::wstring & filePath, const std::vector<D3D_SHADER_MACRO>* macros, ID3D11ClassLinkage * classLinkage, SR_PixelShader ** out_pixelShader)
	{
		*out_pixelShader = new SR_PixelShader();

		SR_RF_BOOL((*out_pixelShader)->CreatePixelShader(filePath, classLinkage, macros));

		m_shaders.emplace_back(*out_pixelShader);

		return true;
	}

	bool SR_ResourceGenerator::CreateComputeShader(const std::wstring & filePath, const std::vector<D3D_SHADER_MACRO>* macros, ID3D11ClassLinkage * classLinkage, SR_ComputeShader ** out_computeShader)
	{
		*out_computeShader = new SR_ComputeShader();

		SR_RF_BOOL((*out_computeShader)->CreateComputeShader(filePath, classLinkage, macros));

		m_shaders.emplace_back(*out_computeShader);

		return true;
	}

	bool SR_ResourceGenerator::CreateBitmap(const std::wstring & filePath, SR_Bitmap ** out_bitmap)
	{
		*out_bitmap = new SR_Bitmap();

		SR_RF_BOOL((*out_bitmap)->CreateBitmap(filePath));

		m_bitmaps.emplace_back(*out_bitmap);

		return true;
	}

	bool SR_ResourceGenerator::CreateColorMatrixEffect(SR_ColorMatrixEffect ** out_colorMatrixEffect)
	{
		*out_colorMatrixEffect = new SR_ColorMatrixEffect();

		SR_RF_BOOL((*out_colorMatrixEffect)->CreateEffect());

		m_effects.emplace_back(*out_colorMatrixEffect);

		return true;
	}

	bool SR_ResourceGenerator::CreateWavSound(const std::wstring & filePath, std::wstring & name, SR_WavSound ** out_wavSound)
	{
		*out_wavSound = new SR_WavSound(name);

		SR_RF_BOOL((*out_wavSound)->CreateSound(filePath));

		m_sounds.emplace_back(*out_wavSound);

		return true;
	}

	bool SR_ResourceGenerator::CreateOggSound(const std::wstring & filePath, std::wstring & name, SR_OggSound ** out_oggSound)
	{
		*out_oggSound = new SR_OggSound(name);

		SR_RF_BOOL((*out_oggSound)->CreateSound(filePath));

		m_sounds.emplace_back(*out_oggSound);

		return true;
	}

	bool SR_ResourceGenerator::CreateVector2(float x, float y, SR_Vector2 ** out_vector2)
	{
		*out_vector2 = new SR_Vector2(x, y);

		m_vector2s.emplace_back(*out_vector2);

		return true;
	}

	bool SR_ResourceGenerator::CreateVector3(float x, float y, float z, SR_Vector3 ** out_vector3)
	{
		*out_vector3 = new SR_Vector3(x, y, z);

		m_vector3s.emplace_back(*out_vector3);

		return true;
	}

	bool SR_ResourceGenerator::CreateVector4(float x, float y, float z, float w, SR_Vector4 ** out_vector4)
	{
		*out_vector4 = new SR_Vector4(x, y, z, w);

		m_vector4s.emplace_back(*out_vector4);

		return true;
	}

}