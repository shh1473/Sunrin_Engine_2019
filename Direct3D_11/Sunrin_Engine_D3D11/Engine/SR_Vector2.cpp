#include "SR_PCH.h"
#include "SR_Vector2.h"

namespace SunrinEngine
{

	const SR_Vector2 SR_Vector2::M_Zero		{ 0.0f, 0.0f };
	const SR_Vector2 SR_Vector2::M_One		{ 1.0f, 1.0f };
	const SR_Vector2 SR_Vector2::M_UnitX	{ 1.0f, 0.0f };
	const SR_Vector2 SR_Vector2::M_UnitY	{ 0.0f, 1.0f };

	constexpr SR_Vector2::SR_Vector2() noexcept :
		m_float2{ 0.0f, 0.0f }
	{

	}

	constexpr SR_Vector2::SR_Vector2(float x, float y) noexcept :
		m_float2{ x, y }
	{

	}

	constexpr SR_Vector2::SR_Vector2(const SR_Vector2 & vector2) noexcept :
		m_float2{ vector2.m_float2 }
	{
	}

	constexpr SR_Vector2::SR_Vector2(SR_Vector2 && vector2) noexcept :
		m_float2{ std::move(vector2.m_float2) }
	{
	}

	constexpr SR_Vector2::SR_Vector2(const DirectX::XMFLOAT2 & float2) noexcept :
		m_float2{ float2 }
	{

	}

	constexpr SR_Vector2::SR_Vector2(DirectX::XMFLOAT2 && float2) noexcept :
		m_float2{ std::move(float2) }
	{

	}

	SR_Vector2::~SR_Vector2() noexcept
	{

	}

	bool SR_Vector2::operator==(const SR_Vector2 & vector2) const
	{
		return DirectX::XMVector2Equal(
			std::move(DirectX::XMLoadFloat2(&m_float2)),
			std::move(DirectX::XMLoadFloat2(&vector2.m_float2)));
	}

	bool SR_Vector2::operator!=(const SR_Vector2 & vector2) const
	{
		return DirectX::XMVector2NotEqual(
			std::move(DirectX::XMLoadFloat2(&m_float2)),
			std::move(DirectX::XMLoadFloat2(&vector2.m_float2)));
	}

	SR_Vector2 & SR_Vector2::operator=(const SR_Vector2 & vector2) noexcept
	{
		m_float2 = vector2.m_float2;

		return *this;
	}

	SR_Vector2 & SR_Vector2::operator=(SR_Vector2 && vector2) noexcept
	{
		m_float2 = std::move(vector2.m_float2);

		return *this;
	}

