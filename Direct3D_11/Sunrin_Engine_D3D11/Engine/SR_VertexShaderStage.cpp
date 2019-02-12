#include "SR_PCH.h"

#include "SR_VertexShaderStage.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_VertexShaderStage::SR_VertexShaderStage() noexcept :
		m_vertexShader{ nullptr }
	{

	}

	void SR_VertexShaderStage::Apply(bool isBindShader, bool isBindCB, bool isBindSRV, bool isBindSS)
	{
		if (isBindShader)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->VSSetShader(
				m_vertexShader,
				GetClassInstances(),
				GetClassInstanceCount());
		}

		if (isBindCB)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->VSSetConstantBuffers(
				GetConstantBufferStartSlot(),
				GetConstantBufferCount(),
				GetConstantBuffers());
		}

		if (isBindSRV)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->VSSetShaderResources(
				GetShaderResourceViewStartSlot(),
				GetShaderResourceViewCount(),
				GetShaderResourceViews());
		}

		if (isBindSS)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->VSSetSamplers(
				GetSamplerStateStartSlot(),
				GetSamplerStateCount(),
				GetSamplerStates());
		}
	}

}