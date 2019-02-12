#include "SR_PCH.h"

#include "SR_ComputeShaderParameterSet.h"
#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_ComputeShaderParameterSet::SR_ComputeShaderParameterSet(
		SR_Component * owner,
		unsigned classInstanceSlotCount,
		unsigned constantBufferSlotCount,
		unsigned shaderResourceViewSlotCount,
		unsigned unorderedAccessViewSlotCount,
		unsigned samplerStateSlotCount) :
		SR_CommonShaderParameterSet(classInstanceSlotCount, constantBufferSlotCount, shaderResourceViewSlotCount, samplerStateSlotCount),
		m_owner								{ owner },
		m_isBindUnorderedAccessView			{ false },
		m_computeShader						{ nullptr },
		m_unorderedAccessViewStartSlot		{ 0 },
		m_unorderedAccessViewCount			{ 0 },
		m_unorderedAccessViews				{},
		m_unorderedAccessViewInitialCounts	{}
	{
		m_unorderedAccessViews.assign(unorderedAccessViewSlotCount, nullptr);
	}

	void SR_ComputeShaderParameterSet::Apply(unsigned contextIndex)
	{
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetComputeShaderStage().SetComputeShader(m_computeShader);
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetComputeShaderStage().SetClassInstances(GetClassInstanceCount(), GetClassInstances());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetComputeShaderStage().SetConstantBuffers(GetConstantBufferStartSlot(), GetConstantBufferCount(), GetConstantBuffers());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetComputeShaderStage().SetShaderResourceViews(GetShaderResourceViewStartSlot(), GetShaderResourceViewCount(), GetShaderResourceViews());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetComputeShaderStage().SetSamplerStates(GetSamplerStateStartSlot(), GetSamplerStateCount(), GetSamplerStates());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetComputeShaderStage().SetUnorderedAccessViews(m_unorderedAccessViewStartSlot, m_unorderedAccessViewCount, m_unorderedAccessViews, m_unorderedAccessViewInitialCounts);
	}

}