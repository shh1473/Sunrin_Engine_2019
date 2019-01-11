#include "SR_PCH.h"
#include "SR_Vector3.h"

namespace SunrinEngine
{

	const SR_Vector3 SR_Vector3::M_Zero		{  0.0f,  0.0f,  0.0f };
	const SR_Vector3 SR_Vector3::M_One		{  1.0f,  1.0f,  1.0f };
	const SR_Vector3 SR_Vector3::M_UnitX	{  1.0f,  0.0f,  0.0f };
	const SR_Vector3 SR_Vector3::M_UnitY	{  0.0f,  1.0f,  0.0f };
	const SR_Vector3 SR_Vector3::M_UnitZ	{  0.0f,  0.0f,  1.0f };
	const SR_Vector3 SR_Vector3::M_Up		{  0.0f,  1.0f,  0.0f };
	const SR_Vector3 SR_Vector3::M_Down		{  0.0f, -1.0f,  0.0f };
	const SR_Vector3 SR_Vector3::M_Right	{  1.0f,  0.0f,  0.0f };
	const SR_Vector3 SR_Vector3::M_Left		{ -1.0f,  0.0f,  0.0f };
	const SR_Vector3 SR_Vector3::M_Forward	{  0.0f,  1.0f,  1.0f };
	const SR_Vector3 SR_Vector3::M_Backward	{  0.0f,  1.0f, -1.0f };

	constexpr SR_Vector3::SR_Vector3() noexcept :
		m_float3{ 0.0f, 0.0f, 0.0f }
	{

	}

	constexpr SR_Vector3::SR_Vector3(float x, float y, float z) noexcept :
		m_float3{ x, y, z }
	{

	}

	constexpr SR_Vector3::SR_Vector3(const SR_Vector3 & vector3) noexcept :
		m_float3{ vector3.m_float3 }
	{

	}

	constexpr SR_Vector3::SR_Vector3(SR_Vector3 && vector3) noexcept :
		m_float3{ std::move(vector3.m_float3) }
	{

	}

	constexpr SR_Vector3::SR_Vector3(const DirectX::XMFLOAT3 & vector3) noexcept :
		m_float3{ vector3 }
	{

	}

	constexpr SR_Vector3::SR_Vector3(DirectX::XMFLOAT3 && vector3) noexcept :
		m_float3{ std::move(vector3) }
	{

	}

	SR_Vector3::~SR_Vector3() noexcept
	{

	}

	bool SR_Vector3::operator==(const SR_Vector3 & vector3) const
	{
		return DirectX::XMVector3Equal(
			std::move(DirectX::XMLoadFloat3(&m_float3)),
			std::move(DirectX::XMLoadFloat3(&vector3.m_float3)));
	}

	bool SR_Vector3::operator!=(const SR_Vector3 & vector3) const
	{
		return DirectX::XMVector3NotEqual(
			std::move(DirectX::XMLoadFloat3(&m_float3)),
			std::move(DirectX::XMLoadFloat3(&vector3.m_float3)));
	}

	SR_Vector3 & SR_Vector3::operator=(const SR_Vector3 & vector3) noexcept
	{
		m_float3 = vector3.m_float3;

		return *this;
	}

	SR_Vector3 & SR_Vector3::operator=(SR_Vector3 && vector3) noexcept
	{
		m_float3 = std::move(vector3.m_float3);

		return *this;
	}

