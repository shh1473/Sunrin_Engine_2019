#include "SR_PCH.h"

#include "SR_PixelShaderParameterSet.h"
#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_PixelShaderParameterSet::SR_PixelShaderParameterSet(
		SR_Component * owner,
		unsigned classInstanceSlotCount,
		unsigned constantBufferSlotCount,
		unsigned shaderResourceViewSlotCount,
		unsigned samplerStateSlotCount) :
		SR_CommonShaderParameterSet(classInstanceSlotCount, constantBufferSlotCount, shaderResourceViewSlotCount, samplerStateSlotCount),
		m_owner			{ owner },
		m_pixelShader	{ nullptr }
	{

	}

	void SR_PixelShaderParameterSet::Apply(unsigned contextIndex)
	{
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetPixelShaderStage().SetPixelShader(m_pixelShader);
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetPixelShaderStage().SetClassInstances(GetClassInstanceCount(), GetClassInstances());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetPixelShaderStage().SetConstantBuffers(GetConstantBufferStartSlot(), GetConstantBufferCount(), GetConstantBuffers());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetPixelShaderStage().SetShaderResourceViews(GetShaderResourceViewStartSlot(), GetShaderResourceViewCount(), GetShaderResourceViews());
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetPixelShaderStage().SetSamplerStates(GetSamplerStateStartSlot(), GetSamplerStateCount(), GetSamplerStates());
	}

}