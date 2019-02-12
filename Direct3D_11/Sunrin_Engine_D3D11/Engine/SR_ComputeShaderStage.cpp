#include "SR_PCH.h"

#include "SR_ComputeShaderStage.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_ComputeShaderStage::SR_ComputeShaderStage() noexcept :
		m_computeShader						{ nullptr },
		m_unorderedAccessViewStartSlot		{ 0 },
		m_unorderedAccessViewCount			{ 0 },
		m_unorderedAccessViews				{ nullptr },
		m_unorderedAccessViewInitialCounts	{ 0 }
	{

	}

	void SR_ComputeShaderStage::Apply(bool isBindShader, bool isBindCB, bool isBindSRV, bool isBindUAV, bool isBindSS)
	{
		if (isBindShader)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->CSSetShader(
				m_computeShader,
				GetClassInstances(),
				GetClassInstanceCount());
		}

		if (isBindCB)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->CSSetConstantBuffers(
				GetConstantBufferStartSlot(),
				GetConstantBufferCount(),
				GetConstantBuffers());
		}

		if (isBindSRV)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->CSSetShaderResources(
				GetShaderResourceViewStartSlot(),
				GetShaderResourceViewCount(),
				GetShaderResourceViews());
		}

		if (isBindUAV)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->CSSetUnorderedAccessViews(
				m_unorderedAccessViewStartSlot,
				m_unorderedAccessViewCount,
				m_unorderedAccessViews,
				m_unorderedAccessViewInitialCounts);
		}

		if (isBindSS)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->CSSetSamplers(
				GetSamplerStateStartSlot(),
				GetSamplerStateCount(),
				GetSamplerStates());
		}
	}

	void SR_ComputeShaderStage::SetUnorderedAccessViews(unsigned start, unsigned count, const std::vector<ID3D11UnorderedAccessView*> & unorderedAccessViews, const std::vector<unsigned> & unorderedAccessViewInitialCounts) noexcept
	{
		m_unorderedAccessViewStartSlot = start;
		m_unorderedAccessViewCount = count;

		for (unsigned i{ m_unorderedAccessViewStartSlot }; i < m_unorderedAccessViewCount; ++i)
		{
			m_unorderedAccessViews[i] = unorderedAccessViews[i];
			m_unorderedAccessViewInitialCounts[i] = unorderedAccessViewInitialCounts[i];
		}
	}

}