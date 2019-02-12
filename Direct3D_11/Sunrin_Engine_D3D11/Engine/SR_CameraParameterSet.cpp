#include "SR_PCH.h"

#include "SR_CameraParameterSet.h"
#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_CameraParameterSet::SR_CameraParameterSet(
		SR_Component * owner,
		unsigned renderTargetViewSlotCount,
		unsigned viewportSlotCount,
		unsigned scissorRectSlotCount) :
		m_owner										{ owner },
		m_isBindRenderTargetViewAndDepthStencilView	{ false },
		m_isBindDepthStencilState					{ false },
		m_isBindBlendState							{ false },
		m_isBindRasterizerState						{ false },
		m_isBindViewport							{ false },
		m_isBindScissorRect							{ false },
		m_renderTargetViews							{},
		m_depthStencilView							{ nullptr },
		m_depthStencilState							{ nullptr },
		m_stencilRef								{ D3D11_DEFAULT_STENCIL_REFERENCE },
		m_blendState								{ nullptr },
		m_blendFactor								{ nullptr },
		m_blendSampleMask							{ D3D11_DEFAULT_SAMPLE_MASK },
		m_renderTargetViewClearColors				{},
		m_depthStencilClearFlag						{ D3D11_CLEAR_DEPTH },
		m_depthClearValue							{ 1.0f },
		m_stencilClearValue							{ 0 },
		m_rasterizerState							{ nullptr },
		m_viewportCount								{ 0 },
		m_viewports									{},
		m_scissorRectCount							{ 0 },
		m_scissorRects								{}
	{
		m_renderTargetViews.assign(renderTargetViewSlotCount, nullptr);
		m_viewports.assign(viewportSlotCount, nullptr);
		m_scissorRects.assign(scissorRectSlotCount, nullptr);
		m_renderTargetViewClearColors.assign(renderTargetViewSlotCount, nullptr);
	}

	void SR_CameraParameterSet::Apply()
	{
		for (unsigned i{ 0 }; i < SR_MAX_THREAD_COUNT; ++i)
		{
			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetOutputMergerStage().SetRenderTargetViews(m_renderTargetViewCount, m_renderTargetViews);
			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetOutputMergerStage().SetDepthStencilView(m_depthStencilView);
			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetOutputMergerStage().SetDepthStencilState(m_depthStencilState);
			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetOutputMergerStage().SetStencilRef(m_stencilRef);
			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetOutputMergerStage().SetBlendState(m_blendState);
			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetOutputMergerStage().SetBlendFactor(m_blendFactor);
			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetOutputMergerStage().SetBlendSampleMask(m_blendSampleMask);
			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetOutputMergerStage().SetRenderTargetViewClearColors(m_renderTargetViewClearColors);
			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetOutputMergerStage().SetDepthStencilClearFlag(m_depthStencilClearFlag);
			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetOutputMergerStage().SetDepthClearValue(m_depthClearValue);
			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetOutputMergerStage().SetStencilClearValue(m_stencilClearValue);

			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetRasterizerStage().SetRasterizerState(m_rasterizerState);
			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetRasterizerStage().SetViewports(m_viewportCount, m_viewports);
			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(i).GetRasterizerStage().SetScissorRects(m_scissorRectCount, m_scissorRects);
		}
	}

}