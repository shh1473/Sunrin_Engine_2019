#include "SR_PCH.h"
#include "SR_Matrix4x4.h"

namespace SunrinEngine
{

	const SR_Matrix4x4 SR_Matrix4x4::M_Identity{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f };

	constexpr SR_Matrix4x4::SR_Matrix4x4() noexcept :
		m_float4x4{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f }
	{

	}

	constexpr SR_Matrix4x4::SR_Matrix4x4(
		float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44) noexcept :
		m_float4x4{
		m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44 }
	{

	}

	constexpr SR_Matrix4x4::SR_Matrix4x4(
		const DirectX::XMFLOAT4 & r1,
		const DirectX::XMFLOAT4 & r2,
		const DirectX::XMFLOAT4 & r3,
		const DirectX::XMFLOAT4 & r4) noexcept :
		m_float4x4{
		r1.x, r1.y, r1.z, r1.w,
		r2.x, r2.y, r2.z, r2.w,
		r3.x, r3.y, r3.z, r3.w,
		r4.x, r4.y, r4.z, r4.w }
	{

	}

	constexpr SR_Matrix4x4::SR_Matrix4x4(const SR_Matrix4x4 & matrix4x4) noexcept :
		m_float4x4{ matrix4x4.m_float4x4 }
	{

	}

	constexpr SR_Matrix4x4::SR_Matrix4x4(SR_Matrix4x4 && matrix4x4) noexcept :
		m_float4x4{ std::move(matrix4x4.m_float4x4) }
	{

	}

	constexpr SR_Matrix4x4::SR_Matrix4x4(const DirectX::XMFLOAT4X4 & float4x4) noexcept :
		m_float4x4{ float4x4 }
	{

	}

	constexpr SR_Matrix4x4::SR_Matrix4x4(DirectX::XMFLOAT4X4 && float4x4) noexcept :
		m_float4x4{ std::move(float4x4) }
	{

	}

	SR_Matrix4x4::~SR_Matrix4x4() noexcept
	{

	}

