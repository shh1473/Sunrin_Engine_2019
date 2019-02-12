#include "SR_PCH.h"

#include "SR_Quaternion.h"

namespace SunrinEngine
{

	const SR_Quaternion SR_Quaternion::M_Identity{ 0.0f, 0.0f, 0.0f, 1.0f };

	SR_Quaternion::SR_Quaternion() noexcept :
		m_quaternion{}
	{

	}

	SR_Quaternion::SR_Quaternion(float x, float y, float z, float w) noexcept :
		m_quaternion{ x, y, z, w }
	{

	}

	SR_Quaternion::SR_Quaternion(const SR_Quaternion & quaternion) noexcept :
		m_quaternion{ quaternion.m_quaternion }
	{

	}

	SR_Quaternion::SR_Quaternion(SR_Quaternion && quaternion) noexcept :
		m_quaternion{ std::move(quaternion.m_quaternion) }
	{

	}

	SR_Quaternion::SR_Quaternion(const DirectX::XMFLOAT4 & float4) noexcept :
		m_quaternion{ float4 }
	{

	}

	SR_Quaternion::SR_Quaternion(DirectX::XMFLOAT4 && float4) noexcept :
		m_quaternion{ std::move(float4) }
	{

	}

	bool SR_Quaternion::operator==(const SR_Quaternion & quaternion) const
	{
		return DirectX::XMQuaternionEqual(
			std::move(DirectX::XMLoadFloat4(&m_quaternion)),
			std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)));
	}

	bool SR_Quaternion::operator!=(const SR_Quaternion & quaternion) const
	{
		return DirectX::XMQuaternionNotEqual(
			std::move(DirectX::XMLoadFloat4(&m_quaternion)),
			std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)));
	}

	SR_Quaternion & SR_Quaternion::operator=(const SR_Quaternion & quaternion) noexcept
	{
		m_quaternion = quaternion.m_quaternion;

		return *this;
	}

	SR_Quaternion & SR_Quaternion::operator=(SR_Quaternion && quaternion) noexcept
	{
		m_quaternion = std::move(quaternion.m_quaternion);

		return *this;
	}

	SR_Quaternion & SR_Quaternion::operator+=(const SR_Quaternion & quaternion)
	{
		DirectX::XMStoreFloat4(
			&m_quaternion,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)))));

		return *this;
	}

	SR_Quaternion & SR_Quaternion::operator+=(float scalar)
	{
		DirectX::XMStoreFloat4(
			&m_quaternion,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))))));

		return *this;
	}

	SR_Quaternion & SR_Quaternion::operator-=(const SR_Quaternion & quaternion)
	{
		DirectX::XMStoreFloat4(
			&m_quaternion,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)))));

		return *this;
	}

	SR_Quaternion & SR_Quaternion::operator-=(float scalar)
	{
		DirectX::XMStoreFloat4(
			&m_quaternion,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))))));

		return *this;
	}

	SR_Quaternion & SR_Quaternion::operator*=(const SR_Quaternion & quaternion)
	{
		DirectX::XMStoreFloat4(
			&m_quaternion,
			std::move(DirectX::XMQuaternionMultiply(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)))));

		return *this;
	}

	SR_Quaternion & SR_Quaternion::operator*=(float scalar)
	{
		DirectX::XMStoreFloat4(
			&m_quaternion,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				scalar)));

		return *this;
	}

	SR_Quaternion & SR_Quaternion::operator/=(const SR_Quaternion & quaternion)
	{
		DirectX::XMStoreFloat4(
			&m_quaternion,
			std::move(DirectX::XMQuaternionMultiply(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				std::move(DirectX::XMQuaternionInverse(
					std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)))))));

		return *this;
	}

	SR_Quaternion & SR_Quaternion::operator/=(float scalar)
	{
		DirectX::XMStoreFloat4(
			&m_quaternion,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				1.0f / scalar)));

		return *this;
	}

	const SR_Quaternion SR_Quaternion::operator-() const
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMVectorNegate(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)))));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::operator+(const SR_Quaternion & quaternion) const
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)))));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::operator+(float scalar) const
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))))));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::operator-(const SR_Quaternion & quaternion) const
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)))));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::operator-(float scalar) const
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))))));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::operator*(const SR_Quaternion & quaternion) const
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMQuaternionMultiply(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)))));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::operator*(float scalar) const
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				scalar)));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::operator/(const SR_Quaternion & quaternion) const
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMQuaternionMultiply(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				std::move(DirectX::XMQuaternionInverse(
					std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)))))));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::operator/(float scalar) const
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(&m_quaternion)),
				1.0f / scalar)));

		return std::move(quat);
	}

	float SR_Quaternion::Length(const SR_Quaternion & quaternion)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMQuaternionLength(
				std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)))));
	}

	float SR_Quaternion::LengthSquared(const SR_Quaternion & quaternion)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMQuaternionLengthSq(
				std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)))));
	}

	float SR_Quaternion::Dot(const SR_Quaternion & quaternion_1, const SR_Quaternion & quaternion_2)
	{
		return DirectX::XMVectorGetX(
			std::move(DirectX::XMQuaternionDot(
				std::move(DirectX::XMLoadFloat4(&quaternion_1.m_quaternion)),
				std::move(DirectX::XMLoadFloat4(&quaternion_2.m_quaternion)))));
	}

	const SR_Quaternion SR_Quaternion::Normalize(const SR_Quaternion & quaternion)
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMQuaternionNormalize(
				std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)))));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::Conjugate(const SR_Quaternion & quaternion)
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMQuaternionConjugate(
				std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)))));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::Inverse(const SR_Quaternion & quaternion)
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMQuaternionInverse(
				std::move(DirectX::XMLoadFloat4(&quaternion.m_quaternion)))));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::Concatenate(const SR_Quaternion & quaternion_1, const SR_Quaternion & quaternion_2)
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMQuaternionMultiply(
				std::move(DirectX::XMLoadFloat4(&quaternion_1.m_quaternion)),
				std::move(DirectX::XMLoadFloat4(&quaternion_2.m_quaternion)))));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::Lerp(const SR_Quaternion & position1, const SR_Quaternion & position2, float t)
	{
		DirectX::XMVECTOR v1{ DirectX::XMLoadFloat4(&position1.m_quaternion) };
		DirectX::XMVECTOR v2{ DirectX::XMLoadFloat4(&position2.m_quaternion) };
		DirectX::XMVECTOR r;

		if (DirectX::XMVector4GreaterOrEqual(
			std::move(DirectX::XMVector4Dot(v1, v2)),
			std::move(DirectX::XMVectorZero())))
		{
			r = std::move(DirectX::XMVectorLerp(v1, v2, t));
		}
		else
		{
			r = std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMVectorMultiply(
					v1,
					std::move(DirectX::XMVectorReplicate(1.0f - t)))),
				std::move(DirectX::XMVectorMultiply(
					v2,
					std::move(DirectX::XMVectorReplicate(t))))));
		}

		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMQuaternionNormalize(r)));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::Slerp(const SR_Quaternion & quaternion_1, const SR_Quaternion & quaternion_2, float t)
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMQuaternionSlerp(
				std::move(DirectX::XMLoadFloat4(&quaternion_1.m_quaternion)),
				std::move(DirectX::XMLoadFloat4(&quaternion_2.m_quaternion)),
				t)));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::AxisAngle(const DirectX::XMFLOAT3 & axis, float angle)
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMQuaternionRotationAxis(
				std::move(DirectX::XMLoadFloat3(&axis)),
				angle)));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::YawPitchRoll(float yaw, float pitch, float roll)
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMQuaternionRotationRollPitchYaw(pitch, yaw, roll)));

		return std::move(quat);
	}

	const SR_Quaternion SR_Quaternion::RotationMatrix(const DirectX::XMFLOAT4X4 & float4x4)
	{
		SR_Quaternion quat;

		DirectX::XMStoreFloat4(
			&quat.m_quaternion,
			std::move(DirectX::XMQuaternionRotationMatrix(
				std::move(DirectX::XMLoadFloat4x4(&float4x4)))));

		return std::move(quat);
	}

}