#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Matrix3x2
	{
	public:
		explicit SR_Matrix3x2() noexcept;
		explicit SR_Matrix3x2(
			float m11, float m12,
			float m21, float m22,
			float m31, float m32) noexcept;
		explicit SR_Matrix3x2(
			D2D1_VECTOR_2F r1,
			D2D1_VECTOR_2F r2,
			D2D1_VECTOR_2F r3) noexcept;

		SR_Matrix3x2(const SR_Matrix3x2 & matrix3x2) noexcept;
		SR_Matrix3x2(SR_Matrix3x2 && matrix3x2) noexcept;
		SR_Matrix3x2(const D2D1::Matrix3x2F & float3x2) noexcept;
		SR_Matrix3x2(D2D1::Matrix3x2F && float3x2) noexcept;

		bool operator==(const SR_Matrix3x2 & matrix3x2) const noexcept;
		bool operator!=(const SR_Matrix3x2 & matrix3x2) const noexcept;

		SR_Matrix3x2 & operator=(const SR_Matrix3x2 & matrix3x2) noexcept;
		SR_Matrix3x2 & operator=(SR_Matrix3x2 && matrix3x2) noexcept;
		SR_Matrix3x2 & operator+=(const SR_Matrix3x2 & matrix3x2) noexcept;
		SR_Matrix3x2 & operator+=(float scalar) noexcept;
		SR_Matrix3x2 & operator-=(const SR_Matrix3x2 & matrix3x2) noexcept;
		SR_Matrix3x2 & operator-=(float scalar) noexcept;
		SR_Matrix3x2 & operator*=(const SR_Matrix3x2 & matrix3x2) noexcept;
		SR_Matrix3x2 & operator*=(float scalar) noexcept;
		SR_Matrix3x2 & operator/=(const SR_Matrix3x2 & matrix3x2) noexcept;
		SR_Matrix3x2 & operator/=(float scalar) noexcept;

		const SR_Matrix3x2 operator-() const noexcept;
		const SR_Matrix3x2 operator+(const SR_Matrix3x2 & matrix3x2) noexcept;
		const SR_Matrix3x2 operator+(float scalar) noexcept;
		const SR_Matrix3x2 operator-(const SR_Matrix3x2 & matrix3x2) noexcept;
		const SR_Matrix3x2 operator-(float scalar) noexcept;
		const SR_Matrix3x2 operator*(const SR_Matrix3x2 & matrix3x2) noexcept;
		const SR_Matrix3x2 operator*(float scalar) noexcept;
		const SR_Matrix3x2 operator/(const SR_Matrix3x2 & matrix3x2) noexcept;
		const SR_Matrix3x2 operator/(float scalar) noexcept;

		void Inverse();

		float GetDeterminant() const;

		const SR_Matrix3x2 GetInverse() const;

	public:
		static const SR_Matrix3x2 CreateTranslationMatrix(const DirectX::XMFLOAT2 & position);

		static const SR_Matrix3x2 CreateRotationMatrix(float rotation, const DirectX::XMFLOAT2 & rotationCenter);

		static const SR_Matrix3x2 CreateScaleMatrix(const DirectX::XMFLOAT2 & scale, const DirectX::XMFLOAT2 & scaleCenter);

		static const SR_Matrix3x2 CreateSkewMatrix(const DirectX::XMFLOAT2 & skew, const DirectX::XMFLOAT2 & skewCenter);

	public:
		static const SR_Matrix3x2 m_IDENTITY;

		union
		{
			struct
			{
				float m_11, m_12;
				float m_21, m_22;
				float m_31, m_32;

			};

			float m_array[3][2];

			D2D1::Matrix3x2F m_float3x2;

		};

	};

}