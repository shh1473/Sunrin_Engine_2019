#include "SR_PCH.h"

#include "SR_Plane.h"

namespace SunrinEngine
{

	SR_Plane::SR_Plane() noexcept :
		m_plane{ 0.0f, 1.0f, 0.0f, 0.0f }
	{

	}

	SR_Plane::SR_Plane(float x, float y, float z, float w) noexcept :
		m_plane{ x, y, z, w }
	{

	}

	SR_Plane::SR_Plane(const DirectX::XMFLOAT3 & normal, float d) noexcept :
		m_plane{ normal.x, normal.y, normal.z, d }
	{

	}

	SR_Plane::SR_Plane(const DirectX::XMFLOAT3 & point_1, const DirectX::XMFLOAT3 & point_2, const DirectX::XMFLOAT3 & point_3) noexcept :
		m_plane{ 0.0f, 1.0f, 0.0f, 0.0f }
	{
		DirectX::XMStoreFloat4(
			&m_plane,
			std::move(DirectX::XMPlaneFromPoints(
				std::move(DirectX::XMLoadFloat3(&point_1)),
				std::move(DirectX::XMLoadFloat3(&point_2)),
				std::move(DirectX::XMLoadFloat3(&point_3)))));
	}

	SR_Plane::SR_Plane(const DirectX::XMFLOAT3 & point, const DirectX::XMFLOAT3 & normal) noexcept :
		m_plane{ 0.0f, 1.0f, 0.0f, 0.0f }
	{
		DirectX::XMStoreFloat4(
			&m_plane,
			std::move(DirectX::XMPlaneFromPointNormal(
				std::move(DirectX::XMLoadFloat3(&point)),
				std::move(DirectX::XMLoadFloat3(&normal)))));
	}

	SR_Plane::SR_Plane(const SR_Plane & plane) noexcept :
		m_plane{ plane.m_plane }
	{

	}

	SR_Plane::SR_Plane(SR_Plane && plane) noexcept :
		m_plane{ std::move(plane.m_plane) }
	{

	}

	SR_Plane::SR_Plane(const DirectX::XMFLOAT4 & float4) noexcept :
		m_plane{ float4 }
	{

	}

	SR_Plane::SR_Plane(DirectX::XMFLOAT4 && float4) noexcept :
		m_plane{ std::move(float4) }
	{

	}

	bool SR_Plane::operator==(const SR_Plane & plane) const
	{
		return DirectX::XMVector4Equal(
			std::move(DirectX::XMLoadFloat4(&m_plane)),
			std::move(DirectX::XMLoadFloat4(&plane.m_plane)));
	}

	bool SR_Plane::operator!=(const SR_Plane & plane) const
	{
		return DirectX::XMVector4NotEqual(
			std::move(DirectX::XMLoadFloat4(&m_plane)),
			std::move(DirectX::XMLoadFloat4(&plane.m_plane)));
	}

	SR_Plane & SR_Plane::operator=(const SR_Plane & plane) noexcept
	{
		m_plane = plane.m_plane;

		return *this;
	}

	SR_Plane & SR_Plane::operator=(SR_Plane && plane) noexcept
	{
		m_plane = std::move(plane.m_plane);

		return *this;
	}

	float SR_Plane::Dot(const SR_Plane & plane_1, const SR_Plane & plane_2)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMPlaneDot(
				std::move(DirectX::XMLoadFloat4(&plane_1.m_plane)),
				std::move(DirectX::XMLoadFloat4(&plane_2.m_plane)))));
	}

	float SR_Plane::DotCoord(const SR_Plane & plane, const DirectX::XMFLOAT3 & coord)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMPlaneDotCoord(
				std::move(DirectX::XMLoadFloat4(&plane.m_plane)),
				std::move(DirectX::XMLoadFloat3(&coord)))));
	}

	float SR_Plane::DotNormal(const SR_Plane & plane, const DirectX::XMFLOAT3 & normal)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMPlaneDotNormal(
				std::move(DirectX::XMLoadFloat4(&plane.m_plane)),
				std::move(DirectX::XMLoadFloat3(&normal)))));
	}

	const SR_Plane SR_Plane::Normalize(const SR_Plane & plane)
	{
		SR_Plane pla;

		DirectX::XMStoreFloat4(
			&pla.m_plane,
			std::move(DirectX::XMPlaneNormalize(
				std::move(DirectX::XMLoadFloat4(&plane.m_plane)))));

		return std::move(pla);
	}

	const SR_Plane SR_Plane::Transform(const SR_Plane & plane, const DirectX::XMFLOAT4X4 & float4x4)
	{
		SR_Plane pla;

		DirectX::XMStoreFloat4(
			&pla.m_plane,
			std::move(DirectX::XMPlaneTransform(
				std::move(DirectX::XMLoadFloat4(&plane.m_plane)),
				std::move(DirectX::XMLoadFloat4x4(&float4x4)))));

		return std::move(pla);
	}

	const SR_Plane SR_Plane::Transform(const SR_Plane & plane, const DirectX::XMFLOAT4 & float4)
	{
		DirectX::XMVECTOR p{ std::move(DirectX::XMLoadFloat4(&plane.m_plane)) };

		SR_Plane pla;

		DirectX::XMStoreFloat4(
			&pla.m_plane,
			std::move(DirectX::XMVectorSelect(
				p,
				std::move(DirectX::XMVector3Rotate(
					p,
					std::move(DirectX::XMLoadFloat4(&float4)))),
				DirectX::g_XMSelect1110)));

		return std::move(pla);
	}

}