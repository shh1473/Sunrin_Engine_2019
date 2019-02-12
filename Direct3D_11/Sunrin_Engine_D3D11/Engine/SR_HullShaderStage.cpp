#include "SR_PCH.h"

#include "SR_HullShaderStage.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_HullShaderStage::SR_HullShaderStage() noexcept :
		m_hullShader{ nullptr }
	{

	}

	void SR_HullShaderStage::Apply(bool isBindShader, bool isBindCB, bool isBindSRV, bool isBindSS)
	{
		if (isBindShader)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->HSSetShader(
				m_hullShader,
				GetClassInstances(),
				GetClassInstanceCount());
		}

		if (isBindCB)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->HSSetConstantBuffers(
				GetConstantBufferStartSlot(),
				GetConstantBufferCount(),
				GetConstantBuffers());
		}

		if (isBindSRV)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->HSSetShaderResources(
				GetShaderResourceViewStartSlot(),
				GetShaderResourceViewCount(),
				GetShaderResourceViews());
		}

		if (isBindSS)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->HSSetSamplers(
				GetSamplerStateStartSlot(),
				GetSamplerStateCount(),
				GetSamplerStates());
		}
	}

}