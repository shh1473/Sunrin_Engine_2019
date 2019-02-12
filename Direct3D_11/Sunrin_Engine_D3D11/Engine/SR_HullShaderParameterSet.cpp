#include "SR_PCH.h"

#include "SR_HullShaderParameterSet.h"
#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_HullShaderParameterSet::SR_HullShaderParameterSet(
		SR_Component * owner,
		unsigned classInstanceSlotCount,
		unsigned constantBufferSlotCount,
		unsigned shaderResourceViewSlotCount,
		unsigned samplerStateSlotCount) :
		SR_CommonShaderParameterSet(classInstanceSlotCount, constantBufferSlotCount, shaderResourceViewSlotCount, samplerStateSlotCount),
		m_owner			{ owner },
		m_hullShader	{ nullptr }
	{

	}

	void SR_HullShaderParameterSet::Apply(unsigned contextIndex)
	{
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetHullShaderStage().SetHullShader(m_hullShader);
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetHullShaderStage().SetClassInstances(GetClassInstanceCount(), GetClassInstances());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetHullShaderStage().SetConstantBuffers(GetConstantBufferStartSlot(), GetConstantBufferCount(), GetConstantBuffers());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetHullShaderStage().SetShaderResourceViews(GetShaderResourceViewStartSlot(), GetShaderResourceViewCount(), GetShaderResourceViews());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetHullShaderStage().SetSamplerStates(GetSamplerStateStartSlot(), GetSamplerStateCount(), GetSamplerStates());
	}

}