#include "SR_PCH.h"

#include "SR_TargetParameterSet.h"
#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_TargetParameterSet::SR_TargetParameterSet(SR_UIComponent * owner) :
		m_owner				{ owner },
		m_targetBitmap		{ nullptr },
		m_primitiveBlend	{ D2D1_PRIMITIVE_BLEND_ADD },
		m_renderingControls	{},
		m_unitMode			{ D2D1_UNIT_MODE_PIXELS },
		m_clearColor		{ 0.0f, 0.0f, 1.0f, 1.0f }
	{

	}

	void SR_TargetParameterSet::Apply()
	{
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetTargetStage().SetTargetImage(m_targetBitmap);
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetTargetStage().SetPrimitiveBlend(m_primitiveBlend);
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetTargetStage().SetRenderingControls(m_renderingControls);
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetTargetStage().SetUnitMode(m_unitMode);
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetTargetStage().SetClearColor(m_clearColor);
	}

}