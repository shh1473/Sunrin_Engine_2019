#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Color
	{
	public:
		explicit SR_Color() noexcept;
		explicit SR_Color(float r, float g, float b) noexcept;
		explicit SR_Color(float r, float g, float b, float a) noexcept;

		SR_Color(const SR_Color & color) noexcept;
		SR_Color(SR_Color && color) noexcept;
		SR_Color(const DirectX::XMFLOAT4 & float4) noexcept;
		SR_Color(DirectX::XMFLOAT4 && float4) noexcept;

		~SR_Color() noexcept;

		bool operator==(const SR_Color & color) const;
		bool operator!=(const SR_Color & color) const;

		SR_Color & operator=(const SR_Color & color) noexcept;
		SR_Color & operator=(SR_Color && color) noexcept;
		SR_Color & operator+=(const SR_Color & color);
		SR_Color & operator+=(float scalar);
		SR_Color & operator-=(const SR_Color & color);
		SR_Color & operator-=(float scalar);
		SR_Color & operator*=(const SR_Color & color);
		SR_Color & operator*=(float scalar);
		SR_Color & operator/=(const SR_Color & color);
		SR_Color & operator/=(float scalar);

		const SR_Color operator-() const;
		const SR_Color operator+(const SR_Color & color) const;
		const SR_Color operator+(float scalar) const;
		const SR_Color operator-(const SR_Color & color) const;
		const SR_Color operator-(float scalar) const;
		const SR_Color operator*(const SR_Color & color) const;
		const SR_Color operator*(float scalar) const;
		const SR_Color operator/(const SR_Color & color) const;
		const SR_Color operator/(float scalar) const;

	public:
		static const SR_Color Negative(const SR_Color & color);

		static const SR_Color Saturate(const SR_Color & color);

		static const SR_Color Premultiply(const SR_Color & color);

		static const SR_Color AdjustSaturation(const SR_Color & color, float sat);

		static const SR_Color AdjustContrast(const SR_Color & color, float con);

		static const SR_Color Modulate(const SR_Color & color_1, const SR_Color & color_2);

		static const SR_Color Lerp(const SR_Color & color_1, const SR_Color & color_2, float t);

	public:
		union
		{
			struct
			{
				float m_r;
				float m_g;
				float m_b;
				float m_a;

			};

			float m_array[4];

			DirectX::XMFLOAT4 m_color;

		};

	};

}