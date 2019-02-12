#include "SR_PCH.h"

#include "SR_OutputMergerStage.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_OutputMergerStage::SR_OutputMergerStage() noexcept :
		m_renderTargetViewCount			{ 0 },
		m_renderTargetViews				{ nullptr },
		m_depthStencilView				{ nullptr },
		m_depthStencilState				{ nullptr },
		m_stencilRef					{ D3D11_DEFAULT_STENCIL_REFERENCE },
		m_blendState					{ nullptr },
		m_blendFactor					{ nullptr },
		m_blendSampleMask				{ D3D11_DEFAULT_SAMPLE_MASK },
		m_renderTargetViewClearColors	{ nullptr },
		m_depthStencilClearFlag			{ D3D11_CLEAR_DEPTH },
		m_depthClearValue				{ 1.0f },
		m_stencilClearValue				{ 0 }
	{

	}

	void SR_OutputMergerStage::Apply(bool isBindRTVAndDSV, bool isBindDSS, bool isBindBS)
	{
		if (isBindRTVAndDSV)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->OMSetRenderTargets(
				m_renderTargetViewCount,
				m_renderTargetViews,
				m_depthStencilView);
		}

		if (isBindDSS)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->OMSetDepthStencilState(
				m_depthStencilState,
				m_stencilRef);
		}

		if (isBindBS)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->OMSetBlendState(
				m_blendState,
				m_blendFactor ? m_blendFactor->m_array : nullptr,
				m_blendSampleMask);
		}
	}

	void SR_OutputMergerStage::ClearViews()
	{
		for (unsigned i{ 0 }; i < m_renderTargetViewCount; ++i)
		{
			if (m_renderTargetViews[i])
			{
				SR_App::GetInstance()->GetGraphic().GetD3DImmediateContext()->ClearRenderTargetView(m_renderTargetViews[i], m_renderTargetViewClearColors[i]->m_array);
			}
		}

		SR_App::GetInstance()->GetGraphic().GetD3DImmediateContext()->ClearDepthStencilView(m_depthStencilView, m_depthStencilClearFlag, m_depthClearValue, m_stencilClearValue);
	}

	void SR_OutputMergerStage::SetRenderTargetViews(unsigned count, const std::vector<ID3D11RenderTargetView*> & renderTargetViews)
	{
		m_renderTargetViewCount = count;

		for (unsigned i{ 0 }; i < m_renderTargetViewCount; ++i)
		{
			m_renderTargetViews[i] = renderTargetViews[i];
		}
	}

	void SR_OutputMergerStage::SetRenderTargetViewClearColors(const std::vector<SR_Vector4*> & clearColors)
	{
		for (unsigned i{ 0 }; i < m_renderTargetViewCount; ++i)
		{
			m_renderTargetViewClearColors[i] = clearColors[i];
		}
	}

}