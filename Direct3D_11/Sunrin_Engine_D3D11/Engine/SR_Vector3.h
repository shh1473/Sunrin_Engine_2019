#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Vector3
	{
	public:
		constexpr explicit SR_Vector3() noexcept;
		constexpr explicit SR_Vector3(float x, float y, float z) noexcept;

		constexpr SR_Vector3(const SR_Vector3 & vector3) noexcept;
		constexpr SR_Vector3(SR_Vector3 && vector3) noexcept;
		constexpr SR_Vector3(const DirectX::XMFLOAT3 & float3) noexcept;
		constexpr SR_Vector3(DirectX::XMFLOAT3 && float3) noexcept;

		~SR_Vector3() noexcept;

		bool operator==(const SR_Vector3 & vector3) const;
		bool operator!=(const SR_Vector3 & vector3) const;

		SR_Vector3 & operator=(const SR_Vector3 & vector3) noexcept;
		SR_Vector3 & operator=(SR_Vector3 && vector3) noexcept;
		SR_Vector3 & operator+=(const SR_Vector3 & vector3);
		SR_Vector3 & operator+=(float scalar);
		SR_Vector3 & operator-=(const SR_Vector3 & vector3);
		SR_Vector3 & operator-=(float scalar);
		SR_Vector3 & operator*=(const SR_Vector3 & vector3);
		SR_Vector3 & operator*=(float scalar);
		SR_Vector3 & operator/=(const SR_Vector3 & vector3);
		SR_Vector3 & operator/=(float scalar);

		const SR_Vector3 operator-() const;
		const SR_Vector3 operator+(const SR_Vector3 & vector3) const;
		const SR_Vector3 operator+(float scalar) const;
		const SR_Vector3 operator-(const SR_Vector3 & vector3) const;
		const SR_Vector3 operator-(float scalar) const;
		const SR_Vector3 operator*(const SR_Vector3 & vector3) const;
		const SR_Vector3 operator*(float scalar) const;
		const SR_Vector3 operator/(const SR_Vector3 & vector3) const;
		const SR_Vector3 operator/(float scalar) const;

	public:
		static bool InBounds(const SR_Vector3 & vector3, const SR_Vector3 & bounds);

		static float Length(const SR_Vector3 & vector3);

		static float LengthSquared(const SR_Vector3 & vector3);

		static float Distance(const SR_Vector3 & position_1, const SR_Vector3 & position_2);

		static float DistanceSquared(const SR_Vector3 & position_1, const SR_Vector3 & position_2);

		static float Dot(const SR_Vector3 & vector3_1, const SR_Vector3 & vector3_2);

		static const SR_Vector3 Cross(const SR_Vector3 & vector3_1, const SR_Vector3 & vector3_2);

		static const SR_Vector3 Normalize(const SR_Vector3 & vector3);

		static const SR_Vector3 Clamp(const SR_Vector3 & vector3, const SR_Vector3 & min, const SR_Vector3 & max);

		static const SR_Vector3 Min(const SR_Vector3 & vector3_1, const SR_Vector3 & vector3_2);

		static const SR_Vector3 Max(const SR_Vector3 & vector3_1, const SR_Vector3 & vector3_2);

		static const SR_Vector3 Lerp(const SR_Vector3 & position_1, const SR_Vector3 & position_2, float t);

		static const SR_Vector3 SmoothStep(const SR_Vector3 & position_1, const SR_Vector3 & position_2, float t);

		static const SR_Vector3 BaryCentric(const SR_Vector3 & position_1, const SR_Vector3 & position_2, const SR_Vector3 & position_3, float f, float g);

		static const SR_Vector3 CatmullRom(const SR_Vector3 & position_1, const SR_Vector3 & position_2, const SR_Vector3 & position_3, const SR_Vector3 & position_4, float t);

		static const SR_Vector3 Hermite(const SR_Vector3 & position_1, const SR_Vector3 & tangent_1, const SR_Vector3 & position_2, const SR_Vector3 & tangent_2, float t);

		static const SR_Vector3 Reflect(const SR_Vector3 & incident, const SR_Vector3 & normal);

		static const SR_Vector3 Refract(const SR_Vector3 & incident, const SR_Vector3 & normal, float refractionIndex);

		static const SR_Vector3 Rotate(const SR_Vector3 & rotation, const DirectX::XMFLOAT4 & quaternion);

		static const SR_Vector3 TransformCoord(const SR_Vector3 & vector3, const DirectX::XMFLOAT4X4 & float4x4);

		static const SR_Vector3 TransformNormal(const SR_Vector3 & vector3, const DirectX::XMFLOAT4X4 & float4x4);

	public:
		static const SR_Vector3 M_Zero;
		static const SR_Vector3 M_One;
		static const SR_Vector3 M_UnitX;
		static const SR_Vector3 M_UnitY;
		static const SR_Vector3 M_UnitZ;
		static const SR_Vector3 M_Up;
		static const SR_Vector3 M_Down;
		static const SR_Vector3 M_Right;
		static const SR_Vector3 M_Left;
		static const SR_Vector3 M_Forward;
		static const SR_Vector3 M_Backward;

		union
		{
			struct
			{
				float m_x;
				float m_y;
				float m_z;

			};

			DirectX::XMFLOAT3 m_float3;

		};

	};

}