#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Quaternion
	{
	public:
		constexpr explicit SR_Quaternion() noexcept;
		constexpr explicit SR_Quaternion(float x, float y, float z, float w) noexcept;

		constexpr SR_Quaternion(const SR_Quaternion & quaternion) noexcept;
		constexpr SR_Quaternion(SR_Quaternion && quaternion) noexcept;
		constexpr SR_Quaternion(const DirectX::XMFLOAT4 & float4) noexcept;
		constexpr SR_Quaternion(DirectX::XMFLOAT4 && float4) noexcept;

		~SR_Quaternion() noexcept;

		bool operator==(const SR_Quaternion & quaternion) const;
		bool operator!=(const SR_Quaternion & quaternion) const;

		SR_Quaternion & operator=(const SR_Quaternion & quaternion) noexcept;
		SR_Quaternion & operator=(SR_Quaternion && quaternion) noexcept;
		SR_Quaternion & operator+=(const SR_Quaternion & quaternion);
		SR_Quaternion & operator+=(float scalar);
		SR_Quaternion & operator-=(const SR_Quaternion & quaternion);
		SR_Quaternion & operator-=(float scalar);
		SR_Quaternion & operator*=(const SR_Quaternion & quaternion);
		SR_Quaternion & operator*=(float scalar);
		SR_Quaternion & operator/=(const SR_Quaternion & quaternion);
		SR_Quaternion & operator/=(float scalar);

		const SR_Quaternion operator-() const;
		const SR_Quaternion operator+(const SR_Quaternion & quaternion) const;
		const SR_Quaternion operator+(float scalar) const;
		const SR_Quaternion operator-(const SR_Quaternion & quaternion) const;
		const SR_Quaternion operator-(float scalar) const;
		const SR_Quaternion operator*(const SR_Quaternion & quaternion) const;
		const SR_Quaternion operator*(float scalar) const;
		const SR_Quaternion operator/(const SR_Quaternion & quaternion) const;
		const SR_Quaternion operator/(float scalar) const;

	public:
		static float Length(const SR_Quaternion & quaternion);

		static float LengthSquared(const SR_Quaternion & quaternion);

		static float Dot(const SR_Quaternion & quaternion_1, const SR_Quaternion & quaternion_2);

		static const SR_Quaternion Normalize(const SR_Quaternion & quaternion);

		static const SR_Quaternion Conjugate(const SR_Quaternion & quaternion);

		static const SR_Quaternion Inverse(const SR_Quaternion & quaternion);

		static const SR_Quaternion Concatenate(const SR_Quaternion & quaternion_1, const SR_Quaternion & quaternion_2);

		static const SR_Quaternion Lerp(const SR_Quaternion & quaternion_1, const SR_Quaternion & quaternion_2, float t);

		static const SR_Quaternion Slerp(const SR_Quaternion & quaternion_1, const SR_Quaternion & quaternion_2, float t);

		static const SR_Quaternion AxisAngle(const DirectX::XMFLOAT3 & axis, float angle);

		static const SR_Quaternion YawPitchRoll(float yaw, float pitch, float roll);

		static const SR_Quaternion RotationMatrix(const DirectX::XMFLOAT4X4 & float4x4);

	public:
		static const SR_Quaternion M_Identity;

		union
		{
			struct
			{
				float m_x;
				float m_y;
				float m_z;
				float m_w;

			};
			
			DirectX::XMFLOAT4 m_quaternion;

		};

	};

}