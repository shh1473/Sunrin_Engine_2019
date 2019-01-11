#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Plane
	{
	public:
		constexpr explicit SR_Plane() noexcept;
		constexpr explicit SR_Plane(float x, float y, float z, float w) noexcept;
		constexpr explicit SR_Plane(const DirectX::XMFLOAT3 & normal, float d) noexcept;
		explicit SR_Plane(const DirectX::XMFLOAT3 & point_1, const DirectX::XMFLOAT3 & point_2, const DirectX::XMFLOAT3 & point_3) noexcept;
		explicit SR_Plane(const DirectX::XMFLOAT3 & point, const DirectX::XMFLOAT3 & normal) noexcept;

		constexpr SR_Plane(const SR_Plane & plane) noexcept;
		constexpr SR_Plane(SR_Plane && plane) noexcept;
		constexpr SR_Plane(const DirectX::XMFLOAT4 & float4) noexcept;
		constexpr SR_Plane(DirectX::XMFLOAT4 && float4) noexcept;

		~SR_Plane() noexcept;

		bool operator==(const SR_Plane & plane) const;
		bool operator!=(const SR_Plane & plane) const;

		SR_Plane & operator=(const SR_Plane & plane) noexcept;
		SR_Plane & operator=(SR_Plane && plane) noexcept;

	public:
		static float Dot(const SR_Plane & plane_1, const SR_Plane & plane_2);

		static float DotCoord(const SR_Plane & plane, const DirectX::XMFLOAT3 & coord);

		static float DotNormal(const SR_Plane & plane, const DirectX::XMFLOAT3 & normal);

		static const SR_Plane Normalize(const SR_Plane & plane);

		static const SR_Plane Transform(const SR_Plane & plane, const DirectX::XMFLOAT4X4 & float4x4);

		static const SR_Plane Transform(const SR_Plane & plane, const DirectX::XMFLOAT4 & float4);

	public:
		union
		{
			struct
			{
				float m_x;
				float m_y;
				float m_z;
				float m_w;

			};

			DirectX::XMFLOAT4 m_plane;

		};

	};

}