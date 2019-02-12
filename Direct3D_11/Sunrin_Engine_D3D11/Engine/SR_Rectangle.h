#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Rectangle
	{
	public:
		explicit SR_Rectangle() noexcept;
		explicit SR_Rectangle(long left, long top, long right, long bottom) noexcept;

		SR_Rectangle(const SR_Rectangle & rectangle) noexcept;
		SR_Rectangle(SR_Rectangle && rectangle) noexcept;
		SR_Rectangle(const D3D11_RECT & rect) noexcept;
		SR_Rectangle(D3D11_RECT && rect) noexcept;

		bool operator==(const SR_Rectangle & rectangle) const noexcept;
		bool operator!=(const SR_Rectangle & rectangle) const noexcept;

		constexpr SR_Rectangle & operator=(const SR_Rectangle & rectangle) noexcept;
		constexpr SR_Rectangle & operator=(SR_Rectangle && rectangle) noexcept;

		constexpr void Add(long horizontal, long vertical) noexcept;
		constexpr void Inflate(long horizontal, long vertical) noexcept;

	public:
		static bool IsEmpty(const SR_Rectangle & rectangle) noexcept;

		static constexpr unsigned CenterX(const SR_Rectangle & rectangle) noexcept;

		static constexpr unsigned CenterY(const SR_Rectangle & rectangle) noexcept;

		static constexpr bool Contains(const SR_Rectangle & rectangle, long x, long y) noexcept;

		static constexpr bool Contains(const SR_Rectangle & rectangle_1, const SR_Rectangle & rectangle_2) noexcept;

		static constexpr bool Intersect(const SR_Rectangle & rectangle_1, const SR_Rectangle & rectangle_2) noexcept;

		static const SR_Rectangle IntersectSection(const SR_Rectangle & rectangle_1, const SR_Rectangle & rectangle_2) noexcept;

		static const SR_Rectangle Union(const SR_Rectangle & rectangle_1, const SR_Rectangle & rectangle_2) noexcept;

	public:
		static const SR_Rectangle M_Zero;

		union
		{
			struct
			{
				long m_left;
				long m_top;
				long m_right;
				long m_bottom;

			};

			D3D11_RECT m_rect;

		};

	};

}