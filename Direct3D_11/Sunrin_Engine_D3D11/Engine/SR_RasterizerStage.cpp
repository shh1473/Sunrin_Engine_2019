#include "SR_PCH.h"

#include "SR_RasterizerStage.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_RasterizerStage::SR_RasterizerStage() noexcept :
		m_rasterizerState	{ nullptr },
		m_viewportCount		{ 0 },
		m_viewports			{},
		m_scissorRectCount	{ 0 },
		m_scissorRects		{}
	{

	}

	void SR_RasterizerStage::Apply(bool isBindRS, bool isBindViewport, bool isBindScissorRect)
	{
		if (isBindRS)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->RSSetState(
				m_rasterizerState);
		}

		if (isBindViewport)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->RSSetViewports(
				m_viewportCount,
				m_viewports);
		}

		if (isBindScissorRect)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->RSSetScissorRects(
				m_scissorRectCount,
				m_scissorRects);
		}
	}

	void SR_RasterizerStage::SetViewports(unsigned count, const std::vector<SR_Viewport*> & viewports)
	{
		m_viewportCount = count;

		for (unsigned i{ 0 }; i < m_viewportCount; ++i)
		{
			m_viewports[i] = viewports[i]->m_viewport;
		}
	}

	void SR_RasterizerStage::SetScissorRects(unsigned count, const std::vector<SR_Rectangle*> & scissorRects)
	{
		m_scissorRectCount = count;

		for (unsigned i{ 0 }; i < m_scissorRectCount; ++i)
		{
			m_scissorRects[i] = scissorRects[i]->m_rect;
		}
	}

}