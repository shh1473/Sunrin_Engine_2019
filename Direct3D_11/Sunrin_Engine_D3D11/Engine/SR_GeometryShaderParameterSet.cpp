#include "SR_PCH.h"

#include "SR_GeometryShaderParameterSet.h"
#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_GeometryShaderParameterSet::SR_GeometryShaderParameterSet(
		SR_Component * owner,
		unsigned classInstanceSlotCount,
		unsigned constantBufferSlotCount,
		unsigned shaderResourceViewSlotCount,
		unsigned samplerStateSlotCount) :
		SR_CommonShaderParameterSet(classInstanceSlotCount, constantBufferSlotCount, shaderResourceViewSlotCount, samplerStateSlotCount),
		m_owner				{ owner },
		m_geometryShader	{ nullptr }
	{

	}

	void SR_GeometryShaderParameterSet::Apply(unsigned contextIndex)
	{
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetGeometryShaderStage().SetGeometryShader(m_geometryShader);
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetGeometryShaderStage().SetClassInstances(GetClassInstanceCount(), GetClassInstances());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetGeometryShaderStage().SetConstantBuffers(GetConstantBufferStartSlot(), GetConstantBufferCount(), GetConstantBuffers());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetGeometryShaderStage().SetShaderResourceViews(GetShaderResourceViewStartSlot(), GetShaderResourceViewCount(), GetShaderResourceViews());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetGeometryShaderStage().SetSamplerStates(GetSamplerStateStartSlot(), GetSamplerStateCount(), GetSamplerStates());
	}

}