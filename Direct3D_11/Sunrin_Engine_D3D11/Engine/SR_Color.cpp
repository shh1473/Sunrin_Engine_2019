#include "SR_PCH.h"

#include "SR_Color.h"

namespace SunrinEngine
{

	SR_Color::SR_Color() noexcept :
		m_color{ 0.0f, 0.0f, 0.0f, 1.0f }
	{

	}

	SR_Color::SR_Color(float r, float g, float b) noexcept :
		m_color{ r, g, b, 1.0f }
	{

	}

	SR_Color::SR_Color(float r, float g, float b, float a) noexcept :
		m_color{ r, g, b, a }
	{

	}

	SR_Color::SR_Color(const SR_Color & color) noexcept :
		m_color{ color.m_color }
	{

	}

	SR_Color::SR_Color(SR_Color && color) noexcept :
		m_color{ std::move(color.m_color) }
	{

	}

	SR_Color::SR_Color(const DirectX::XMFLOAT4 & float4) noexcept :
		m_color{ float4 }
	{

	}

	SR_Color::SR_Color(DirectX::XMFLOAT4 && float4) noexcept :
		m_color{ std::move(float4) }
	{

	}

	SR_Color::~SR_Color() noexcept
	{

	}

	bool SR_Color::operator==(const SR_Color & color) const
	{
		return DirectX::XMVector4Equal(
			std::move(DirectX::XMLoadFloat4(&m_color)),
			std::move(DirectX::XMLoadFloat4(&color.m_color)));
	}

	bool SR_Color::operator!=(const SR_Color & color) const
	{
		return DirectX::XMVector4NotEqual(
			std::move(DirectX::XMLoadFloat4(&m_color)),
			std::move(DirectX::XMLoadFloat4(&color.m_color)));
	}

	SR_Color & SR_Color::operator=(const SR_Color & color) noexcept
	{
		m_color = color.m_color;

		return *this;
	}

	SR_Color & SR_Color::operator=(SR_Color && color) noexcept
	{
		m_color = std::move(color.m_color);

		return *this;
	}

	SR_Color & SR_Color::operator+=(const SR_Color & color)
	{
		DirectX::XMStoreFloat4(
			&m_color,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				std::move(DirectX::XMLoadFloat4(&color.m_color)))));

		return *this;
	}

	SR_Color & SR_Color::operator+=(float scalar)
	{
		DirectX::XMStoreFloat4(
			&m_color,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))))));

		return *this;
	}

	SR_Color & SR_Color::operator-=(const SR_Color & color)
	{
		DirectX::XMStoreFloat4(
			&m_color,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				std::move(DirectX::XMLoadFloat4(&color.m_color)))));

		return *this;
	}

	SR_Color & SR_Color::operator-=(float scalar)
	{
		DirectX::XMStoreFloat4(
			&m_color,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))))));

		return *this;
	}

	SR_Color & SR_Color::operator*=(const SR_Color & color)
	{
		DirectX::XMStoreFloat4(
			&m_color,
			std::move(DirectX::XMVectorMultiply(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				std::move(DirectX::XMLoadFloat4(&color.m_color)))));

		return *this;
	}

	SR_Color & SR_Color::operator*=(float scalar)
	{
		DirectX::XMStoreFloat4(
			&m_color,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				scalar)));

		return *this;
	}

	SR_Color & SR_Color::operator/=(const SR_Color & color)
	{
		DirectX::XMStoreFloat4(
			&m_color,
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				std::move(DirectX::XMLoadFloat4(&color.m_color)))));

		return *this;
	}

	SR_Color & SR_Color::operator/=(float scalar)
	{
		DirectX::XMStoreFloat4(
			&m_color,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				1.0f / scalar)));

		return *this;
	}

	const SR_Color SR_Color::operator-() const
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMVectorNegate(
				std::move(DirectX::XMLoadFloat4(&m_color)))));

		return std::move(col);
	}

	const SR_Color SR_Color::operator+(const SR_Color & color) const
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				std::move(DirectX::XMLoadFloat4(&color.m_color)))));

		return std::move(col);
	}

	const SR_Color SR_Color::operator+(float scalar) const
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMVectorAdd(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))))));

		return std::move(col);
	}

	const SR_Color SR_Color::operator-(const SR_Color & color) const
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				std::move(DirectX::XMLoadFloat4(&color.m_color)))));

		return std::move(col);
	}

	const SR_Color SR_Color::operator-(float scalar) const
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMVectorSubtract(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				std::move(DirectX::XMLoadFloat4(&DirectX::XMFLOAT4(scalar, scalar, scalar, scalar))))));

		return std::move(col);
	}

	const SR_Color SR_Color::operator*(const SR_Color & color) const
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMVectorMultiply(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				std::move(DirectX::XMLoadFloat4(&color.m_color)))));

		return std::move(col);
	}

	const SR_Color SR_Color::operator*(float scalar) const
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				scalar)));

		return std::move(col);
	}

	const SR_Color SR_Color::operator/(const SR_Color & color) const
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMVectorDivide(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				std::move(DirectX::XMLoadFloat4(&color.m_color)))));

		return std::move(col);
	}

	const SR_Color SR_Color::operator/(float scalar) const
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMVectorScale(
				std::move(DirectX::XMLoadFloat4(&m_color)),
				1.0f / scalar)));

		return std::move(col);
	}

	const SR_Color SR_Color::Negative(const SR_Color & color)
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMColorNegative(
				std::move(DirectX::XMLoadFloat4(&color.m_color)))));

		return std::move(col);
	}

	const SR_Color SR_Color::Saturate(const SR_Color & color)
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMVectorSaturate(
				std::move(DirectX::XMLoadFloat4(&color.m_color)))));

		return std::move(col);
	}

	const SR_Color SR_Color::Premultiply(const SR_Color & color)
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMVectorMultiply(
				std::move(DirectX::XMLoadFloat4(&color.m_color)),
				std::move(DirectX::XMVectorSelect(
					DirectX::g_XMIdentityR3,
					std::move(DirectX::XMVectorSplatW(
						std::move(DirectX::XMLoadFloat4(&color.m_color)))),
					DirectX::g_XMSelect1110)))));

		return std::move(col);
	}

	const SR_Color SR_Color::AdjustSaturation(const SR_Color & color, float sat)
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMColorAdjustSaturation(
				std::move(DirectX::XMLoadFloat4(&color.m_color)),
				sat)));

		return std::move(col);
	}

	const SR_Color SR_Color::AdjustContrast(const SR_Color & color, float con)
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMColorAdjustContrast(
				std::move(DirectX::XMLoadFloat4(&color.m_color)),
				con)));

		return std::move(col);
	}

	const SR_Color SR_Color::Modulate(const SR_Color & color_1, const SR_Color & color_2)
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMColorModulate(
				std::move(DirectX::XMLoadFloat4(&color_1.m_color)),
				std::move(DirectX::XMLoadFloat4(&color_2.m_color)))));

		return std::move(col);
	}

	const SR_Color SR_Color::Lerp(const SR_Color & color_1, const SR_Color & color_2, float t)
	{
		SR_Color col;

		DirectX::XMStoreFloat4(
			&col.m_color,
			std::move(DirectX::XMVectorLerp(
				std::move(DirectX::XMLoadFloat4(&color_1.m_color)),
				std::move(DirectX::XMLoadFloat4(&color_2.m_color)),
				t)));

		return std::move(col);
	}

}