	SR_Vector2 & SR_Vector2::operator+=(const SR_Vector2 & vector2)
	{
		DirectX::XMStoreFloat2(
			&m_float2,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)))));

		return *this;
	}

	SR_Vector2 & SR_Vector2::operator+=(float scalar)
	{
		DirectX::XMStoreFloat2(
			&m_float2,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				std::move(DirectX::XMLoadFloat2(&DirectX::XMFLOAT2(scalar, scalar))))));

		return *this;
	}

	SR_Vector2 & SR_Vector2::operator-=(const SR_Vector2 & vector2)
	{
		DirectX::XMStoreFloat2(
			&m_float2,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)))));

		return *this;
	}

	SR_Vector2 & SR_Vector2::operator-=(float scalar)
	{
		DirectX::XMStoreFloat2(
			&m_float2,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				std::move(DirectX::XMLoadFloat2(&DirectX::XMFLOAT2(scalar, scalar))))));

		return *this;
	}

	SR_Vector2 & SR_Vector2::operator*=(const SR_Vector2 & vector2)
	{
		DirectX::XMStoreFloat2(
			&m_float2,
			std::move(DirectX::XMVectorMultiply(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)))));

		return *this;
	}

	SR_Vector2 & SR_Vector2::operator*=(float scalar)
	{
		DirectX::XMStoreFloat2(
			&m_float2,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				scalar)));

		return *this;
	}

	SR_Vector2 & SR_Vector2::operator/=(const SR_Vector2 & vector2)
	{
		DirectX::XMStoreFloat2(
			&m_float2,
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)))));

		return *this;
	}

	SR_Vector2 & SR_Vector2::operator/=(float scalar)
	{
		DirectX::XMStoreFloat2(
			&m_float2,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				1.0f / scalar)));

		return *this;
	}

	const SR_Vector2 SR_Vector2::operator-() const
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorNegate(
				std::move(DirectX::XMLoadFloat2(&m_float2)))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::operator+(const SR_Vector2 & vector2) const
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::operator+(float scalar) const
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				std::move(DirectX::XMLoadFloat2(&DirectX::XMFLOAT2(scalar, scalar))))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::operator-(const SR_Vector2 & vector2) const
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::operator-(float scalar) const
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				std::move(DirectX::XMLoadFloat2(&DirectX::XMFLOAT2(scalar, scalar))))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::operator*(const SR_Vector2 & vector2) const
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorMultiply(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::operator*(float scalar) const
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				scalar)));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::operator/(const SR_Vector2 & vector2) const
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::operator/(float scalar) const
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat2(&m_float2)),
				1.0f / scalar)));

		return std::move(vec2);
	}

	bool SR_Vector2::InBounds(const SR_Vector2 & vector2, const SR_Vector2 & bounds)
	{
		return DirectX::XMVector2InBounds(
			std::move(DirectX::XMLoadFloat2(&vector2.m_float2)),
			std::move(DirectX::XMLoadFloat2(&bounds.m_float2)));
	}

	float SR_Vector2::Length(const SR_Vector2 & vector2)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector2Length(
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)))));
	}

	float SR_Vector2::LengthSquared(const SR_Vector2 & vector2)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector2LengthSq(
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)))));
	}

	float SR_Vector2::Distance(const SR_Vector2 & position_1, const SR_Vector2 & position_2)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector2Length(
				std::move(DirectX::XMVectorSubtract(
					std::move(DirectX::XMLoadFloat2(&position_2.m_float2)),
					std::move(DirectX::XMLoadFloat2(&position_1.m_float2)))))));
	}

	float SR_Vector2::DistanceSquared(const SR_Vector2 & position_1, const SR_Vector2 & position_2)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector2LengthSq(
				std::move(DirectX::XMVectorSubtract(
					std::move(DirectX::XMLoadFloat2(&position_2.m_float2)),
					std::move(DirectX::XMLoadFloat2(&position_1.m_float2)))))));
	}

	float SR_Vector2::Dot(const SR_Vector2 & vector2_1, const SR_Vector2 & vector2_2)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMVector2Dot(
				std::move(DirectX::XMLoadFloat2(&vector2_1.m_float2)),
				std::move(DirectX::XMLoadFloat2(&vector2_2.m_float2)))));
	}

	const SR_Vector2 SR_Vector2::Cross(const SR_Vector2 & vector2_1, const SR_Vector2 & vector2_2)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVector2Cross(
				std::move(DirectX::XMLoadFloat2(&vector2_1.m_float2)),
				std::move(DirectX::XMLoadFloat2(&vector2_2.m_float2)))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::Normalize(const SR_Vector2 & vector2)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVector2Normalize(
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::Clamp(const SR_Vector2 & vector2, const SR_Vector2 & min, const SR_Vector2 & max)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorClamp(
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)),
				std::move(DirectX::XMLoadFloat2(&min.m_float2)),
				std::move(DirectX::XMLoadFloat2(&max.m_float2)))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::Min(const SR_Vector2 & vector2_1, const SR_Vector2 & vector2_2)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorMin(
				std::move(DirectX::XMLoadFloat2(&vector2_1.m_float2)),
				std::move(DirectX::XMLoadFloat2(&vector2_2.m_float2)))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::Max(const SR_Vector2 & vector2_1, const SR_Vector2 & vector2_2)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorMax(
				std::move(DirectX::XMLoadFloat2(&vector2_1.m_float2)),
				std::move(DirectX::XMLoadFloat2(&vector2_2.m_float2)))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::Lerp(const SR_Vector2 & position_1, const SR_Vector2 & position_2, float t)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorLerp(
				std::move(DirectX::XMLoadFloat2(&position_1.m_float2)),
				std::move(DirectX::XMLoadFloat2(&position_2.m_float2)), t)));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::SmoothStep(const SR_Vector2 & position_1, const SR_Vector2 & position_2, float t)
	{
		t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t);
		t = t * t * (3.0f - (2.0f * t));

		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorLerp(
				std::move(DirectX::XMLoadFloat2(&position_1.m_float2)),
				std::move(DirectX::XMLoadFloat2(&position_2.m_float2)),
				t)));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::BaryCentric(const SR_Vector2 & position_1, const SR_Vector2 & position_2, const SR_Vector2 & position_3, float f, float g)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorBaryCentric(
				std::move(DirectX::XMLoadFloat2(&position_1.m_float2)),
				std::move(DirectX::XMLoadFloat2(&position_2.m_float2)),
				std::move(DirectX::XMLoadFloat2(&position_3.m_float2)),
				f, g)));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::CatmullRom(const SR_Vector2 & position_1, const SR_Vector2 & position_2, const SR_Vector2 & position_3, const SR_Vector2 & position_4, float t)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorCatmullRom(
				std::move(DirectX::XMLoadFloat2(&position_1.m_float2)),
				std::move(DirectX::XMLoadFloat2(&position_2.m_float2)),
				std::move(DirectX::XMLoadFloat2(&position_3.m_float2)),
				std::move(DirectX::XMLoadFloat2(&position_4.m_float2)),
				t)));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::Hermite(const SR_Vector2 & position_1, const SR_Vector2 & tangent_1, const SR_Vector2 & position_2, const SR_Vector2 & tangent_2, float t)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVectorHermite(
				std::move(DirectX::XMLoadFloat2(&position_1.m_float2)),
				std::move(DirectX::XMLoadFloat2(&tangent_1.m_float2)),
				std::move(DirectX::XMLoadFloat2(&position_2.m_float2)),
				std::move(DirectX::XMLoadFloat2(&tangent_2.m_float2)),
				t)));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::Reflect(const SR_Vector2 & incident, const SR_Vector2 & normal)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVector2Reflect(
				std::move(DirectX::XMLoadFloat2(&incident.m_float2)),
				std::move(DirectX::XMLoadFloat2(&normal.m_float2)))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::Refract(const SR_Vector2 & incident, const SR_Vector2 & normal, float refractionIndex)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVector2Refract(
				std::move(DirectX::XMLoadFloat2(&incident.m_float2)),
				std::move(DirectX::XMLoadFloat2(&normal.m_float2)),
				refractionIndex)));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::Rotate(const SR_Vector2 & rotation, const DirectX::XMFLOAT4 & quaternion)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVector3Rotate(
				std::move(DirectX::XMLoadFloat2(&rotation.m_float2)),
				std::move(DirectX::XMLoadFloat4(&quaternion)))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::TransformCoord(const SR_Vector2 & vector2, const DirectX::XMFLOAT4X4 & matrix)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVector2TransformCoord(
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)),
				std::move(DirectX::XMLoadFloat4x4(&matrix)))));

		return std::move(vec2);
	}

	const SR_Vector2 SR_Vector2::TransformNormal(const SR_Vector2 & vector2, const DirectX::XMFLOAT4X4 & matrix)
	{
		SR_Vector2 vec2;

		DirectX::XMStoreFloat2(
			&vec2.m_float2,
			std::move(DirectX::XMVector2TransformNormal(
				std::move(DirectX::XMLoadFloat2(&vector2.m_float2)),
				std::move(DirectX::XMLoadFloat4x4(&matrix)))));

		return std::move(vec2);
	}

}