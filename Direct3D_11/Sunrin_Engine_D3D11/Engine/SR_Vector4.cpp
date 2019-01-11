#include "SR_PCH.h"
#include "SR_Vector4.h"

namespace SunrinEngine
{

	const SR_Vector4 SR_Vector4::M_Zero		{ 0.0f, 0.0f, 0.0f, 0.0f };
	const SR_Vector4 SR_Vector4::M_One		{ 1.0f, 1.0f, 1.0f, 1.0f };
	const SR_Vector4 SR_Vector4::M_UnitX	{ 1.0f, 0.0f, 0.0f, 0.0f };
	const SR_Vector4 SR_Vector4::M_UnitY	{ 0.0f, 1.0f, 0.0f, 0.0f };
	const SR_Vector4 SR_Vector4::M_UnitZ	{ 0.0f, 0.0f, 1.0f, 0.0f };
	const SR_Vector4 SR_Vector4::M_UnitW	{ 0.0f, 0.0f, 0.0f, 1.0f };

	constexpr SR_Vector4::SR_Vector4() noexcept :
		m_float4{ 0.0f, 0.0f, 0.0f, 0.0f }
	{

	}

	constexpr SR_Vector4::SR_Vector4(float x, float y, float z, float w) noexcept :
		m_float4{ x, y, z, w }
	{

	}

	constexpr SR_Vector4::SR_Vector4(const SR_Vector4 & vector4) noexcept :
		m_float4{ vector4.m_float4 }
	{

	}

	constexpr SR_Vector4::SR_Vector4(SR_Vector4 && vector4) noexcept :
		m_float4{ std::move(vector4.m_float4) }
	{
	}

	constexpr SR_Vector4::SR_Vector4(const DirectX::XMFLOAT4 & float4) noexcept :
		m_float4{ float4 }
	{

	}

	constexpr SR_Vector4::SR_Vector4(DirectX::XMFLOAT4 && float4) noexcept :
		m_float4{ std::move(float4) }
	{

	}

	SR_Vector4::~SR_Vector4() noexcept
	{

	}

	bool SR_Vector4::operator==(const SR_Vector4 & vector4) const
	{
		return DirectX::XMVector4Equal(
			std::move(DirectX::XMLoadFloat4(&m_float4)),
			std::move(DirectX::XMLoadFloat4(&vector4.m_float4)));
	}

	bool SR_Vector4::operator!=(const SR_Vector4 & vector4) const
	{
		return DirectX::XMVector4NotEqual(
			std::move(DirectX::XMLoadFloat4(&m_float4)),
			std::move(DirectX::XMLoadFloat4(&vector4.m_float4)));
	}

	SR_Vector4 & SR_Vector4::operator=(const SR_Vector4 & vector4) noexcept
	{
		m_float4 = vector4.m_float4;

		return *this;
	}

	SR_Vector4 & SR_Vector4::operator=(SR_Vector4 && vector4) noexcept
	{
		m_float4 = std::move(vector4.m_float4);

		return *this;
	}

