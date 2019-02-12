#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_TargetStage : public SR_NonCopyable
	{
	public:
		explicit SR_TargetStage();

		void Apply(bool isBindTarget, bool isBindPrimitiveBlend, bool isBindRenderingControls, bool isBindUnitMode);
		void ClearView();

		void SetTargetImage(ID2D1Image * targetImage) noexcept { m_targetImage = targetImage; }
		void SetPrimitiveBlend(D2D1_PRIMITIVE_BLEND primitiveBlend) noexcept { m_primitiveBlend = primitiveBlend; }
		void SetRenderingControls(D2D1_RENDERING_CONTROLS renderingControls) noexcept { m_renderingControls = renderingControls; }
		void SetUnitMode(D2D1_UNIT_MODE unitMode) noexcept { m_unitMode = unitMode; }
		void SetClearColor(const D2D1_COLOR_F & clearColor) noexcept { m_clearColor = clearColor; }

	public:
		ID2D1Image * m_targetImage;
		D2D1_PRIMITIVE_BLEND m_primitiveBlend;
		D2D1_RENDERING_CONTROLS m_renderingControls;
		D2D1_UNIT_MODE m_unitMode;
		D2D1_COLOR_F m_clearColor;


	};

}