#pragma once

#include "SR_Generator.h"
#include "SR_RenderDescription.h"
#include "SR_Mesh.h"
#include "SR_VertexShader.h"
#include "SR_HullShader.h"
#include "SR_DomainShader.h"
#include "SR_GeometryShader.h"
#include "SR_PixelShader.h"
#include "SR_ComputeShader.h"
#include "SR_Bitmap.h"
#include "SR_ColorMatrixEffect.h"
#include "SR_WavSound.h"
#include "SR_OggSound.h"
#include "SR_Viewport.h"
#include "SR_Rectangle.h"
#include "SR_Vector2.h"
#include "SR_Vector3.h"
#include "SR_Vector4.h"

namespace SunrinEngine
{

	class SR_ResourceGenerator : public SR_Generator
	{
	public:
		explicit SR_ResourceGenerator() noexcept;
		virtual ~SR_ResourceGenerator() noexcept;

		bool CreateBuffer(const D3D11_BUFFER_DESC * desc, const D3D11_SUBRESOURCE_DATA * initialData, ID3D11Buffer ** out_buffer);
		bool CreateTexture1D(const D3D11_TEXTURE1D_DESC * desc, const D3D11_SUBRESOURCE_DATA * initialData, ID3D11Texture1D ** out_texture1D);
		bool CreateTexture2D(const D3D11_TEXTURE2D_DESC * desc, const D3D11_SUBRESOURCE_DATA * initialData, ID3D11Texture2D ** out_texture2D);
		bool CreateTexture3D(const D3D11_TEXTURE3D_DESC * desc, const D3D11_SUBRESOURCE_DATA * initialData, ID3D11Texture3D ** out_texture3D);
		bool CreateRenderTargetView(const D3D11_RENDER_TARGET_VIEW_DESC * desc, ID3D11Resource * resource, ID3D11RenderTargetView ** out_renderTargetView);
		bool CreateDepthStencilView(const D3D11_DEPTH_STENCIL_VIEW_DESC * desc, ID3D11Resource * resource, ID3D11DepthStencilView ** out_depthStencilView);
		bool CreateShaderResourceView(const D3D11_SHADER_RESOURCE_VIEW_DESC * desc, ID3D11Resource * resource, ID3D11ShaderResourceView ** out_shaderResourceView);
		bool CreateUnorderedAccessView(const D3D11_UNORDERED_ACCESS_VIEW_DESC * desc, ID3D11Resource * resource, ID3D11UnorderedAccessView ** out_unorderedAccessView);
		bool CreateSamplerState(const D3D11_SAMPLER_DESC * desc, ID3D11SamplerState ** out_samplerState);
		bool CreateDepthStencilState(const D3D11_DEPTH_STENCIL_DESC * desc, ID3D11DepthStencilState ** out_depthStencilState);
		bool CreateBlendState(const D3D11_BLEND_DESC * desc, ID3D11BlendState ** out_blendState);
		bool CreateRasterizerState(const D3D11_RASTERIZER_DESC * desc, ID3D11RasterizerState ** out_rasterizerState);
		bool CreateClassLinkage(ID3D11ClassLinkage ** out_classLinkage);
		bool CreateViewport(float topLeftX, float topLeftY, float width, float height, float minDepth, float maxDepth, SR_Viewport **out_viewport);
		bool CreateViewport(const D3D11_VIEWPORT & viewport, SR_Viewport **out_viewport);
		bool CreateScissorRect(long left, long top, long right, long bottom, SR_Rectangle ** out_scissorRect);
		bool CreateScissorRect(const D3D11_RECT & scissorRect, SR_Rectangle ** out_scissorRect);
		bool CreateMesh(const std::wstring & filePath, SR_Mesh ** out_mesh);
		bool CreateVertexShader(const std::wstring & filePath, const std::vector<D3D_SHADER_MACRO> * macros, ID3D11ClassLinkage * classLinkage, const std::vector<D3D11_INPUT_ELEMENT_DESC> & inputElements, SR_VertexShader ** out_vertexShader);
		bool CreateHullShader(const std::wstring & filePath, const std::vector<D3D_SHADER_MACRO> * macros, ID3D11ClassLinkage * classLinkage, SR_HullShader ** out_hullShader);
		bool CreateDomainShader(const std::wstring & filePath, const std::vector<D3D_SHADER_MACRO> * macros, ID3D11ClassLinkage * classLinkage, SR_DomainShader ** out_domainShader);
		bool CreateGeometryShader(const std::wstring & filePath, const std::vector<D3D_SHADER_MACRO> * macros, ID3D11ClassLinkage * classLinkage, SR_GeometryShader ** out_geometryShader);
		bool CreatePixelShader(const std::wstring & filePath, const std::vector<D3D_SHADER_MACRO> * macros, ID3D11ClassLinkage * classLinkage, SR_PixelShader ** out_pixelShader);
		bool CreateComputeShader(const std::wstring& filePath, const std::vector<D3D_SHADER_MACRO> * macros, ID3D11ClassLinkage * classLinkage, SR_ComputeShader ** out_computeShader);
		bool CreateBitmap(const std::wstring & filePath, SR_Bitmap ** out_bitmap);
		bool CreateColorMatrixEffect(SR_ColorMatrixEffect ** out_colorMatrixEffect);
		bool CreateWavSound(const std::wstring & filePath, std::wstring & name, SR_WavSound ** out_wavSound);
		bool CreateOggSound(const std::wstring & filePath, std::wstring & name, SR_OggSound ** out_oggSound);
		bool CreateVector2(float x, float y, SR_Vector2 ** out_vector2);
		bool CreateVector3(float x, float y, float z, SR_Vector3 ** out_vector3);
		bool CreateVector4(float x, float y, float z, float w, SR_Vector4 ** out_vector4);

	private:
		std::vector<IUnknown*> m_interfaces;
		std::vector<std::unique_ptr<SR_Viewport>> m_viewports;
		std::vector<std::unique_ptr<SR_Rectangle>> m_scissorRects;
		std::vector<std::unique_ptr<SR_Mesh>> m_meshes;
		std::vector<std::unique_ptr<SR_CommonShader>> m_shaders;
		std::vector<std::unique_ptr<SR_Bitmap>> m_bitmaps;
		std::vector<std::unique_ptr<SR_Effect>> m_effects;
		std::vector<std::unique_ptr<SR_CommonSound>> m_sounds;
		std::vector<std::unique_ptr<SR_Vector2>> m_vector2s;
		std::vector<std::unique_ptr<SR_Vector3>> m_vector3s;
		std::vector<std::unique_ptr<SR_Vector4>> m_vector4s;

	};

}