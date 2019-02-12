#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Ray
	{
	public:
		explicit SR_Ray() noexcept;
		explicit SR_Ray(
			float x, float y, float z,
			float dx, float dy, float dz) noexcept;
		explicit SR_Ray(
			const DirectX::XMFLOAT3 & position,
			const DirectX::XMFLOAT3 & direction) noexcept;

		SR_Ray(const SR_Ray & ray) noexcept;
		SR_Ray(SR_Ray && ray) noexcept;

		bool operator==(const SR_Ray & ray) const;
		bool operator!=(const SR_Ray & ray) const;

		SR_Ray & operator=(const SR_Ray & ray) noexcept;
		SR_Ray & operator=(SR_Ray && ray) noexcept;

	public:
		static bool Intersect(const SR_Ray & ray, const DirectX::BoundingSphere & sphere, float * distance);

		static bool Intersect(const SR_Ray & ray, const DirectX::BoundingBox & box, float * distance);

		static bool Intersect(const SR_Ray & ray, const DirectX::XMFLOAT3 & vertex_1, const DirectX::XMFLOAT3 & vertex_2, const DirectX::XMFLOAT3 & vertex_3, float * distance);

		static bool Intersect(const SR_Ray & ray, const DirectX::XMFLOAT4 & plane, float * distance);

	public:
		union
		{
			struct
			{
				float m_x;
				float m_y;
				float m_z;

				float m_dx;
				float m_dy;
				float m_dz;

			};

			struct
			{
				DirectX::XMFLOAT3 m_position;
				DirectX::XMFLOAT3 m_direction;

			};

		};

	};

}