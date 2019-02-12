#include "SR_PCH.h"

#include "SR_RenderDescription.h"

namespace SunrinEngine
{

	SR_BufferDesc::SR_BufferDesc() noexcept
	{
		SetToDefault();
	}

	void SR_BufferDesc::SetToDefault() noexcept
	{
		ZeroMemory(&m_desc, sizeof(D3D11_BUFFER_DESC));
	}

	SR_Texture1DDesc::SR_Texture1DDesc() noexcept
	{
		SetToDefault();
	}

	void SR_Texture1DDesc::SetToDefault() noexcept
	{
		ZeroMemory(&m_desc, sizeof(D3D11_TEXTURE1D_DESC));

		m_desc.Width = 1;
		m_desc.MipLevels = 1;
		m_desc.ArraySize = 1;
		m_desc.Format = DXGI_FORMAT_UNKNOWN;
		m_desc.Usage = D3D11_USAGE_DEFAULT;
		m_desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		m_desc.CPUAccessFlags = NULL;
		m_desc.MiscFlags = NULL;
	}

	SR_Texture2DDesc::SR_Texture2DDesc() noexcept
	{
		SetToDefault();
	}

	void SR_Texture2DDesc::SetToDefault() noexcept
	{
		ZeroMemory(&m_desc, sizeof(D3D11_TEXTURE2D_DESC));

		m_desc.Width = 1;
		m_desc.Height = 1;
		m_desc.MipLevels = 1;
		m_desc.ArraySize = 1;
		m_desc.Format = DXGI_FORMAT_UNKNOWN;
		m_desc.SampleDesc.Count = 1;
		m_desc.SampleDesc.Quality = 0;
		m_desc.Usage = D3D11_USAGE_DEFAULT;
		m_desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		m_desc.CPUAccessFlags = NULL;
		m_desc.MiscFlags = NULL;
	}

	SR_Texture3DDesc::SR_Texture3DDesc() noexcept
	{
		SetToDefault();
	}

	void SR_Texture3DDesc::SetToDefault() noexcept
	{
		ZeroMemory(&m_desc, sizeof(D3D11_TEXTURE3D_DESC));

		m_desc.Width = 1;
		m_desc.Height = 1;
		m_desc.Depth = 1;
		m_desc.MipLevels = 1;
		m_desc.Format = DXGI_FORMAT_UNKNOWN;
		m_desc.Usage = D3D11_USAGE_DEFAULT;
		m_desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		m_desc.CPUAccessFlags = NULL;
		m_desc.MiscFlags = NULL;
	}

	SR_BlendDesc::SR_BlendDesc() noexcept
	{
		SetToDefault();
	}

	void SR_BlendDesc::SetToDefault() noexcept
	{
		ZeroMemory(&m_desc, sizeof(D3D11_BLEND_DESC));

		for (unsigned i{ 0 }; i < 8; ++i)
		{
			m_desc.RenderTarget[i].BlendEnable = FALSE;
			m_desc.RenderTarget[i].SrcBlend = D3D11_BLEND_ONE;
			m_desc.RenderTarget[i].DestBlend = D3D11_BLEND_ZERO;
			m_desc.RenderTarget[i].BlendOp = D3D11_BLEND_OP_ADD;
			m_desc.RenderTarget[i].SrcBlendAlpha = D3D11_BLEND_ONE;
			m_desc.RenderTarget[i].DestBlendAlpha = D3D11_BLEND_ZERO;
			m_desc.RenderTarget[i].BlendOpAlpha = D3D11_BLEND_OP_ADD;
			m_desc.RenderTarget[i].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		}
	}

	SR_DepthStencilDesc::SR_DepthStencilDesc() noexcept
	{
		SetToDefault();
	}

	void SR_DepthStencilDesc::SetToDefault() noexcept
	{
		ZeroMemory(&m_desc, sizeof(D3D11_DEPTH_STENCIL_DESC));

		m_desc.DepthEnable = TRUE;
		m_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		m_desc.DepthFunc = D3D11_COMPARISON_LESS;
		m_desc.StencilEnable = FALSE;
		m_desc.StencilReadMask = D3D11_DEFAULT_STENCIL_READ_MASK;
		m_desc.StencilWriteMask = D3D11_DEFAULT_STENCIL_WRITE_MASK;
		m_desc.FrontFace.StencilFunc = D3D11_COMPARISON_NEVER;
		m_desc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		m_desc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		m_desc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
		m_desc.BackFace.StencilFunc = D3D11_COMPARISON_NEVER;
		m_desc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		m_desc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		m_desc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
	}

	SR_RasterizerDesc::SR_RasterizerDesc() noexcept
	{
		SetToDefault();
	}

	void SR_RasterizerDesc::SetToDefault() noexcept
	{
		ZeroMemory(&m_desc, sizeof(D3D11_RASTERIZER_DESC));

		m_desc.FillMode = D3D11_FILL_SOLID;
		m_desc.CullMode = D3D11_CULL_BACK;
		m_desc.DepthClipEnable = TRUE;
	}

	SR_SamplerDesc::SR_SamplerDesc() noexcept
	{
		SetToDefault();
	}

	void SR_SamplerDesc::SetToDefault() noexcept
	{
		ZeroMemory(&m_desc, sizeof(D3D11_SAMPLER_DESC));

		m_desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
		m_desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		m_desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		m_desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		m_desc.MaxAnisotropy = 1;
		m_desc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
		m_desc.MaxLOD = D3D11_FLOAT32_MAX;
	}

	SR_DepthStencilViewDesc::SR_DepthStencilViewDesc() noexcept
	{
		SetToDefault();
	}

	void SR_DepthStencilViewDesc::SetToDefault() noexcept
	{
		ZeroMemory(&m_desc, sizeof(D3D11_DEPTH_STENCIL_VIEW_DESC));

		m_desc.Format = DXGI_FORMAT_UNKNOWN;
		m_desc.ViewDimension = D3D11_DSV_DIMENSION_UNKNOWN;
		m_desc.Flags = NULL;
	}

	SR_RenderTargetViewDesc::SR_RenderTargetViewDesc() noexcept
	{
		SetToDefault();
	}

	void SR_RenderTargetViewDesc::SetToDefault() noexcept
	{
		ZeroMemory(&m_desc, sizeof(D3D11_RENDER_TARGET_VIEW_DESC));

		m_desc.Format = DXGI_FORMAT_UNKNOWN;
		m_desc.ViewDimension = D3D11_RTV_DIMENSION_UNKNOWN;
	}

	SR_ShaderResourceViewDesc::SR_ShaderResourceViewDesc() noexcept
	{
		SetToDefault();
	}

	void SR_ShaderResourceViewDesc::SetToDefault() noexcept
	{
		ZeroMemory(&m_desc, sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));

		m_desc.Format = DXGI_FORMAT_UNKNOWN;
		m_desc.ViewDimension = D3D11_SRV_DIMENSION_UNKNOWN;
	}

	SR_UnorderedAccessViewDesc::SR_UnorderedAccessViewDesc() noexcept
	{
		SetToDefault();
	}

	void SR_UnorderedAccessViewDesc::SetToDefault() noexcept
	{
		ZeroMemory(&m_desc, sizeof(D3D11_UNORDERED_ACCESS_VIEW_DESC));

		m_desc.Format = DXGI_FORMAT_UNKNOWN;
		m_desc.ViewDimension = D3D11_UAV_DIMENSION_UNKNOWN;
	}

}