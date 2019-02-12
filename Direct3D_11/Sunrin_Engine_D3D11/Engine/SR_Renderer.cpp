#include "SR_PCH.h"

#include "SR_Renderer.h"
#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_CommonRenderer::SR_CommonRenderer(SR_Entity * owner, unsigned threadID) :
		SR_Component(owner),
		m_threadID{ threadID }
	{

	}

	bool SR_CommonRenderer::Render()
	{
		SR_RF_BOOL(m_technique->Render(m_threadID));

		return true;
	}

	SR_ForwardRenderer::SR_ForwardRenderer(SR_Entity * owner) :
		SR_CommonRenderer(owner, owner->GetGameScene()->GetRenderExecutor().AddForwardRenderer(this))
	{

	}

	SR_ForwardRenderer::~SR_ForwardRenderer()
	{
		GetOwner()->GetGameScene()->GetRenderExecutor().RemoveForwardRenderer(this, GetThreadID());
	}

	SR_DeferredRenderer::SR_DeferredRenderer(SR_Entity * owner) :
		SR_CommonRenderer(owner, owner->GetGameScene()->GetRenderExecutor().AddDeferredRenderer(this))
	{

	}

	SR_DeferredRenderer::~SR_DeferredRenderer()
	{
		GetOwner()->GetGameScene()->GetRenderExecutor().RemoveDeferredRenderer(this, GetThreadID());
	}

	SR_PackingRenderer::SR_PackingRenderer(SR_Entity * owner) :
		SR_CommonRenderer(owner, owner->GetGameScene()->GetRenderExecutor().AddPackingRenderer(this))
	{

	}

	SR_PackingRenderer::~SR_PackingRenderer()
	{
		GetOwner()->GetGameScene()->GetRenderExecutor().RemovePackingRenderer(this, GetThreadID());
	}

	SR_ComputeRenderer::SR_ComputeRenderer(SR_Entity * owner) :
		SR_CommonRenderer(owner, owner->GetGameScene()->GetRenderExecutor().AddComputeRenderer(this))
	{

	}

	SR_ComputeRenderer::~SR_ComputeRenderer()
	{
		GetOwner()->GetGameScene()->GetRenderExecutor().RemoveComputeRenderer(this, GetThreadID());
	}

}