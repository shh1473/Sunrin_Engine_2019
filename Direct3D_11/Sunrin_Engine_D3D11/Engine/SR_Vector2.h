#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Vector2
	{
	public:
		explicit SR_Vector2() noexcept;
		explicit SR_Vector2(float x, float y) noexcept;

		SR_Vector2(const SR_Vector2 & vector2) noexcept;
		SR_Vector2(SR_Vector2 && vector2) noexcept;
		SR_Vector2(const DirectX::XMFLOAT2 & float2) noexcept;
		SR_Vector2(DirectX::XMFLOAT2 && float2) noexcept;

		bool operator==(const SR_Vector2 & vector2) const;
		bool operator!=(const SR_Vector2 & vector2) const;

		SR_Vector2 & operator=(const SR_Vector2 & vector2) noexcept;
		SR_Vector2 & operator=(SR_Vector2 && vector2) noexcept;
		SR_Vector2 & operator+=(const SR_Vector2 & vector2);
		SR_Vector2 & operator+=(float scalar);
		SR_Vector2 & operator-=(const SR_Vector2 & vector2);
		SR_Vector2 & operator-=(float scalar);
		SR_Vector2 & operator*=(const SR_Vector2 & vector2);
		SR_Vector2 & operator*=(float scalar);
		SR_Vector2 & operator/=(const SR_Vector2 & vector2);
		SR_Vector2 & operator/=(float scalar);

		const SR_Vector2 operator-() const;
		const SR_Vector2 operator+(const SR_Vector2 & vector2) const;
		const SR_Vector2 operator+(float scalar) const;
		const SR_Vector2 operator-(const SR_Vector2 & vector2) const;
		const SR_Vector2 operator-(float scalar) const;
		const SR_Vector2 operator*(const SR_Vector2 & vector2) const;
		const SR_Vector2 operator*(float scalar) const;
		const SR_Vector2 operator/(const SR_Vector2 & vector2) const;
		const SR_Vector2 operator/(float scalar) const;

	public:
		static bool InBounds(const SR_Vector2 & vector2, const SR_Vector2 & bounds);

		static float Length(const SR_Vector2 & vector2);

		static float LengthSquared(const SR_Vector2 & vector2);

		static float Distance(const SR_Vector2 & position_1, const SR_Vector2 & position_2);

		static float DistanceSquared(const SR_Vector2 & position_1, const SR_Vector2 & position_2);

		static float Dot(const SR_Vector2 & vector2_1, const SR_Vector2 & vector2_2);

		static const SR_Vector2 Cross(const SR_Vector2 & vector2_1, const SR_Vector2 & vector2_2);

		static const SR_Vector2 Normalize(const SR_Vector2 & vector2);

		static const SR_Vector2 Clamp(const SR_Vector2 & vector2, const SR_Vector2 & min, const SR_Vector2 & max);

		static const SR_Vector2 Min(const SR_Vector2 & vector2_1, const SR_Vector2 & vector2_2);

		static const SR_Vector2 Max(const SR_Vector2 & vector2_1, const SR_Vector2 & vector2_2);

		static const SR_Vector2 Lerp(const SR_Vector2 & position_1, const SR_Vector2 & position_2, float t);

		static const SR_Vector2 SmoothStep(const SR_Vector2 & position_1, const SR_Vector2 & position_2, float t);

		static const SR_Vector2 BaryCentric(const SR_Vector2 & position_1, const SR_Vector2 & position_2, const SR_Vector2 & position_3, float f, float g);

		static const SR_Vector2 CatmullRom(const SR_Vector2 & position_1, const SR_Vector2 & position_2, const SR_Vector2 & position_3, const SR_Vector2 & position_4, float t);

		static const SR_Vector2 Hermite(const SR_Vector2 & position_1, const SR_Vector2 & tangent_1, const SR_Vector2 & position_2, const SR_Vector2 & tangent_2, float t);

		static const SR_Vector2 Reflect(const SR_Vector2 & incident, const SR_Vector2 & normal);

		static const SR_Vector2 Refract(const SR_Vector2 & incident, const SR_Vector2 & normal, float refractionIndex);

		static const SR_Vector2 Rotate(const SR_Vector2 & rotation, const DirectX::XMFLOAT4 & quaternion);

		static const SR_Vector2 TransformCoord(const SR_Vector2 & vector2, const DirectX::XMFLOAT4X4 & matrix);

		static const SR_Vector2 TransformNormal(const SR_Vector2 & vector2, const DirectX::XMFLOAT4X4 & matrix);

	public:
		static const SR_Vector2 m_ZERO;
		static const SR_Vector2 m_ONE;
		static const SR_Vector2 m_UNIT_X;
		static const SR_Vector2 m_UNIT_Y;

		union
		{
			struct
			{
				float m_x;
				float m_y;

			};

			float m_array[2];

			DirectX::XMFLOAT2 m_float2;

		};

	};

}