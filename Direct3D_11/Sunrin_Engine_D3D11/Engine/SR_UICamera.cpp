#include "SR_PCH.h"

#include "SR_UICamera.h"
#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_UICamera::SR_UICamera(SR_UI * owner) :
		SR_UIComponent(owner),
		m_targetParameterSet{ nullptr }
	{
		owner->GetGameScene()->GetRenderExecutor().AddUICamera(this);
	}

	SR_UICamera::~SR_UICamera()
	{
		GetOwner()->GetGameScene()->GetRenderExecutor().RemoveUICamera(this);
	}

	void SR_UICamera::Ready()
	{
		m_targetParameterSet->Apply();

		GetOwner()->GetGameScene()->GetRenderExecutor().GetTargetStage().Apply(
			m_targetParameterSet->GetIsBindTargetBitmap(),
			m_targetParameterSet->GetIsBindPrimitiveBlend(),
			m_targetParameterSet->GetIsBindRenderingControls(),
			m_targetParameterSet->GetIsBindUnitMode());

		GetOwner()->GetGameScene()->GetRenderExecutor().GetTargetStage().ClearView();
	}

}