	SR_Vector4 & SR_Vector4::operator+=(const SR_Vector4 & vector4)
	{
		DirectX::XMStoreFloat4(
			&m_float4,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				std::move(DirectX::XMLoadFloat4(&vector4.m_float4)))));

		return *this;
	}

	SR_Vector4 & SR_Vector4::operator+=(float scalar)
	{
		DirectX::XMStoreFloat4(
			&m_float4,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))))));

		return *this;
	}

	SR_Vector4 & SR_Vector4::operator-=(const SR_Vector4 & vector4)
	{
		DirectX::XMStoreFloat4(
			&m_float4,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				std::move(DirectX::XMLoadFloat4(&vector4.m_float4)))));

		return *this;
	}

	SR_Vector4 & SR_Vector4::operator-=(float scalar)
	{
		DirectX::XMStoreFloat4(
			&m_float4,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))))));

		return *this;
	}

	SR_Vector4 & SR_Vector4::operator*=(const SR_Vector4 & vector4)
	{
		DirectX::XMStoreFloat4(
			&m_float4,
			std::move(DirectX::XMVectorMultiply(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				std::move(DirectX::XMLoadFloat4(&vector4.m_float4)))));

		return *this;
	}

	SR_Vector4 & SR_Vector4::operator*=(float scalar)
	{
		DirectX::XMStoreFloat4(
			&m_float4,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				scalar)));

		return *this;
	}

	SR_Vector4 & SR_Vector4::operator/=(const SR_Vector4 & vector4)
	{
		DirectX::XMStoreFloat4(
			&m_float4,
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				std::move(DirectX::XMLoadFloat4(&vector4.m_float4)))));

		return *this;
	}

	SR_Vector4 & SR_Vector4::operator/=(float scalar)
	{
		DirectX::XMStoreFloat4(
			&m_float4,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				1.0f / scalar)));

		return *this;
	}

	const SR_Vector4 SR_Vector4::operator-() const
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorNegate(
				std::move(DirectX::XMLoadFloat4(&m_float4)))));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::operator+(const SR_Vector4 & vector4) const
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				std::move(DirectX::XMLoadFloat4(&vector4.m_float4)))));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::operator+(float scalar) const
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))))));

		return *this;
	}

	const SR_Vector4 SR_Vector4::operator-(const SR_Vector4 & vector4) const
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				std::move(DirectX::XMLoadFloat4(&vector4.m_float4)))));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::operator-(float scalar) const
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))))));

		return *this;
	}

	const SR_Vector4 SR_Vector4::operator*(const SR_Vector4 & vector4) const
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorMultiply(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				std::move(DirectX::XMLoadFloat4(&vector4.m_float4)))));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::operator*(float scalar) const
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				scalar)));

		return *this;
	}

	const SR_Vector4 SR_Vector4::operator/(const SR_Vector4 & vector4) const
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				std::move(DirectX::XMLoadFloat4(&vector4.m_float4)))));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::operator/(float scalar) const
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(&m_float4)),
				1.0f / scalar)));

		return *this;
	}

	bool SR_Vector4::InBounds(const SR_Vector4 & vector4, const SR_Vector4 & bounds)
	{
		return DirectX::XMVector4InBounds(
			std::move(DirectX::XMLoadFloat4(&vector4.m_float4)),
			std::move(DirectX::XMLoadFloat4(&bounds.m_float4)));
	}

	float SR_Vector4::Length(const SR_Vector4 & vector4)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector4Length(
				std::move(DirectX::XMLoadFloat4(&vector4.m_float4)))));
	}

	float SR_Vector4::LengthSquared(const SR_Vector4 & vector4)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector4LengthSq(
				std::move(DirectX::XMLoadFloat4(&vector4.m_float4)))));
	}

	float SR_Vector4::Distance(const SR_Vector4 & position_1, const SR_Vector4 & position_2)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector4Length(
				std::move(DirectX::XMVectorSubtract(
					std::move(std::move(DirectX::XMLoadFloat4(&position_2.m_float4))),
					std::move(std::move(DirectX::XMLoadFloat4(&position_1.m_float4))))))));
	}

	float SR_Vector4::DistanceSquared(const SR_Vector4 & position_1, const SR_Vector4 & position_2)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector4LengthSq(
				std::move(DirectX::XMVectorSubtract(
					std::move(std::move(DirectX::XMLoadFloat4(&position_2.m_float4))),
					std::move(std::move(DirectX::XMLoadFloat4(&position_1.m_float4))))))));
	}

	float SR_Vector4::Dot(const SR_Vector4 & vector4_1, const SR_Vector4 & vector4_2)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector4Dot(
				std::move(DirectX::XMLoadFloat4(&vector4_1.m_float4)),
				std::move(DirectX::XMLoadFloat4(&vector4_2.m_float4)))));
	}

	const SR_Vector4 SR_Vector4::Cross(const SR_Vector4 & vector4_1, const SR_Vector4 & vector4_2, const SR_Vector4 & vector4_3)
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVector4Cross(
				std::move(DirectX::XMLoadFloat4(&vector4_1.m_float4)),
				std::move(DirectX::XMLoadFloat4(&vector4_2.m_float4)),
				std::move(DirectX::XMLoadFloat4(&vector4_3.m_float4)))));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::Normalize(const SR_Vector4 & vector4)
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			DirectX::XMVector4Normalize(
				DirectX::XMLoadFloat4(&vector4.m_float4)));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::Clamp(const SR_Vector4 & vector4, const SR_Vector4 & min, const SR_Vector4 & max)
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorClamp(
				std::move(DirectX::XMLoadFloat4(&vector4.m_float4)),
				std::move(DirectX::XMLoadFloat4(&min.m_float4)),
				std::move(DirectX::XMLoadFloat4(&max.m_float4)))));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::Min(const SR_Vector4 & vector4_1, const SR_Vector4 & vector4_2)
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorMin(
				std::move(DirectX::XMLoadFloat4(&vector4_1.m_float4)),
				std::move(DirectX::XMLoadFloat4(&vector4_2.m_float4)))));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::Max(const SR_Vector4 & vector4_1, const SR_Vector4 & vector4_2)
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorMax(
				std::move(DirectX::XMLoadFloat4(&vector4_1.m_float4)),
				std::move(DirectX::XMLoadFloat4(&vector4_2.m_float4)))));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::Lerp(const SR_Vector4 & position_1, const SR_Vector4 & position_2, float t)
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorLerp(
				std::move(DirectX::XMLoadFloat4(&position_1.m_float4)),
				std::move(DirectX::XMLoadFloat4(&position_2.m_float4)),
				t)));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::SmoothStep(const SR_Vector4 & position_1, const SR_Vector4 & position_2, float t)
	{
		t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t);
		t = t * t * (3.0f - (2.0f * t));

		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorLerp(
				std::move(DirectX::XMLoadFloat4(&position_1.m_float4)),
				std::move(DirectX::XMLoadFloat4(&position_2.m_float4)),
				t)));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::BaryCentric(const SR_Vector4 & position_1, const SR_Vector4 & position_2, const SR_Vector4 & position_3, float f, float g)
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorBaryCentric(
				std::move(DirectX::XMLoadFloat4(&position_1.m_float4)),
				std::move(DirectX::XMLoadFloat4(&position_2.m_float4)),
				std::move(DirectX::XMLoadFloat4(&position_3.m_float4)),
				f, g)));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::CatmullRom(const SR_Vector4 & position_1, const SR_Vector4 & position_2, const SR_Vector4 & position_3, const SR_Vector4 & position_4, float t)
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorCatmullRom(
				std::move(DirectX::XMLoadFloat4(&position_1.m_float4)),
				std::move(DirectX::XMLoadFloat4(&position_2.m_float4)),
				std::move(DirectX::XMLoadFloat4(&position_3.m_float4)),
				std::move(DirectX::XMLoadFloat4(&position_4.m_float4)),
				t)));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::Hermite(const SR_Vector4 & position_1, const SR_Vector4 & tangent_1, const SR_Vector4 & position_2, const SR_Vector4 & tangent_2, float t)
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorHermite(
				std::move(DirectX::XMLoadFloat4(&position_1.m_float4)),
				std::move(DirectX::XMLoadFloat4(&tangent_1.m_float4)),
				std::move(DirectX::XMLoadFloat4(&position_2.m_float4)),
				std::move(DirectX::XMLoadFloat4(&tangent_2.m_float4)),
				t)));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::Reflect(const SR_Vector4 & incident, const SR_Vector4 & normal)
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVector4Reflect(
				std::move(DirectX::XMLoadFloat4(&incident.m_float4)),
				std::move(DirectX::XMLoadFloat4(&normal.m_float4)))));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::Refract(const SR_Vector4 & incident, const SR_Vector4 & normal, float refractionIndex)
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVector4Refract(
				std::move(DirectX::XMLoadFloat4(&incident.m_float4)),
				std::move(DirectX::XMLoadFloat4(&normal.m_float4)),
				refractionIndex)));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::Rotate(const SR_Vector4 & rotation, const DirectX::XMFLOAT4 & quaternion)
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVectorSelect(
				DirectX::g_XMIdentityR3,
				std::move(DirectX::XMVector3Rotate(
					std::move(DirectX::XMLoadFloat4(&rotation.m_float4)),
					std::move(DirectX::XMLoadFloat4(&quaternion)))),
				DirectX::g_XMSelect1110)));

		return std::move(vec4);
	}

	const SR_Vector4 SR_Vector4::Transform(const SR_Vector4 & vector4, const DirectX::XMFLOAT4X4 & float4x4)
	{
		SR_Vector4 vec4;

		DirectX::XMStoreFloat4(
			&vec4.m_float4,
			std::move(DirectX::XMVector4Transform(
				std::move(DirectX::XMLoadFloat4(&vector4.m_float4)),
				std::move(DirectX::XMLoadFloat4x4(&float4x4)))));

		return std::move(vec4);
	}

}