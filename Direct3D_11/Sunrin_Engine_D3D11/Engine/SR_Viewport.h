#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Viewport
	{
	public:
		constexpr explicit SR_Viewport() noexcept;
		constexpr explicit SR_Viewport(
			float topLeftX, float topLeftY,
			float width, float height,
			float minDepth, float maxDepth) noexcept;

		constexpr SR_Viewport(const SR_Viewport & viewport) noexcept;
		constexpr SR_Viewport(SR_Viewport && viewport) noexcept;

		~SR_Viewport() noexcept;

		bool operator==(const SR_Viewport & viewport) const noexcept;
		bool operator!=(const SR_Viewport & viewport) const noexcept;

		SR_Viewport & operator=(const SR_Viewport & viewport) noexcept;
		SR_Viewport & operator=(SR_Viewport && viewport) noexcept;

	public:
		static float AspectRatio(const SR_Viewport & viewport) noexcept;

		static const DirectX::XMFLOAT3 ProjectPosition(const SR_Viewport & viewport, const DirectX::XMFLOAT3 & position, const DirectX::XMFLOAT4X4 & worldMatrix, DirectX::XMFLOAT4X4 & viewMatrix, DirectX::XMFLOAT4X4 & projMatrix);

		static const DirectX::XMFLOAT3 UnprojectPosition(const SR_Viewport & viewport, const DirectX::XMFLOAT3 & position, const DirectX::XMFLOAT4X4 & worldMatrix, DirectX::XMFLOAT4X4 & viewMatrix, DirectX::XMFLOAT4X4 & projMatrix);

	public:
		union
		{
			struct
			{
				float m_topLeftX;
				float m_topLeftY;
				float m_width;
				float m_height;
				float m_minDepth;
				float m_maxDepth;

			};

			D3D11_VIEWPORT m_viewport;

		};

	};

}