#include "SR_PCH.h"

#include "SR_VertexShaderParameterSet.h"
#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_VertexShaderParameterSet::SR_VertexShaderParameterSet(
		SR_Component * owner,
		unsigned classInstanceSlotCount,
		unsigned constantBufferSlotCount,
		unsigned shaderResourceViewSlotCount,
		unsigned samplerStateSlotCount) :
		SR_CommonShaderParameterSet(classInstanceSlotCount, constantBufferSlotCount, shaderResourceViewSlotCount, samplerStateSlotCount),
		m_owner				{ owner },
		m_isBindInputLayout	{ false },
		m_vertexShader		{ nullptr },
		m_inputLayout		{ nullptr }
	{

	}

	void SR_VertexShaderParameterSet::Apply(unsigned contextIndex)
	{
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetInputAssemblerStage().SetInputLayout(m_inputLayout);

		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetVertexShaderStage().SetVertexShader(m_vertexShader);
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetVertexShaderStage().SetClassInstances(GetClassInstanceCount(), GetClassInstances());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetVertexShaderStage().SetConstantBuffers(GetConstantBufferStartSlot(), GetConstantBufferCount(), GetConstantBuffers());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetVertexShaderStage().SetShaderResourceViews(GetShaderResourceViewStartSlot(), GetShaderResourceViewCount(), GetShaderResourceViews());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetVertexShaderStage().SetSamplerStates(GetSamplerStateStartSlot(), GetSamplerStateCount(), GetSamplerStates());
	}

}