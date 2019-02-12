#pragma once

#include "SR_DeferredStage.h"
#include "SR_Viewport.h"
#include "SR_Rectangle.h"

namespace SunrinEngine
{

	class SR_RasterizerStage : public SR_DeferredStage
	{
	public:
		explicit SR_RasterizerStage() noexcept;

		void Apply(bool isBindRS, bool isBindViewport, bool isBindScissorRect);

		void SetRasterizerState(ID3D11RasterizerState * rasterizerState) noexcept { m_rasterizerState = rasterizerState; }
		void SetViewports(unsigned count, const std::vector<SR_Viewport*> & viewports);
		void SetScissorRects(unsigned count, const std::vector<SR_Rectangle*> & scissorRects);

	private:
		ID3D11RasterizerState * m_rasterizerState;
		unsigned m_viewportCount;
		D3D11_VIEWPORT m_viewports[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];
		unsigned m_scissorRectCount;
		D3D11_RECT m_scissorRects[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];

	};

}