	SR_Vector3 & SR_Vector3::operator+=(const SR_Vector3 & vector3)
	{
		DirectX::XMStoreFloat3(
			&m_float3,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)))));

		return *this;
	}

	SR_Vector3 & SR_Vector3::operator+=(float scalar)
	{
		DirectX::XMStoreFloat3(
			&m_float3,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				std::move(DirectX::XMLoadFloat3(&DirectX::XMFLOAT3(scalar, scalar, scalar))))));

		return *this;
	}

	SR_Vector3 & SR_Vector3::operator-=(const SR_Vector3 & vector3)
	{
		DirectX::XMStoreFloat3(
			&m_float3,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)))));

		return *this;
	}

	SR_Vector3 & SR_Vector3::operator-=(float scalar)
	{
		DirectX::XMStoreFloat3(
			&m_float3,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				std::move(DirectX::XMLoadFloat3(&DirectX::XMFLOAT3(scalar, scalar, scalar))))));

		return *this;
	}

	SR_Vector3 & SR_Vector3::operator*=(const SR_Vector3 & vector3)
	{
		DirectX::XMStoreFloat3(
			&m_float3,
			std::move(DirectX::XMVectorMultiply(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)))));

		return *this;
	}

	SR_Vector3 & SR_Vector3::operator*=(float scalar)
	{
		DirectX::XMStoreFloat3(
			&m_float3,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				scalar)));

		return *this;
	}

	SR_Vector3 & SR_Vector3::operator/=(const SR_Vector3 & vector3)
	{
		DirectX::XMStoreFloat3(
			&m_float3,
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)))));

		return *this;
	}

	SR_Vector3 & SR_Vector3::operator/=(float scalar)
	{
		DirectX::XMStoreFloat3(
			&m_float3,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				1.0f / scalar)));

		return *this;
	}

	const SR_Vector3 SR_Vector3::operator-() const
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorNegate(
				std::move(DirectX::XMLoadFloat3(&m_float3)))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::operator+(const SR_Vector3 & vector3) const
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::operator+(float scalar) const
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				std::move(DirectX::XMLoadFloat3(&DirectX::XMFLOAT3(scalar, scalar, scalar))))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::operator-(const SR_Vector3 & vector3) const
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::operator-(float scalar) const
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				std::move(DirectX::XMLoadFloat3(&DirectX::XMFLOAT3(scalar, scalar, scalar))))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::operator*(const SR_Vector3 & vector3) const
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorMultiply(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::operator*(float scalar) const
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				scalar)));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::operator/(const SR_Vector3 & vector3) const
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::operator/(float scalar) const
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat3(&m_float3)),
				1.0f / scalar)));

		return std::move(vec3);
	}

	bool SR_Vector3::InBounds(const SR_Vector3 & vector3, const SR_Vector3 & bounds)
	{
		return DirectX::XMVector3InBounds(
			std::move(DirectX::XMLoadFloat3(&vector3.m_float3)),
			std::move(DirectX::XMLoadFloat3(&bounds.m_float3)));
	}

	float SR_Vector3::Length(const SR_Vector3 & vector3)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector3Length(
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)))));
	}

	float SR_Vector3::LengthSquared(const SR_Vector3 & vector3)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector3LengthSq(
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)))));
	}

	float SR_Vector3::Distance(const SR_Vector3 & position_1, const SR_Vector3 & position_2)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector3Length(
				std::move(DirectX::XMVectorSubtract(
					std::move(DirectX::XMLoadFloat3(&position_2.m_float3)),
					std::move(DirectX::XMLoadFloat3(&position_1.m_float3)))))));
	}

	float SR_Vector3::DistanceSquared(const SR_Vector3 & position_1, const SR_Vector3 & position_2)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector3LengthSq(
				std::move(DirectX::XMVectorSubtract(
					std::move(DirectX::XMLoadFloat3(&position_2.m_float3)),
					std::move(DirectX::XMLoadFloat3(&position_1.m_float3)))))));
	}

	float SR_Vector3::Dot(const SR_Vector3 & vector3_1, const SR_Vector3 & vector3_2)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector3Dot(
				std::move(DirectX::XMLoadFloat3(&vector3_1.m_float3)),
				std::move(DirectX::XMLoadFloat3(&vector3_2.m_float3)))));
	}

	const SR_Vector3 SR_Vector3::Cross(const SR_Vector3 & vector3_1, const SR_Vector3 & vector3_2)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVector3Cross(
				std::move(DirectX::XMLoadFloat3(&vector3_1.m_float3)),
				std::move(DirectX::XMLoadFloat3(&vector3_2.m_float3)))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::Normalize(const SR_Vector3 & vector3)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVector3Normalize(
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::Clamp(const SR_Vector3 & vector3, const SR_Vector3 & min, const SR_Vector3 & max)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorClamp(
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)),
				std::move(DirectX::XMLoadFloat3(&min.m_float3)),
				std::move(DirectX::XMLoadFloat3(&max.m_float3)))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::Min(const SR_Vector3 & vector3_1, const SR_Vector3 & vector3_2)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorMin(
				std::move(DirectX::XMLoadFloat3(&vector3_1.m_float3)),
				std::move(DirectX::XMLoadFloat3(&vector3_2.m_float3)))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::Max(const SR_Vector3 & vector3_1, const SR_Vector3 & vector3_2)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorMax(
				std::move(DirectX::XMLoadFloat3(&vector3_1.m_float3)),
				std::move(DirectX::XMLoadFloat3(&vector3_2.m_float3)))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::Lerp(const SR_Vector3 & position_1, const SR_Vector3 & position_2, float t)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorLerp(
				std::move(DirectX::XMLoadFloat3(&position_1.m_float3)),
				std::move(DirectX::XMLoadFloat3(&position_2.m_float3)),
				t)));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::SmoothStep(const SR_Vector3 & position_1, const SR_Vector3 & position_2, float t)
	{
		t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t);
		t = t * t * (3.0f - (2.0f * t));

		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorLerp(
				std::move(DirectX::XMLoadFloat3(&position_1.m_float3)),
				std::move(DirectX::XMLoadFloat3(&position_2.m_float3)),
				t)));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::BaryCentric(const SR_Vector3 & position_1, const SR_Vector3 & position_2, const SR_Vector3 & position_3, float f, float g)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorBaryCentric(
				std::move(DirectX::XMLoadFloat3(&position_1.m_float3)),
				std::move(DirectX::XMLoadFloat3(&position_2.m_float3)),
				std::move(DirectX::XMLoadFloat3(&position_3.m_float3)),
				f, g)));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::CatmullRom(const SR_Vector3 & position_1, const SR_Vector3 & position_2, const SR_Vector3 & position_3, const SR_Vector3 & position_4, float t)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorCatmullRom(
				std::move(DirectX::XMLoadFloat3(&position_1.m_float3)),
				std::move(DirectX::XMLoadFloat3(&position_2.m_float3)),
				std::move(DirectX::XMLoadFloat3(&position_3.m_float3)),
				std::move(DirectX::XMLoadFloat3(&position_4.m_float3)),
				t)));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::Hermite(const SR_Vector3 & position_1, const SR_Vector3 & tangent_1, const SR_Vector3 & position_2, const SR_Vector3 & tangent_2, float t)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVectorHermite(
				std::move(DirectX::XMLoadFloat3(&position_1.m_float3)),
				std::move(DirectX::XMLoadFloat3(&tangent_1.m_float3)),
				std::move(DirectX::XMLoadFloat3(&position_2.m_float3)),
				std::move(DirectX::XMLoadFloat3(&tangent_2.m_float3)),
				t)));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::Reflect(const SR_Vector3 & incident, const SR_Vector3 & normal)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVector3Reflect(
				std::move(DirectX::XMLoadFloat3(&incident.m_float3)),
				std::move(DirectX::XMLoadFloat3(&normal.m_float3)))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::Refract(const SR_Vector3 & incident, const SR_Vector3 & normal, float refractionIndex)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVector3Refract(
				std::move(DirectX::XMLoadFloat3(&incident.m_float3)),
				std::move(DirectX::XMLoadFloat3(&normal.m_float3)),
				refractionIndex)));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::Rotate(const SR_Vector3 & rotation, const DirectX::XMFLOAT4 & quaternion)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVector3Rotate(
				std::move(DirectX::XMLoadFloat3(&rotation.m_float3)),
				std::move(DirectX::XMLoadFloat4(&quaternion)))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::TransformCoord(const SR_Vector3 & vector3, const DirectX::XMFLOAT4X4 & float4x4)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVector3TransformCoord(
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)),
				std::move(DirectX::XMLoadFloat4x4(&float4x4)))));

		return std::move(vec3);
	}

	const SR_Vector3 SR_Vector3::TransformNormal(const SR_Vector3 & vector3, const DirectX::XMFLOAT4X4 & float4x4)
	{
		SR_Vector3 vec3;

		DirectX::XMStoreFloat3(
			&vec3.m_float3,
			std::move(DirectX::XMVector3TransformNormal(
				std::move(DirectX::XMLoadFloat3(&vector3.m_float3)),
				std::move(DirectX::XMLoadFloat4x4(&float4x4)))));

		return std::move(vec3);
	}

}