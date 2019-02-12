#include "SR_PCH.h"

#include "SR_UIRenderer.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_UIRenderer::SR_UIRenderer(SR_UI * owner) :
		SR_UIComponent(owner)
	{
		owner->GetGameScene()->GetRenderExecutor().AddUIRenderer(this);
	}

	SR_UIRenderer::~SR_UIRenderer()
	{
		GetOwner()->GetGameScene()->GetRenderExecutor().RemoveUIRenderer(this);
	}

	bool SR_UIRenderer::Update()
	{
		SR_RF_BOOL(m_technique->Update());

		return true;
	}

	bool SR_UIRenderer::Render()
	{
		SR_RF_BOOL(m_technique->Render());

		return true;
	}

}