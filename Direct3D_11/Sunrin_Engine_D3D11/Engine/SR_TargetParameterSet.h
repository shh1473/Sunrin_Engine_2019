#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_UIComponent;

	class SR_TargetParameterSet : public SR_NonCopyable
	{
	public:
		explicit SR_TargetParameterSet(SR_UIComponent * owner);

		void Apply();

		void SetIsBindTargetBitmap(bool isBindTargetBitmap) noexcept { m_isBindTargetBitmap = isBindTargetBitmap; }
		void SetIsBindPrimitiveBlend(bool isBindPrimitiveBlend) noexcept { m_isBindPrimitiveBlend = isBindPrimitiveBlend; }
		void SetIsBindRenderingControls(bool isBindRenderingControls) noexcept { m_isBindRenderingControls = isBindRenderingControls; }
		void SetIsBindUnitMode(bool isBindUnitMode) noexcept { m_isBindUnitMode = isBindUnitMode; }
		void SetTargetBitmap(ID2D1Bitmap1 * targetBitmap) noexcept { m_targetBitmap = targetBitmap; }
		void SetPrimitiveBlend(D2D1_PRIMITIVE_BLEND primitiveBlend) noexcept { m_primitiveBlend = primitiveBlend; }
		void SetRenderingControls(D2D1_RENDERING_CONTROLS renderingControls) noexcept { m_renderingControls = renderingControls; }
		void SetUnitMode(D2D1_UNIT_MODE unitMode) noexcept { m_unitMode = unitMode; }
		void SetClearColor(const D2D1::ColorF & clearColor) noexcept { m_clearColor = clearColor; }

		bool GetIsBindTargetBitmap() const noexcept { return m_isBindTargetBitmap; }
		bool GetIsBindPrimitiveBlend() const noexcept { return m_isBindPrimitiveBlend; }
		bool GetIsBindRenderingControls() const noexcept { return m_isBindRenderingControls; }
		bool GetIsBindUnitMode() const noexcept { return m_isBindUnitMode; }

	public:
		SR_UIComponent * m_owner;
		bool m_isBindTargetBitmap;
		bool m_isBindPrimitiveBlend;
		bool m_isBindRenderingControls;
		bool m_isBindUnitMode;
		ID2D1Bitmap1 * m_targetBitmap;
		D2D1_PRIMITIVE_BLEND m_primitiveBlend;
		D2D1_RENDERING_CONTROLS m_renderingControls;
		D2D1_UNIT_MODE m_unitMode;
		D2D1::ColorF m_clearColor;

	};

}