	bool SR_Matrix4x4::operator==(const SR_Matrix4x4 & matrix4x4) const
	{
		return
			DirectX::XMVector4Equal(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._11)))) &&
			DirectX::XMVector4Equal(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._21)))) &&
			DirectX::XMVector4Equal(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._31)))) &&
			DirectX::XMVector4Equal(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._41))));
	}

	bool SR_Matrix4x4::operator!=(const SR_Matrix4x4 & matrix4x4) const
	{
		return
			DirectX::XMVector4NotEqual(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._11)))) ||
			DirectX::XMVector4NotEqual(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._21)))) ||
			DirectX::XMVector4NotEqual(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._31)))) ||
			DirectX::XMVector4NotEqual(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._41))));
	}

	SR_Matrix4x4 & SR_Matrix4x4::operator=(const SR_Matrix4x4 & matrix4x4) noexcept
	{
		m_float4x4 = matrix4x4.m_float4x4;

		return *this;
	}

	SR_Matrix4x4 & SR_Matrix4x4::operator=(SR_Matrix4x4 && matrix4x4) noexcept
	{
		m_float4x4 = std::move(matrix4x4.m_float4x4);

		return *this;
	}

	SR_Matrix4x4 & SR_Matrix4x4::operator+=(const SR_Matrix4x4 & matrix4x4)
	{
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._11),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._11))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._21),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._21))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._31),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._31))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._41),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._41))))));

		return *this;
	}

	SR_Matrix4x4 & SR_Matrix4x4::operator+=(float scalar)
	{
		DirectX::XMVECTOR s{ std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))) };

		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._11),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				s)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._21),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				s)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._31),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				s)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._41),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				s)));

		return *this;
	}

	SR_Matrix4x4 & SR_Matrix4x4::operator-=(const SR_Matrix4x4 & matrix4x4)
	{
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._11),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._11))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._21),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._21))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._31),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._31))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._41),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._41))))));

		return *this;
	}

	SR_Matrix4x4 & SR_Matrix4x4::operator-=(float scalar)
	{
		DirectX::XMVECTOR s{ std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))) };

		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._11),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				s)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._21),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				s)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._31),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				s)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._41),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				s)));

		return *this;
	}

	SR_Matrix4x4 & SR_Matrix4x4::operator*=(const SR_Matrix4x4 & matrix4x4)
	{
		DirectX::XMStoreFloat4x4(
			&m_float4x4,
			std::move(DirectX::XMMatrixMultiply(
				std::move(DirectX::XMLoadFloat4x4(&m_float4x4)),
				std::move(DirectX::XMLoadFloat4x4(&matrix4x4.m_float4x4)))));

		return *this;
	}

	SR_Matrix4x4 & SR_Matrix4x4::operator*=(float scalar)
	{
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._11),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				scalar)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._21),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				scalar)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._31),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				scalar)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._41),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				scalar)));

		return *this;
	}

	SR_Matrix4x4 & SR_Matrix4x4::operator/=(const SR_Matrix4x4 & matrix4x4)
	{
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._11),
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._11))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._21),
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._21))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._31),
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._31))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._41),
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._41))))));

		return *this;
	}

	SR_Matrix4x4 & SR_Matrix4x4::operator/=(float scalar)
	{
		float d{ 1.0f / scalar };

		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._11),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				d)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._21),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				d)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._31),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				d)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._41),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				d)));

		return *this;
	}

	const SR_Matrix4x4 SR_Matrix4x4::operator-() const noexcept
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._11),
			std::move(DirectX::XMVectorNegate(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._21),
			std::move(DirectX::XMVectorNegate(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._31),
			std::move(DirectX::XMVectorNegate(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._41),
			std::move(DirectX::XMVectorNegate(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))))));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::operator+(const SR_Matrix4x4 & matrix4x4)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._11),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._11))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._21),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._21))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._31),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._31))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._41),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._41))))));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::operator+(float scalar)
	{
		DirectX::XMVECTOR s{ std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))) };

		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._11),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				s)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._21),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				s)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._31),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				s)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._41),
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				s)));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::operator-(const SR_Matrix4x4 & matrix4x4)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._11),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._11))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._21),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._21))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._31),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._31))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._41),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._41))))));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::operator-(float scalar)
	{
		DirectX::XMVECTOR s{ std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))) };

		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._11),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				s)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._21),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				s)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._31),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				s)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._41),
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				s)));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::operator*(const SR_Matrix4x4 & matrix4x4)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&m_float4x4,
			std::move(DirectX::XMMatrixMultiply(
				std::move(DirectX::XMLoadFloat4x4(&m_float4x4)),
				std::move(DirectX::XMLoadFloat4x4(&matrix4x4.m_float4x4)))));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::operator*(float scalar)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._11),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				scalar)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._21),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				scalar)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._31),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				scalar)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._41),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				scalar)));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::operator/(const SR_Matrix4x4 & matrix4x4)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._11),
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._11))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._21),
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._21))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._31),
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._31))))));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._41),
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix4x4.m_float4x4._41))))));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::operator/(float scalar)
	{
		float d{ 1.0f / scalar };

		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._11),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._11))),
				d)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._21),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._21))),
				d)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._31),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._31))),
				d)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&m_float4x4._41),
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&m_float4x4._41))),
				d)));

		return std::move(mat4x4);
	}

	bool SR_Matrix4x4::Decompose(
		DirectX::XMFLOAT3 * translation,
		DirectX::XMFLOAT4 * rotation,
		DirectX::XMFLOAT3 * scale)
	{
		DirectX::XMVECTOR t, r, s;

		if (!DirectX::XMMatrixDecompose(&s, &r, &t, std::move(DirectX::XMLoadFloat4x4(&m_float4x4))))
		{
			return false;
		}

		DirectX::XMStoreFloat3(translation, std::move(t));
		DirectX::XMStoreFloat4(rotation, std::move(r));
		DirectX::XMStoreFloat3(scale, std::move(s));

		return true;
	}

	void SR_Matrix4x4::Transpose()
	{
		DirectX::XMStoreFloat4x4(
			&m_float4x4,
			std::move(DirectX::XMMatrixTranspose(
				std::move(DirectX::XMLoadFloat4x4(&m_float4x4)))));
	}

	void SR_Matrix4x4::Inverse()
	{
		DirectX::XMStoreFloat4x4(
			&m_float4x4,
			std::move(DirectX::XMMatrixInverse(
				nullptr,
				std::move(DirectX::XMLoadFloat4x4(&m_float4x4)))));
	}

	float SR_Matrix4x4::GetDeterminant() const
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMMatrixDeterminant(
				std::move(DirectX::XMLoadFloat4x4(&m_float4x4)))));
	}

	const SR_Matrix4x4 SR_Matrix4x4::GetInverse() const
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(DirectX::XMMatrixTranspose(
				std::move(DirectX::XMLoadFloat4x4(&m_float4x4)))));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::GetTranspose() const
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(DirectX::XMMatrixInverse(
				nullptr,
				std::move(DirectX::XMLoadFloat4x4(&m_float4x4)))));

		return std::move(mat4x4);
	}

	void SR_Matrix4x4::SetUpVector(const DirectX::XMFLOAT3 & float3) noexcept
	{
		m_float4x4._21 = float3.x;
		m_float4x4._22 = float3.y;
		m_float4x4._23 = float3.z;
	}

	void SR_Matrix4x4::SetDownVector(const DirectX::XMFLOAT3 & float3) noexcept
	{
		m_float4x4._21 = -float3.x;
		m_float4x4._22 = -float3.y;
		m_float4x4._23 = -float3.z;
	}

	void SR_Matrix4x4::SetRightVector(const DirectX::XMFLOAT3 & float3) noexcept
	{
		m_float4x4._11 = float3.x;
		m_float4x4._12 = float3.y;
		m_float4x4._13 = float3.z;
	}

	void SR_Matrix4x4::SetLeftVector(const DirectX::XMFLOAT3 & float3) noexcept
	{
		m_float4x4._11 = -float3.x;
		m_float4x4._12 = -float3.y;
		m_float4x4._13 = -float3.z;
	}

	void SR_Matrix4x4::SetForwardVector(const DirectX::XMFLOAT3 & float3) noexcept
	{
		m_float4x4._31 = float3.x;
		m_float4x4._32 = float3.y;
		m_float4x4._33 = float3.z;
	}

	void SR_Matrix4x4::SetBackwardVector(const DirectX::XMFLOAT3 & float3) noexcept
	{
		m_float4x4._31 = -float3.x;
		m_float4x4._32 = -float3.y;
		m_float4x4._33 = -float3.z;
	}

	void SR_Matrix4x4::SetTranslation(const DirectX::XMFLOAT3 & float3) noexcept
	{
		m_float4x4._41 = float3.x;
		m_float4x4._42 = float3.y;
		m_float4x4._43 = float3.z;
	}

	const DirectX::XMFLOAT3 SR_Matrix4x4::GetUpVector() const noexcept
	{
		return std::move(DirectX::XMFLOAT3(m_float4x4._21, m_float4x4._22, m_float4x4._23));
	}

	const DirectX::XMFLOAT3 SR_Matrix4x4::GetDownVector() const noexcept
	{
		return std::move(DirectX::XMFLOAT3(-m_float4x4._21, -m_float4x4._22, -m_float4x4._23));
	}

	const DirectX::XMFLOAT3 SR_Matrix4x4::GetRightVector() const noexcept
	{
		return std::move(DirectX::XMFLOAT3(m_float4x4._11, m_float4x4._12, m_float4x4._13));
	}

	const DirectX::XMFLOAT3 SR_Matrix4x4::GetLeftVector() const noexcept
	{
		return std::move(DirectX::XMFLOAT3(-m_float4x4._11, -m_float4x4._12, -m_float4x4._13));
	}

	const DirectX::XMFLOAT3 SR_Matrix4x4::GetForwardVector() const noexcept
	{
		return std::move(DirectX::XMFLOAT3(m_float4x4._31, m_float4x4._32, m_float4x4._33));
	}

	const DirectX::XMFLOAT3 SR_Matrix4x4::GetBackwardVector() const noexcept
	{
		return std::move(DirectX::XMFLOAT3(-m_float4x4._31, -m_float4x4._32, -m_float4x4._33));
	}

	const DirectX::XMFLOAT3 SR_Matrix4x4::GetTranslation() const noexcept
	{
		return std::move(DirectX::XMFLOAT3(m_float4x4._41, m_float4x4._42, m_float4x4._43));
	}

	const SR_Matrix4x4 SR_Matrix4x4::CreateBillboardMatrix(
		const DirectX::XMFLOAT3 & objectPosition,
		const DirectX::XMFLOAT3 & cameraPosition,
		const DirectX::XMFLOAT3 & cameraUpVector,
		const DirectX::XMFLOAT3 * cameraForwardVector)
	{
		DirectX::XMVECTOR o{ std::move(DirectX::XMLoadFloat3(&objectPosition)) };
		DirectX::XMVECTOR z{ std::move(DirectX::XMVectorSubtract(
			o,
			std::move(DirectX::XMLoadFloat3(&cameraPosition)))) };

		if (DirectX::XMVector3Less(
			std::move(DirectX::XMVector3LengthSq(z)),
			DirectX::g_XMEpsilon))
		{
			if (cameraForwardVector)
			{
				z = std::move(DirectX::XMVectorNegate(
					std::move(DirectX::XMLoadFloat3(cameraForwardVector))));
			}
			else
			{
				z = DirectX::g_XMNegIdentityR2;
			}
		}
		else
		{
			z = std::move(DirectX::XMVector3Normalize(z));
		}

		DirectX::XMVECTOR x{ std::move(DirectX::XMVector3Normalize(
			std::move(DirectX::XMVector3Cross(
				std::move(DirectX::XMLoadFloat3(&cameraUpVector)),
				z)))) };

		DirectX::XMMATRIX mat;
		mat.r[0] = x;
		mat.r[1] = std::move(DirectX::XMVector3Cross(
			z,
			x));
		mat.r[2] = z;
		mat.r[3] = std::move(DirectX::XMVectorSetW(
			o,
			1.0f));

		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(mat));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::CreateConstrainedBillboardMatrix(
		const DirectX::XMFLOAT3 & objectPosition,
		const DirectX::XMFLOAT3 & cameraPosition,
		const DirectX::XMFLOAT3 & rotateAxis,
		const DirectX::XMFLOAT3 * cameraForwardVector,
		const DirectX::XMFLOAT3 * objectForwardVector)
	{
		static const DirectX::XMVECTOR MinAngle{
			1.0f - DirectX::XMConvertToRadians(0.1f),
			1.0f - DirectX::XMConvertToRadians(0.1f),
			1.0f - DirectX::XMConvertToRadians(0.1f),
			1.0f - DirectX::XMConvertToRadians(0.1f) };

		DirectX::XMVECTOR o{ DirectX::XMLoadFloat3(&objectPosition) };
		DirectX::XMVECTOR faceDir{ DirectX::XMVectorSubtract(
			o,
			std::move(DirectX::XMLoadFloat3(&cameraPosition))) };

		if (DirectX::XMVector3Less(
			std::move(DirectX::XMVector3LengthSq(faceDir)),
			DirectX::g_XMEpsilon))
		{
			if (cameraForwardVector)
			{
				faceDir = std::move(DirectX::XMVectorNegate(
					std::move(DirectX::XMLoadFloat3(cameraForwardVector))));
			}
			else
			{
				faceDir = DirectX::g_XMNegIdentityR2;
			}
		}
		else
		{
			faceDir = std::move(DirectX::XMVector3Normalize(faceDir));
		}

		DirectX::XMVECTOR x;
		DirectX::XMVECTOR y{ std::move(DirectX::XMLoadFloat3(&rotateAxis)) };
		DirectX::XMVECTOR z;
		DirectX::XMVECTOR dot{ std::move(DirectX::XMVectorAbs(
			std::move(DirectX::XMVector3Dot(
				y,
				faceDir)))) };

		if (DirectX::XMVector3Greater(
			dot,
			MinAngle))
		{
			if (objectForwardVector)
			{
				z = std::move(DirectX::XMLoadFloat3(objectForwardVector));
				dot = std::move(DirectX::XMVectorAbs(
					std::move(DirectX::XMVector3Dot(
						y,
						z))));

				if (DirectX::XMVector3Greater(
					dot,
					MinAngle))
				{
					dot = std::move(DirectX::XMVectorAbs(
						std::move(DirectX::XMVector3Dot(
							y,
							DirectX::g_XMNegIdentityR2))));
					z = (DirectX::XMVector3Greater(dot, MinAngle)) ? DirectX::g_XMIdentityR0 : DirectX::g_XMNegIdentityR2;
				}
			}
			else
			{
				dot = std::move(DirectX::XMVectorAbs(
					std::move(DirectX::XMVector3Dot(
						y,
						DirectX::g_XMNegIdentityR2))));
				z = (DirectX::XMVector3Greater(dot, MinAngle)) ? DirectX::g_XMIdentityR0 : DirectX::g_XMNegIdentityR2;
			}

			x = std::move(DirectX::XMVector3Normalize(
				std::move(DirectX::XMVector3Cross(
					y,
					z))));
			z = std::move(DirectX::XMVector3Normalize(
				std::move(DirectX::XMVector3Cross(
					x,
					y))));
		}
		else
		{
			x = std::move(DirectX::XMVector3Normalize(
				std::move(DirectX::XMVector3Cross(
					y,
					faceDir))));
			z = std::move(DirectX::XMVector3Normalize(
				std::move(DirectX::XMVector3Cross(
					x,
					y))));
		}

		DirectX::XMMATRIX mat;
		mat.r[0] = x;
		mat.r[1] = y;
		mat.r[2] = z;
		mat.r[3] = std::move(DirectX::XMVectorSetW(
			o,
			1.0f));

		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(mat));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::CreateTranslationMatrix(const DirectX::XMFLOAT3 & position)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(DirectX::XMMatrixTranslation(
				position.x,
				position.y,
				position.z)));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::CreateRotationMatrix(const DirectX::XMFLOAT3 & rotation)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(DirectX::XMMatrixRotationRollPitchYaw(
				rotation.x,
				rotation.y,
				rotation.z)));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::CreateScaleMatrix(const DirectX::XMFLOAT3 & scale)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(DirectX::XMMatrixScaling(
				scale.x,
				scale.y,
				scale.z)));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::CreatePerspectiveFieldOfView(float fieldOfView, float aspectRatio, float nearZ, float farZ)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(DirectX::XMMatrixPerspectiveFovLH(
				fieldOfView,
				aspectRatio,
				nearZ,
				farZ)));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::CreatePerspective(float width, float height, float nearZ, float farZ)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(DirectX::XMMatrixPerspectiveLH(
				width,
				height,
				nearZ,
				farZ)));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::CreatePerspectiveOffCenter(float left, float top, float right, float bottom, float nearZ, float farZ)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(DirectX::XMMatrixPerspectiveOffCenterLH(
				left,
				right,
				top,
				bottom,
				nearZ,
				farZ)));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::CreateOrthographic(float width, float height, float nearZ, float farZ)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(DirectX::XMMatrixOrthographicLH(
				width,
				height,
				nearZ,
				farZ)));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::CreateOrthographicOffCenter(float left, float top, float right, float bottom, float nearZ, float farZ)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(DirectX::XMMatrixOrthographicOffCenterLH(
				left,
				right,
				top,
				bottom,
				nearZ,
				farZ)));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::CreateLookAt(const DirectX::XMFLOAT3 & eyeVector, const DirectX::XMFLOAT3 & lookVector, const DirectX::XMFLOAT3 & upVector)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(DirectX::XMMatrixLookAtLH(
				std::move(DirectX::XMLoadFloat3(&eyeVector)),
				std::move(DirectX::XMLoadFloat3(&lookVector)),
				std::move(DirectX::XMLoadFloat3(&upVector)))));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::CreateWorld(const DirectX::XMFLOAT3 & position, const DirectX::XMFLOAT3 & forwardVector, const DirectX::XMFLOAT3 & upVector)
	{
		DirectX::XMVECTOR axisZ{ std::move(DirectX::XMVector3Normalize(
			std::move(DirectX::XMVectorNegate(
				std::move(DirectX::XMLoadFloat3(&forwardVector)))))) };
		DirectX::XMVECTOR axisY{ std::move(DirectX::XMLoadFloat3(&upVector)) };
		DirectX::XMVECTOR axisX{ std::move(DirectX::XMVector3Normalize(
			std::move(DirectX::XMVector3Cross(
				axisY,
				axisZ)))) };

		axisY = DirectX::XMVector3Cross(
			axisZ,
			axisX);

		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat3(
			reinterpret_cast<DirectX::XMFLOAT3*>(&mat4x4.m_float4x4._11),
			std::move(axisX));
		DirectX::XMStoreFloat3(
			reinterpret_cast<DirectX::XMFLOAT3*>(&mat4x4.m_float4x4._21),
			std::move(axisY));
		DirectX::XMStoreFloat3(
			reinterpret_cast<DirectX::XMFLOAT3*>(&mat4x4.m_float4x4._31),
			std::move(axisZ));

		mat4x4.m_float4x4._14 = 0.0f;
		mat4x4.m_float4x4._24 = 0.0f;
		mat4x4.m_float4x4._34 = 0.0f;
		mat4x4.m_float4x4._41 = position.x;
		mat4x4.m_float4x4._42 = position.y;
		mat4x4.m_float4x4._43 = position.z;
		mat4x4.m_float4x4._44 = 1.0f;

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::Lerp(const SR_Matrix4x4 & matrix1, const SR_Matrix4x4 & matrix2, float t)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._11),
			std::move(DirectX::XMVectorLerp(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix1.m_float4x4._11))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix2.m_float4x4._21))),
				t)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._21),
			std::move(DirectX::XMVectorLerp(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix1.m_float4x4._31))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix2.m_float4x4._41))),
				t)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._31),
			std::move(DirectX::XMVectorLerp(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix1.m_float4x4._11))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix2.m_float4x4._21))),
				t)));
		DirectX::XMStoreFloat4(
			reinterpret_cast<DirectX::XMFLOAT4*>(&mat4x4.m_float4x4._41),
			std::move(DirectX::XMVectorLerp(
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix1.m_float4x4._31))),
				std::move(DirectX::XMLoadFloat4(reinterpret_cast<const DirectX::XMFLOAT4*>(&matrix2.m_float4x4._41))),
				t)));

		return std::move(mat4x4);
	}

	const SR_Matrix4x4 SR_Matrix4x4::Transform(const SR_Matrix4x4 & matrix, const DirectX::XMFLOAT4 & quaternion)
	{
		SR_Matrix4x4 mat4x4;

		DirectX::XMStoreFloat4x4(
			&mat4x4.m_float4x4,
			std::move(DirectX::XMMatrixMultiply(
				std::move(DirectX::XMLoadFloat4x4(&matrix.m_float4x4)),
				std::move(DirectX::XMMatrixRotationQuaternion(
					std::move(DirectX::XMLoadFloat4(&quaternion)))))));

		return std::move(mat4x4);
	}

}