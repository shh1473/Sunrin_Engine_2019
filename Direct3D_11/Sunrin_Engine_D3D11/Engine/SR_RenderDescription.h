#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_BufferDesc
	{
	public:
		explicit SR_BufferDesc() noexcept;

		void SetToDefault() noexcept;

		void SetByteWidth(UINT byteWidth) noexcept { m_desc.ByteWidth = byteWidth; }
		void SetUsage(D3D11_USAGE usage) noexcept { m_desc.Usage = usage; }
		void SetBindFlags(UINT flags) noexcept { m_desc.BindFlags = flags; }
		void SetCPUAccessFlags(UINT flags) noexcept { m_desc.CPUAccessFlags = flags; }
		void SetMiscFlags(UINT flags) noexcept { m_desc.MiscFlags = flags; }
		void SetStructuredByteStride(UINT stride) noexcept { m_desc.StructureByteStride = stride; }

	public:
		D3D11_BUFFER_DESC m_desc;

	};

	class SR_Texture1DDesc
	{
	public:
		explicit SR_Texture1DDesc() noexcept;

		void SetToDefault() noexcept;

		void SetWidth(UINT width) noexcept { m_desc.Width = width; }
		void SetMipLevels(UINT levels) noexcept { m_desc.MipLevels = levels; }
		void SetArraySize(UINT size) noexcept { m_desc.ArraySize = size; }
		void SetFormat(DXGI_FORMAT format) noexcept { m_desc.Format = format; }
		void SetUsage(D3D11_USAGE usage) noexcept { m_desc.Usage = usage; }
		void SetBindFlags(UINT flags) noexcept { m_desc.BindFlags = flags; }
		void SetCPUAccessFlags(UINT flags) noexcept { m_desc.CPUAccessFlags = flags; }
		void SetMiscFlags(UINT flags) noexcept { m_desc.MiscFlags = flags; }

	public:
		D3D11_TEXTURE1D_DESC m_desc;

	};

	class SR_Texture2DDesc
	{
	public:
		explicit SR_Texture2DDesc() noexcept;

		void SetToDefault() noexcept;

		void SetWidth(unsigned width) noexcept { m_desc.Width = width; }
		void SetHeight(unsigned height) noexcept { m_desc.Height = height; }
		void SetMipLevels(unsigned levels) noexcept { m_desc.MipLevels = levels; }
		void SetArraySize(unsigned size) noexcept { m_desc.ArraySize = size; }
		void SetFormat(DXGI_FORMAT format) noexcept { m_desc.Format = format; }
		void SetSampleCount(unsigned count) noexcept { m_desc.SampleDesc.Count = count; }
		void SetSampleQuality(unsigned quality) noexcept { m_desc.SampleDesc.Quality = quality; }
		void SetUsage(D3D11_USAGE usage) noexcept { m_desc.Usage = usage; }
		void SetBindFlags(unsigned flags) noexcept { m_desc.BindFlags = flags; }
		void SetCPUAccessFlags(unsigned flags) noexcept { m_desc.CPUAccessFlags = flags; }
		void SetMiscFlags(unsigned flags) noexcept { m_desc.MiscFlags = flags; }

	public:
		D3D11_TEXTURE2D_DESC m_desc;

	};

	class SR_Texture3DDesc
	{
	public:
		explicit SR_Texture3DDesc() noexcept;

		void SetToDefault() noexcept;

		void SetWidth(unsigned width) noexcept { m_desc.Width = width; }
		void SetHeight(unsigned height) noexcept { m_desc.Height = height; }
		void SetDepth(unsigned depth) noexcept { m_desc.Depth = depth; }
		void SetMipLevels(unsigned levels) noexcept { m_desc.MipLevels = levels; }
		void SetFormat(DXGI_FORMAT format) noexcept { m_desc.Format = format; }
		void SetUsage(D3D11_USAGE usage) noexcept { m_desc.Usage = usage; }
		void SetBindFlags(unsigned flags) noexcept { m_desc.BindFlags = flags; }
		void SetCPUAccessFlags(unsigned flags) noexcept { m_desc.CPUAccessFlags = flags; }
		void SetMiscFlags(unsigned flags) noexcept { m_desc.MiscFlags = flags; }

	public:
		D3D11_TEXTURE3D_DESC m_desc;

	};

	class SR_BlendDesc
	{
	public:
		explicit SR_BlendDesc() noexcept;

		void SetToDefault() noexcept;

		void SetAlphaToCoverageEnable(BOOL isEnable) noexcept { m_desc.AlphaToCoverageEnable = isEnable; }
		void SetIndependentBlendEnable(BOOL isEnable) noexcept { m_desc.IndependentBlendEnable = isEnable; }
		void SetBlendEnable(unsigned index, BOOL isEnable) noexcept { m_desc.RenderTarget[index].BlendEnable = isEnable; }
		void SetSrcBlend(unsigned index, D3D11_BLEND blend) noexcept { m_desc.RenderTarget[index].SrcBlend = blend; }
		void SetDestBlend(unsigned index, D3D11_BLEND blend) noexcept { m_desc.RenderTarget[index].DestBlend = blend; }
		void SetBlendOp(unsigned index, D3D11_BLEND_OP blendOp) noexcept { m_desc.RenderTarget[index].BlendOp = blendOp; }
		void SetSrcBlendAlpha(unsigned index, D3D11_BLEND blend) noexcept { m_desc.RenderTarget[index].SrcBlendAlpha = blend; }
		void SetDestBlendAlpha(unsigned index, D3D11_BLEND blend) noexcept { m_desc.RenderTarget[index].DestBlendAlpha = blend; }
		void SetBlendOpAlpha(unsigned index, D3D11_BLEND_OP blendOp) noexcept { m_desc.RenderTarget[index].BlendOpAlpha = blendOp; }
		void SetRenderTargetWriteMask(unsigned index, UINT8 mask) noexcept { m_desc.RenderTarget[index].RenderTargetWriteMask = mask; }

	public:
		D3D11_BLEND_DESC m_desc;

	};

	class SR_DepthStencilDesc
	{
	public:
		explicit SR_DepthStencilDesc() noexcept;

		void SetToDefault() noexcept;

		void SetDepthEnable(BOOL isEnable) noexcept { m_desc.DepthEnable = isEnable; }
		void SetDepthWriteMask(D3D11_DEPTH_WRITE_MASK mask) noexcept { m_desc.DepthWriteMask = mask; }
		void SetDepthFunc(D3D11_COMPARISON_FUNC func) noexcept { m_desc.DepthFunc = func; }
		void SetStencilEnable(BOOL isEnable) noexcept { m_desc.StencilEnable = isEnable; }
		void SetStencilReadMask(UINT8 mask) noexcept { m_desc.StencilReadMask = mask; }
		void SetStencilWriteMask(UINT8 mask) noexcept { m_desc.StencilWriteMask = mask; }
		void SetFrontStencilFailOp(D3D11_STENCIL_OP stencilOp) noexcept { m_desc.FrontFace.StencilFailOp = stencilOp; }
		void SetFrontStencilDepthFailOp(D3D11_STENCIL_OP stencilOp) noexcept { m_desc.FrontFace.StencilDepthFailOp = stencilOp; }
		void SetFrontStencilPassOp(D3D11_STENCIL_OP stencilOp) noexcept { m_desc.FrontFace.StencilPassOp = stencilOp; }
		void SetFrontStencilFunc(D3D11_COMPARISON_FUNC func) noexcept { m_desc.FrontFace.StencilFunc = func; }
		void SetBackStencilFailOp(D3D11_STENCIL_OP stencilOp) noexcept { m_desc.BackFace.StencilFailOp = stencilOp; }
		void SetBackStencilDepthFailOp(D3D11_STENCIL_OP stencilOp) noexcept { m_desc.BackFace.StencilDepthFailOp = stencilOp; }
		void SetBackStencilPassOp(D3D11_STENCIL_OP stencilOp) noexcept { m_desc.BackFace.StencilPassOp = stencilOp; }
		void SetBackStencilFunc(D3D11_COMPARISON_FUNC func) noexcept { m_desc.BackFace.StencilFunc = func; }

	public:
		D3D11_DEPTH_STENCIL_DESC m_desc;

	};

	class SR_RasterizerDesc
	{
	public:
		explicit SR_RasterizerDesc() noexcept;

		void SetToDefault() noexcept;

		void SetFillMode(D3D11_FILL_MODE mode) noexcept { m_desc.FillMode = mode; }
		void SetCullMode(D3D11_CULL_MODE mode) noexcept { m_desc.CullMode = mode; }
		void SetFrontCounterClockwise(BOOL isEnable) noexcept { m_desc.FrontCounterClockwise = isEnable; }
		void SetDepthBias(INT depthBias) noexcept { m_desc.DepthBias = depthBias; }
		void SetDepthBiasClamp(FLOAT clamp) noexcept { m_desc.DepthBiasClamp = clamp; }
		void SetSlopeScaledDepthBias(FLOAT depthBias) noexcept { m_desc.SlopeScaledDepthBias = depthBias; }
		void SetDepthClipEnable(BOOL isEnable) noexcept { m_desc.DepthClipEnable = isEnable; }
		void SetScissorEnable(BOOL isEnable) noexcept { m_desc.ScissorEnable = isEnable; }
		void SetMultisampleEnable(BOOL isEnable) noexcept { m_desc.MultisampleEnable = isEnable; }
		void SetAntialiasedLineEnable(BOOL isEnable) noexcept { m_desc.AntialiasedLineEnable = isEnable; }

	public:
		D3D11_RASTERIZER_DESC m_desc;

	};

	class SR_SamplerDesc
	{
	public:
		explicit SR_SamplerDesc() noexcept;

		void SetToDefault() noexcept;

		void SetFilter(D3D11_FILTER filter) noexcept { m_desc.Filter = filter; }
		void SetAddressU(D3D11_TEXTURE_ADDRESS_MODE mode) noexcept { m_desc.AddressU = mode; }
		void SetAddressV(D3D11_TEXTURE_ADDRESS_MODE mode) noexcept { m_desc.AddressV = mode; }
		void SetAddressW(D3D11_TEXTURE_ADDRESS_MODE mode) noexcept { m_desc.AddressW = mode; }
		void SetMipLODBias(float bias) noexcept { m_desc.MipLODBias = bias; }
		void SetMaxAnisotropy(unsigned anisotropy) noexcept { m_desc.MaxAnisotropy = anisotropy; }
		void SetComparisonFunc(D3D11_COMPARISON_FUNC func) noexcept { m_desc.ComparisonFunc = func; }
		void SetBorderColor(unsigned index, float color) noexcept { m_desc.BorderColor[index] = color; }
		void SetMinLOD(float min) noexcept { m_desc.MinLOD = min; }
		void SetMaxLOD(float max) noexcept { m_desc.MaxLOD = max; }

	public:
		D3D11_SAMPLER_DESC m_desc;

	};

	class SR_DepthStencilViewDesc
	{
	public:
		explicit SR_DepthStencilViewDesc() noexcept;

		void SetToDefault() noexcept;

		void SetFormat(DXGI_FORMAT format) noexcept { m_desc.Format = format; }
		void SetViewDimensions(D3D11_DSV_DIMENSION dimension) noexcept { m_desc.ViewDimension = dimension; }
		void SetFlags(UINT flags) noexcept { m_desc.Flags = flags; }
		void SetTexture1D(D3D11_TEX1D_DSV tex1D) noexcept { m_desc.Texture1D = tex1D; }
		void SetTexture1DArray(D3D11_TEX1D_ARRAY_DSV tex1DArray) noexcept { m_desc.Texture1DArray = tex1DArray; }
		void SetTexture2D(D3D11_TEX2D_DSV tex2D) noexcept { m_desc.Texture2D = tex2D; }
		void SetTexture2DArray(D3D11_TEX2D_ARRAY_DSV tex2DArray) noexcept { m_desc.Texture2DArray = tex2DArray; }
		void SetTexture2DMS(D3D11_TEX2DMS_DSV tex2DMS) noexcept { m_desc.Texture2DMS = tex2DMS; }
		void SetTexture2DMSArray(D3D11_TEX2DMS_ARRAY_DSV tex2DMSArray) noexcept { m_desc.Texture2DMSArray = tex2DMSArray; }

	public:
		D3D11_DEPTH_STENCIL_VIEW_DESC m_desc;

	};

	class SR_RenderTargetViewDesc
	{
	public:
		explicit SR_RenderTargetViewDesc() noexcept;

		void SetToDefault() noexcept;

		void SetFormat(DXGI_FORMAT format) noexcept { m_desc.Format = format; }
		void SetViewDimensions(D3D11_RTV_DIMENSION dimension) noexcept { m_desc.ViewDimension = dimension; }
		void SetBuffer(D3D11_BUFFER_RTV buffer) noexcept { m_desc.Buffer = buffer; }
		void SetTexture1D(D3D11_TEX1D_RTV tex1D) noexcept { m_desc.Texture1D = tex1D; }
		void SetTexture1DArray(D3D11_TEX1D_ARRAY_RTV tex1DArray) noexcept { m_desc.Texture1DArray = tex1DArray; }
		void SetTexture2D(D3D11_TEX2D_RTV tex2D) noexcept { m_desc.Texture2D = tex2D; }
		void SetTexture2DArray(D3D11_TEX2D_ARRAY_RTV tex2DArray) noexcept { m_desc.Texture2DArray = tex2DArray; }
		void SetTexture2DMS(D3D11_TEX2DMS_RTV tex2DMS) noexcept { m_desc.Texture2DMS = tex2DMS; }
		void SetTexture2DMSArray(D3D11_TEX2DMS_ARRAY_RTV tex2DMSArray) noexcept { m_desc.Texture2DMSArray = tex2DMSArray; }
		void SetTexture3D(D3D11_TEX3D_RTV tex3D) noexcept { m_desc.Texture3D = tex3D; }

	public:
		D3D11_RENDER_TARGET_VIEW_DESC m_desc;

	};

	class SR_ShaderResourceViewDesc
	{
	public:
		explicit SR_ShaderResourceViewDesc() noexcept;

		void SetToDefault() noexcept;

		void SetFormat(DXGI_FORMAT format) noexcept { m_desc.Format = format; }
		void SetViewDimensions(D3D11_SRV_DIMENSION dimension) noexcept { m_desc.ViewDimension = dimension; }
		void SetBuffer(D3D11_BUFFER_SRV buffer) noexcept { m_desc.Buffer = buffer; }
		void SetBufferEx(D3D11_BUFFEREX_SRV bufferEx) noexcept { m_desc.BufferEx = bufferEx; }
		void SetTexture1D(D3D11_TEX1D_SRV tex1D) noexcept { m_desc.Texture1D = tex1D; }
		void SetTexture1DArray(D3D11_TEX1D_ARRAY_SRV tex1DArray) noexcept { m_desc.Texture1DArray = tex1DArray; }
		void SetTexture2D(D3D11_TEX2D_SRV tex2D) noexcept { m_desc.Texture2D = tex2D; }
		void SetTexture2DArray(D3D11_TEX2D_ARRAY_SRV tex2DArray) noexcept { m_desc.Texture2DArray = tex2DArray; }
		void SetTexture2DMS(D3D11_TEX2DMS_SRV tex2DMS) noexcept { m_desc.Texture2DMS = tex2DMS; }
		void SetTexture2DMSArray(D3D11_TEX2DMS_ARRAY_SRV tex2DMSArray) noexcept { m_desc.Texture2DMSArray = tex2DMSArray; }
		void SetTexture3D(D3D11_TEX3D_SRV tex3D) noexcept { m_desc.Texture3D = tex3D; }
		void SetTexture3D(D3D11_TEXCUBE_SRV texCube) noexcept { m_desc.TextureCube = texCube; }
		void SetTexture3D(D3D11_TEXCUBE_ARRAY_SRV texCubeArray) noexcept { m_desc.TextureCubeArray = texCubeArray; }

	public:
		D3D11_SHADER_RESOURCE_VIEW_DESC m_desc;

	};

	class SR_UnorderedAccessViewDesc
	{
	public:
		explicit SR_UnorderedAccessViewDesc() noexcept;

		void SetToDefault() noexcept;

		void SetFormat(DXGI_FORMAT format) noexcept { m_desc.Format = format; }
		void SetViewDimensions(D3D11_UAV_DIMENSION dimension) noexcept { m_desc.ViewDimension = dimension; }
		void SetBuffer(D3D11_BUFFER_UAV buffer) noexcept { m_desc.Buffer = buffer; }
		void SetTexture1D(D3D11_TEX1D_UAV tex1D) noexcept { m_desc.Texture1D = tex1D; }
		void SetTexture1DArray(D3D11_TEX1D_ARRAY_UAV tex1DArray) noexcept { m_desc.Texture1DArray = tex1DArray; }
		void SetTexture2D(D3D11_TEX2D_UAV tex2D) noexcept { m_desc.Texture2D = tex2D; }
		void SetTexture2DArray(D3D11_TEX2D_ARRAY_UAV tex2DArray) noexcept { m_desc.Texture2DArray = tex2DArray; }
		void SetTexture3D(D3D11_TEX3D_UAV tex3D) noexcept { m_desc.Texture3D = tex3D; }

	public:
		D3D11_UNORDERED_ACCESS_VIEW_DESC m_desc;

	};

}