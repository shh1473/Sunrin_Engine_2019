#include "SR_PCH.h"
#include "SR_Ray.h"

namespace SunrinEngine
{

	constexpr SR_Ray::SR_Ray() noexcept :
		m_position	{ 0.0f, 0.0f, 0.0f },
		m_direction	{ 0.0f, 0.0f, 0.0f }
	{

	}

	constexpr SR_Ray::SR_Ray(
		float x, float y, float z,
		float dx, float dy, float dz) noexcept :
		m_position	{ x, y, z },
		m_direction	{ dx, dy, dz }
	{

	}

	constexpr SR_Ray::SR_Ray(
		const DirectX::XMFLOAT3 & position,
		const DirectX::XMFLOAT3 & direction) noexcept :
		m_position	{ position },
		m_direction	{ direction }
	{

	}

	constexpr SR_Ray::SR_Ray(const SR_Ray & ray) noexcept :
		m_position	{ ray.m_position },
		m_direction	{ ray.m_direction }
	{

	}

	constexpr SR_Ray::SR_Ray(SR_Ray && ray) noexcept :
		m_position	{ std::move(ray.m_position) },
		m_direction	{ std::move(ray.m_direction) }
	{

	}

	SR_Ray::~SR_Ray() noexcept
	{

	}

	bool SR_Ray::operator==(const SR_Ray & ray) const
	{
		return
			DirectX::XMVector4Equal(
				std::move(DirectX::XMLoadFloat3(&m_position)),
				std::move(DirectX::XMLoadFloat3(&ray.m_position))) &&
			DirectX::XMVector4Equal(
				std::move(DirectX::XMLoadFloat3(&m_direction)),
				std::move(DirectX::XMLoadFloat3(&ray.m_direction)));
	}

	bool SR_Ray::operator!=(const SR_Ray & ray) const
	{
		return
			DirectX::XMVector4NotEqual(
				std::move(DirectX::XMLoadFloat3(&m_position)),
				std::move(DirectX::XMLoadFloat3(&ray.m_position))) ||
			DirectX::XMVector4NotEqual(
				std::move(DirectX::XMLoadFloat3(&m_direction)),
				std::move(DirectX::XMLoadFloat3(&ray.m_direction)));
	}

	SR_Ray & SR_Ray::operator=(const SR_Ray & ray) noexcept
	{
		m_position = ray.m_position;
		m_direction = ray.m_direction;

		return *this;
	}

	SR_Ray & SR_Ray::operator=(SR_Ray && ray) noexcept
	{
		m_position = std::move(ray.m_position);
		m_direction = std::move(ray.m_direction);

		return *this;
	}

	bool SR_Ray::Intersect(const SR_Ray & ray, const DirectX::BoundingSphere & sphere, float * distance)
	{
		return sphere.Intersects(
			std::move(DirectX::XMLoadFloat3(&ray.m_position)),
			std::move(DirectX::XMLoadFloat3(&ray.m_direction)),
			*distance);
	}

	bool SR_Ray::Intersect(const SR_Ray & ray, const DirectX::BoundingBox & box, float * distance)
	{
		return box.Intersects(
			std::move(DirectX::XMLoadFloat3(&ray.m_position)),
			std::move(DirectX::XMLoadFloat3(&ray.m_direction)),
			*distance);
	}

	bool SR_Ray::Intersect(const SR_Ray & ray, const DirectX::XMFLOAT3 & vertex_1, const DirectX::XMFLOAT3 & vertex_2, const DirectX::XMFLOAT3 & vertex_3, float * distance)
	{
		return DirectX::TriangleTests::Intersects(
			std::move(DirectX::XMLoadFloat3(&ray.m_position)),
			std::move(DirectX::XMLoadFloat3(&ray.m_direction)),
			std::move(DirectX::XMLoadFloat3(&vertex_1)),
			std::move(DirectX::XMLoadFloat3(&vertex_2)),
			std::move(DirectX::XMLoadFloat3(&vertex_3)),
			*distance);
	}

	bool SR_Ray::Intersect(const SR_Ray & ray, const DirectX::XMFLOAT4 & plane, float * distance)
	{
		DirectX::XMVECTOR p{ std::move(XMLoadFloat4(&plane)) };
		DirectX::XMVECTOR nd{ DirectX::XMPlaneDotNormal(
			p,
			std::move(DirectX::XMLoadFloat3(&ray.m_direction))) };

		if (DirectX::XMVector3LessOrEqual(
			std::move(DirectX::XMVectorAbs(nd)),
			DirectX::g_RayEpsilon))
		{
			*distance = 0.0f;

			return false;
		}
		else
		{
			float dist{ -DirectX::XMVectorGetX(
				std::move(DirectX::XMVectorDivide(
					std::move(DirectX::XMVectorAdd(
						std::move(DirectX::XMPlaneDotNormal(
							p,
							std::move(DirectX::XMLoadFloat3(&ray.m_position)))),
						std::move(DirectX::XMVectorSplatW(p)))), nd))) };

			if (dist > 0.0f)
			{
				*distance = dist;

				return true;
			}
			else
			{
				*distance = 0.0f;

				return false;
			}
		}
	}

}