#include "SR_PCH.h"

#include "SR_GeometryShaderStage.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_GeometryShaderStage::SR_GeometryShaderStage() noexcept :
		m_geometryShader{ nullptr }
	{

	}

	void SR_GeometryShaderStage::Apply(bool isBindShader, bool isBindCB, bool isBindSRV, bool isBindSS)
	{
		if (isBindShader)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->GSSetShader(
				m_geometryShader,
				GetClassInstances(),
				GetClassInstanceCount());
		}

		if (isBindCB)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->GSSetConstantBuffers(
				GetConstantBufferStartSlot(),
				GetConstantBufferCount(),
				GetConstantBuffers());
		}

		if (isBindSRV)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->GSSetShaderResources(
				GetShaderResourceViewStartSlot(),
				GetShaderResourceViewCount(),
				GetShaderResourceViews());
		}

		if (isBindSS)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->GSSetSamplers(
				GetSamplerStateStartSlot(),
				GetSamplerStateCount(),
				GetSamplerStates());
		}
	}

}