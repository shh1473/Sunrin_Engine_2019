#pragma once

#include "SR_DeferredStage.h"
#include "SR_Vector4.h"

namespace SunrinEngine
{

	class SR_OutputMergerStage : public SR_DeferredStage
	{
	public:
		explicit SR_OutputMergerStage() noexcept;

		void Apply(bool isBindRTVAndDSV, bool isBindDSS, bool isBindBS);
		void ClearViews();

		void SetRenderTargetViews(unsigned count, const std::vector<ID3D11RenderTargetView*> & renderTargetViews);
		void SetDepthStencilView(ID3D11DepthStencilView * depthStencilView) noexcept { m_depthStencilView = depthStencilView; }
		void SetDepthStencilState(ID3D11DepthStencilState * depthStencilState) noexcept { m_depthStencilState = depthStencilState; }
		void SetStencilRef(unsigned stencilRef) noexcept { m_stencilRef = stencilRef; }
		void SetBlendState(ID3D11BlendState * blendState) noexcept { m_blendState = blendState; }
		void SetBlendFactor(SR_Vector4 * blendFactor) noexcept { m_blendFactor = blendFactor; }
		void SetBlendSampleMask(unsigned blendSampleMask) noexcept { m_blendSampleMask = blendSampleMask; }
		void SetRenderTargetViewClearColors(const std::vector<SR_Vector4*> & clearColors);
		void SetDepthStencilClearFlag(D3D11_CLEAR_FLAG depthStencilClearFlag) noexcept { m_depthStencilClearFlag = depthStencilClearFlag; }
		void SetDepthClearValue(float value) noexcept { m_depthClearValue = value; }
		void SetStencilClearValue(unsigned value) noexcept { m_stencilClearValue = value; }

	private:
		unsigned m_renderTargetViewCount;
		ID3D11RenderTargetView * m_renderTargetViews[D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT];
		ID3D11DepthStencilView * m_depthStencilView;
		ID3D11DepthStencilState * m_depthStencilState;
		unsigned m_stencilRef;
		ID3D11BlendState * m_blendState;
		SR_Vector4 * m_blendFactor;
		unsigned m_blendSampleMask;
		SR_Vector4 * m_renderTargetViewClearColors[D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT];
		D3D11_CLEAR_FLAG m_depthStencilClearFlag;
		float m_depthClearValue;
		unsigned m_stencilClearValue;

	};

}