#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Vector4
	{
	public:
		explicit SR_Vector4() noexcept;
		explicit SR_Vector4(float x, float y, float z, float w) noexcept;

		SR_Vector4(const SR_Vector4 & vector4) noexcept;
		SR_Vector4(SR_Vector4 && vector4) noexcept;
		SR_Vector4(const DirectX::XMFLOAT4 & float4) noexcept;
		SR_Vector4(DirectX::XMFLOAT4 && float4) noexcept;

		bool operator==(const SR_Vector4 & vector4) const;
		bool operator!=(const SR_Vector4 & vector4) const;

		SR_Vector4 & operator=(const SR_Vector4 & vector4) noexcept;
		SR_Vector4 & operator=(SR_Vector4 && vector4) noexcept;
		SR_Vector4 & operator+=(const SR_Vector4 & vector4);
		SR_Vector4 & operator+=(float scalar);
		SR_Vector4 & operator-=(const SR_Vector4 & vector4);
		SR_Vector4 & operator-=(float scalar);
		SR_Vector4 & operator*=(const SR_Vector4 & vector4);
		SR_Vector4 & operator*=(float scalar);
		SR_Vector4 & operator/=(const SR_Vector4 & vector4);
		SR_Vector4 & operator/=(float scalar);

		const SR_Vector4 operator-() const;
		const SR_Vector4 operator+(const SR_Vector4 & vector4) const;
		const SR_Vector4 operator+(float scalar) const;
		const SR_Vector4 operator-(const SR_Vector4 & vector4) const;
		const SR_Vector4 operator-(float scalar) const;
		const SR_Vector4 operator*(const SR_Vector4 & vector4) const;
		const SR_Vector4 operator*(float scalar) const;
		const SR_Vector4 operator/(const SR_Vector4 & vector4) const;
		const SR_Vector4 operator/(float scalar) const;

	public:
		static bool InBounds(const SR_Vector4 & vector4, const SR_Vector4 & bounds);

		static float Length(const SR_Vector4 & vector4);

		static float LengthSquared(const SR_Vector4 & vector4);

		static float Distance(const SR_Vector4 & position_1, const SR_Vector4 & position_2);

		static float DistanceSquared(const SR_Vector4 & position_1, const SR_Vector4 & position_2);

		static float Dot(const SR_Vector4 & vector4_1, const SR_Vector4 & vector4_2);

		static const SR_Vector4 Cross(const SR_Vector4 & vector4_1, const SR_Vector4 & vector4_2, const SR_Vector4 & vector4_3);

		static const SR_Vector4 Normalize(const SR_Vector4 & vector4);

		static const SR_Vector4 Clamp(const SR_Vector4 & vector4, const SR_Vector4 & min, const SR_Vector4 & max);

		static const SR_Vector4 Min(const SR_Vector4 & vector4_1, const SR_Vector4 & vector4_2);

		static const SR_Vector4 Max(const SR_Vector4 & vector4_1, const SR_Vector4 & vector4_2);

		static const SR_Vector4 Lerp(const SR_Vector4 & position_1, const SR_Vector4 & position_2, float t);

		static const SR_Vector4 SmoothStep(const SR_Vector4 & position_1, const SR_Vector4 & position_2, float t);

		static const SR_Vector4 BaryCentric(const SR_Vector4 & position_1, const SR_Vector4 & position_2, const SR_Vector4 & position_3, float f, float g);

		static const SR_Vector4 CatmullRom(const SR_Vector4 & position_1, const SR_Vector4 & position_2, const SR_Vector4 & position_3, const SR_Vector4 & position_4, float t);

		static const SR_Vector4 Hermite(const SR_Vector4 & position_1, const SR_Vector4 & tangent_1, const SR_Vector4 & position_2, const SR_Vector4 & tangent_2, float t);

		static const SR_Vector4 Reflect(const SR_Vector4 & incident, const SR_Vector4 & normal);

		static const SR_Vector4 Refract(const SR_Vector4 & incident, const SR_Vector4 & normal, float refractionIndex);

		static const SR_Vector4 Rotate(const SR_Vector4 & rotation, const DirectX::XMFLOAT4 & quaternion);

		static const SR_Vector4 Transform(const SR_Vector4 & vector4, const DirectX::XMFLOAT4X4 & float4x4);

	public:
		static const SR_Vector4 m_ZERO;
		static const SR_Vector4 m_ONE;
		static const SR_Vector4 m_UNIT_X;
		static const SR_Vector4 m_UNIT_Y;
		static const SR_Vector4 m_UNIT_Z;
		static const SR_Vector4 m_UNIT_W;

		union
		{
			struct
			{
				float m_x;
				float m_y;
				float m_z;
				float m_w;

			};

			float m_array[4];

			DirectX::XMFLOAT4 m_float4;

		};

	};

}