#include "SR_PCH.h"

#include "SR_PixelShaderStage.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_PixelShaderStage::SR_PixelShaderStage() noexcept :
		m_pixelShader{ nullptr }
	{

	}

	void SR_PixelShaderStage::Apply(bool isBindShader, bool isBindCB, bool isBindSRV, bool isBindSS)
	{
		if (isBindShader)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->PSSetShader(
				m_pixelShader,
				GetClassInstances(),
				GetClassInstanceCount());
		}

		if (isBindCB)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->PSSetConstantBuffers(
				GetConstantBufferStartSlot(),
				GetConstantBufferCount(),
				GetConstantBuffers());
		}

		if (isBindSRV)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->PSSetShaderResources(
				GetShaderResourceViewStartSlot(),
				GetShaderResourceViewCount(),
				GetShaderResourceViews());
		}

		if (isBindSS)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->PSSetSamplers(
				GetSamplerStateStartSlot(),
				GetSamplerStateCount(),
				GetSamplerStates());
		}
	}

}