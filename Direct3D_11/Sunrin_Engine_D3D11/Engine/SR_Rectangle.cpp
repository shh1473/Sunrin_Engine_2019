#include "SR_PCH.h"
#include "SR_Rectangle.h"

namespace SunrinEngine
{

	const SR_Rectangle SR_Rectangle::M_Zero{ 0L, 0L, 0L, 0L };

	constexpr SR_Rectangle::SR_Rectangle() noexcept :
		m_rect{}
	{

	}

	constexpr SR_Rectangle::SR_Rectangle(long left, long top, long right, long bottom) noexcept :
		m_rect{ std::move(left), std::move(top), std::move(right), std::move(bottom) }
	{

	}

	constexpr SR_Rectangle::SR_Rectangle(const SR_Rectangle & rectangle) noexcept :
		m_rect{ rectangle.m_rect }
	{

	}

	constexpr SR_Rectangle::SR_Rectangle(SR_Rectangle && rectangle) noexcept :
		m_rect{ std::move(rectangle.m_rect) }
	{

	}

	constexpr SR_Rectangle::SR_Rectangle(const D3D11_RECT & rect) noexcept :
		m_rect{ rect }
	{

	}

	constexpr SR_Rectangle::SR_Rectangle(D3D11_RECT && rect) noexcept :
		m_rect{ std::move(rect) }
	{

	}

	SR_Rectangle::~SR_Rectangle() noexcept
	{

	}

	bool SR_Rectangle::operator==(const SR_Rectangle & rectangle) const noexcept
	{
		return m_rect == rectangle.m_rect;
	}

	bool SR_Rectangle::operator!=(const SR_Rectangle & rectangle) const noexcept
	{
		return m_rect != rectangle.m_rect;
	}

	constexpr SR_Rectangle & SR_Rectangle::operator=(const SR_Rectangle & rectangle) noexcept
	{
		m_rect = rectangle.m_rect;

		return *this;
	}

	constexpr SR_Rectangle & SR_Rectangle::operator=(SR_Rectangle && rectangle) noexcept
	{
		m_rect = std::move(rectangle.m_rect);

		return *this;
	}

	constexpr void SR_Rectangle::Add(long horizontal, long vertical) noexcept
	{
		m_rect.left += horizontal;
		m_rect.top += vertical;
		m_rect.right += horizontal;
		m_rect.bottom += vertical;
	}

	constexpr void SR_Rectangle::Inflate(long horizontal, long vertical) noexcept
	{
		m_rect.left -= horizontal;
		m_rect.top -= vertical;
		m_rect.right += horizontal;
		m_rect.bottom += vertical;
	}

	bool SR_Rectangle::IsEmpty(const SR_Rectangle & rectangle) noexcept
	{
		return rectangle.m_rect == M_Zero.m_rect;
	}

	constexpr unsigned SR_Rectangle::CenterX(const SR_Rectangle & rectangle) noexcept
	{
		return rectangle.m_rect.left + ((rectangle.m_rect.right - rectangle.m_rect.left) / 2);
	}

	constexpr unsigned SR_Rectangle::CenterY(const SR_Rectangle & rectangle) noexcept
	{
		return rectangle.m_rect.top + ((rectangle.m_rect.bottom - rectangle.m_rect.top) / 2);
	}

	constexpr bool SR_Rectangle::Contains(const SR_Rectangle & rectangle, long x, long y) noexcept
	{
		return
			(x > rectangle.m_rect.left && x < rectangle.m_rect.right) &&
			(y > rectangle.m_rect.top && y < rectangle.m_rect.bottom);
	}

	constexpr bool SR_Rectangle::Contains(const SR_Rectangle & rectangle_1, const SR_Rectangle & rectangle_2) noexcept
	{
		return
			(rectangle_1.m_rect.left < rectangle_2.m_rect.left && rectangle_1.m_rect.right > rectangle_2.m_rect.right) &&
			(rectangle_1.m_rect.top < rectangle_2.m_rect.top && rectangle_1.m_rect.bottom > rectangle_2.m_rect.bottom);
	}

	constexpr bool SR_Rectangle::Intersect(const SR_Rectangle & rectangle_1, const SR_Rectangle & rectangle_2) noexcept
	{
		return
			(rectangle_1.m_rect.left < rectangle_2.m_rect.right) &&
			(rectangle_1.m_rect.top < rectangle_2.m_rect.bottom) &&
			(rectangle_1.m_rect.right > rectangle_2.m_rect.left) &&
			(rectangle_1.m_rect.bottom > rectangle_2.m_rect.top);
	}

	const SR_Rectangle SR_Rectangle::IntersectSection(const SR_Rectangle & rectangle_1, const SR_Rectangle & rectangle_2) noexcept
	{
		long maxLeft{ (rectangle_1.m_rect.left > rectangle_2.m_rect.left) ? rectangle_1.m_rect.left : rectangle_2.m_rect.left };
		long maxTop{ (rectangle_1.m_rect.top > rectangle_2.m_rect.top) ? rectangle_1.m_rect.top : rectangle_2.m_rect.top };
		long minRight{ (rectangle_1.m_rect.right < rectangle_2.m_rect.right) ? rectangle_1.m_rect.right : rectangle_2.m_rect.right };
		long minBottom{ (rectangle_1.m_rect.bottom < rectangle_2.m_rect.bottom) ? rectangle_1.m_rect.bottom : rectangle_2.m_rect.bottom };

		if (maxLeft < minRight && maxTop < minBottom)
		{
			return std::move(SR_Rectangle(maxLeft, maxTop, minRight, minBottom));
		}
		else
		{
			return std::move(SR_Rectangle(0L, 0L, 0L, 0L));
		}
	}

	const SR_Rectangle SR_Rectangle::Union(const SR_Rectangle & rectangle_1, const SR_Rectangle & rectangle_2) noexcept
	{
		return std::move(SR_Rectangle(
			(rectangle_1.m_rect.left < rectangle_2.m_rect.left) ? rectangle_1.m_rect.left : rectangle_2.m_rect.left,
			(rectangle_1.m_rect.top < rectangle_2.m_rect.top) ? rectangle_1.m_rect.top : rectangle_2.m_rect.top,
			(rectangle_1.m_rect.right > rectangle_2.m_rect.right) ? rectangle_1.m_rect.right : rectangle_2.m_rect.right,
			(rectangle_1.m_rect.bottom > rectangle_2.m_rect.bottom) ? rectangle_1.m_rect.bottom : rectangle_2.m_rect.bottom));
	}

}