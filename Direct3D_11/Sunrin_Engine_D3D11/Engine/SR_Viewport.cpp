#include "SR_PCH.h"

#include "SR_Viewport.h"

namespace SunrinEngine
{

	SR_Viewport::SR_Viewport() noexcept :
		m_viewport{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f }
	{

	}

	SR_Viewport::SR_Viewport(float topLeftX, float topLeftY, float width, float height, float minDepth, float maxDepth) noexcept :
		m_viewport{ std::move(topLeftX), std::move(topLeftY), std::move(width), std::move(height), std::move(minDepth), std::move(maxDepth) }
	{

	}

	SR_Viewport::SR_Viewport(const SR_Viewport & viewport) noexcept :
		m_viewport{ viewport.m_viewport }
	{

	}

	SR_Viewport::SR_Viewport(SR_Viewport && viewport) noexcept :
		m_viewport{ std::move(viewport.m_viewport) }
	{

	}

	SR_Viewport::SR_Viewport(const D3D11_VIEWPORT & viewport) noexcept :
		m_viewport { viewport }
	{

	}

	SR_Viewport::SR_Viewport(D3D11_VIEWPORT && viewport) noexcept :
		m_viewport{ std::move(viewport) }
	{

	}

	bool SR_Viewport::operator==(const SR_Viewport & viewport) const noexcept
	{
		return
			(m_viewport.TopLeftX == viewport.m_viewport.TopLeftX) &&
			(m_viewport.TopLeftY== viewport.m_viewport.TopLeftY) &&
			(m_viewport.Width == viewport.m_viewport.Width) &&
			(m_viewport.Height == viewport.m_viewport.Height) &&
			(m_viewport.MinDepth == viewport.m_viewport.MinDepth) &&
			(m_viewport.MaxDepth == viewport.m_viewport.MaxDepth);
	}

	bool SR_Viewport::operator!=(const SR_Viewport & viewport) const noexcept
	{
		return
			(m_viewport.TopLeftX != viewport.m_viewport.TopLeftX) ||
			(m_viewport.TopLeftY != viewport.m_viewport.TopLeftY) ||
			(m_viewport.Width != viewport.m_viewport.Width) ||
			(m_viewport.Height != viewport.m_viewport.Height) ||
			(m_viewport.MinDepth != viewport.m_viewport.MinDepth) ||
			(m_viewport.MaxDepth != viewport.m_viewport.MaxDepth);
	}

	SR_Viewport & SR_Viewport::operator=(const SR_Viewport & viewport) noexcept
	{
		m_viewport = viewport.m_viewport;

		return *this;
	}

	SR_Viewport & SR_Viewport::operator=(SR_Viewport && viewport) noexcept
	{
		m_viewport = std::move(viewport.m_viewport);

		return *this;
	}

	float SR_Viewport::AspectRatio(const SR_Viewport & viewport) noexcept
	{
		if (viewport.m_viewport.Width == 0.0f || viewport.m_viewport.Height == 0.0f)
		{
			return 0.0f;
		}
		else
		{
			return viewport.m_viewport.Width / viewport.m_viewport.Height;
		}
	}

	const DirectX::XMFLOAT3 SR_Viewport::ProjectPosition(const SR_Viewport & viewport, const DirectX::XMFLOAT3 & position, const DirectX::XMFLOAT4X4 & worldMatrix, DirectX::XMFLOAT4X4 & viewMatrix, DirectX::XMFLOAT4X4 & projMatrix)
	{
		DirectX::XMFLOAT3 pos;

		DirectX::XMStoreFloat3(
			&pos,
			std::move(DirectX::XMVector3Project(
				std::move(DirectX::XMLoadFloat3(&position)),
				viewport.m_viewport.TopLeftX,
				viewport.m_viewport.TopLeftY,
				viewport.m_viewport.Width,
				viewport.m_viewport.Height,
				viewport.m_viewport.MinDepth,
				viewport.m_viewport.MaxDepth,
				std::move(DirectX::XMLoadFloat4x4(&projMatrix)),
				std::move(DirectX::XMLoadFloat4x4(&viewMatrix)),
				std::move(DirectX::XMLoadFloat4x4(&worldMatrix)))));

		return std::move(pos);
	}

	const DirectX::XMFLOAT3 SR_Viewport::UnprojectPosition(const SR_Viewport & viewport, const DirectX::XMFLOAT3 & position, const DirectX::XMFLOAT4X4 & worldMatrix, DirectX::XMFLOAT4X4 & viewMatrix, DirectX::XMFLOAT4X4 & projMatrix)
	{
		DirectX::XMFLOAT3 pos;

		DirectX::XMStoreFloat3(
			&pos,
			std::move(DirectX::XMVector3Unproject(
				std::move(DirectX::XMLoadFloat3(&position)),
				viewport.m_viewport.TopLeftX,
				viewport.m_viewport.TopLeftY,
				viewport.m_viewport.Width,
				viewport.m_viewport.Height,
				viewport.m_viewport.MinDepth,
				viewport.m_viewport.MaxDepth,
				std::move(DirectX::XMLoadFloat4x4(&projMatrix)),
				std::move(DirectX::XMLoadFloat4x4(&viewMatrix)),
				std::move(DirectX::XMLoadFloat4x4(&worldMatrix)))));

		return std::move(pos);
	}

}