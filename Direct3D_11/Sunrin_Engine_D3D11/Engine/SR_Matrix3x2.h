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
			DirectX::XMFLOAT2 r1,
			DirectX::XMFLOAT2 r2,
			DirectX::XMFLOAT2 r3) noexcept;

		SR_Matrix3x2(const SR_Matrix3x2 & matrix3x2) noexcept;
		SR_Matrix3x2(SR_Matrix3x2 && matrix3x2) noexcept;
		SR_Matrix3x2(const D2D1::Matrix3x2F & float3x2) noexcept;
		SR_Matrix3x2(D2D1::Matrix3x2F && float3x2) noexcept;

		~SR_Matrix3x2() noexcept;

		bool operator==(const SR_Matrix3x2& matrix3x2) const noexcept;
		bool operator!=(const SR_Matrix3x2& matrix3x2) const noexcept;

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
		static const SR_Matrix3x2 CreateTranslationMatrix(float x, float y);

		static const SR_Matrix3x2 CreateRotationMatrix(float angle, float centerX, float centerY);

		static const SR_Matrix3x2 CreateScaleMatrix(float x, float y, float centerX, float centerY);

		static const SR_Matrix3x2 CreateSkewMatrix(float x, float y, float centerX, float centerY);

	public:
		static const SR_Matrix3x2 M_Identity;

		union
		{
			struct
			{
				float m_11, m_12;
				float m_21, m_22;
				float m_31, m_32;

			};

			D2D1::Matrix3x2F m_float3x2;

		};

	};

}