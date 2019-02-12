#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"
#include "SR_Viewport.h"
#include "SR_Rectangle.h"
#include "SR_Vector4.h"

namespace SunrinEngine
{

	class SR_Component;

	class SR_CameraParameterSet : public SR_NonCopyable
	{
	public:
		explicit SR_CameraParameterSet(
			SR_Component * owner,
			unsigned renderTargetViewSlotCount,
			unsigned viewportSlotCount,
			unsigned scissorRectSlotCount);

		void Apply();

		void SetIsBindRenderTargetViewAndDepthStencilView(bool isBindRenderTargetViewAndDepthStencilView) noexcept { m_isBindRenderTargetViewAndDepthStencilView = isBindRenderTargetViewAndDepthStencilView; }
		void SetIsBindDepthStencilState(bool isBindDepthStencilState) noexcept { m_isBindDepthStencilState = isBindDepthStencilState; }
		void SetIsBindBlendState(bool isBindBlendState) noexcept { m_isBindBlendState = isBindBlendState; }
		void SetIsBindRasterizerState(bool isBindRasterizerState) noexcept { m_isBindRasterizerState = isBindRasterizerState; }
		void SetIsBindViewport(bool isBindViewport) noexcept { m_isBindViewport = isBindViewport; }
		void SetIsBindScissorRect(bool isBindScissorRect) noexcept { m_isBindScissorRect = isBindScissorRect; }
		void SetRenderTargetViewCount(unsigned count) noexcept { m_renderTargetViewCount = count; }
		void SetRenderTargetView(unsigned index, ID3D11RenderTargetView *renderTargetView) noexcept { m_renderTargetViews[index] = renderTargetView; }
		void SetDepthStencilView(ID3D11DepthStencilView * depthStencilView) noexcept { m_depthStencilView = depthStencilView; }
		void SetDepthStencilState(ID3D11DepthStencilState * depthStencilState) noexcept { m_depthStencilState = depthStencilState; }
		void SetStencilRef(unsigned stencilRef) noexcept { m_stencilRef = stencilRef; }
		void SetBlendState(ID3D11BlendState * blendState) noexcept { m_blendState = blendState; }
		void SetBlendFactor(SR_Vector4 * blendFactor) noexcept { m_blendFactor = blendFactor; }
		void SetBlendSampleMask(unsigned mask) noexcept { m_blendSampleMask = mask; }
		void SetRenderTargetViewClearColor(unsigned index, SR_Vector4 * color) noexcept { m_renderTargetViewClearColors[index] = color; }
		void SetDepthStencilClearFlag(D3D11_CLEAR_FLAG clearFlag) noexcept { m_depthStencilClearFlag = clearFlag; }
		void SetDepthClearValue(float value) noexcept { m_depthClearValue = value; }
		void SetStencilClearValue(unsigned value) noexcept { m_stencilClearValue = value; }
		void SetRasterizerState(ID3D11RasterizerState * rasterizerState) noexcept { m_rasterizerState = rasterizerState; }
		void SetViewportCount(unsigned count) noexcept { m_viewportCount = count; }
		void SetViewport(unsigned index, SR_Viewport * viewport) noexcept { m_viewports[index] = viewport; }
		void SetScissorRectCount(unsigned count) noexcept { m_scissorRectCount = count; }
		void SetScissorRect(unsigned index, SR_Rectangle * scissorRect) noexcept { m_scissorRects[index] = scissorRect; }

		bool GetIsBindRenderTargetViewAndDepthStencilView() const noexcept { return m_isBindRenderTargetViewAndDepthStencilView; }
		bool GetIsBindDepthStencilState() const noexcept { return m_isBindDepthStencilState; }
		bool GetIsBindBlendState() const noexcept { return m_isBindBlendState; }
		bool GetIsBindRasterizerState() const noexcept { return m_isBindRasterizerState; }
		bool GetIsBindViewport() const noexcept { return m_isBindViewport; }
		bool GetIsBindScissorRect() const noexcept { return m_isBindScissorRect; }

	private:
		SR_Component * m_owner;
		bool m_isBindRenderTargetViewAndDepthStencilView;
		bool m_isBindDepthStencilState;
		bool m_isBindBlendState;
		bool m_isBindRasterizerState;
		bool m_isBindViewport;
		bool m_isBindScissorRect;
		unsigned m_renderTargetViewCount;
		std::vector<ID3D11RenderTargetView*> m_renderTargetViews;
		ID3D11DepthStencilView * m_depthStencilView;
		ID3D11DepthStencilState * m_depthStencilState;
		unsigned m_stencilRef;
		ID3D11BlendState * m_blendState;
		SR_Vector4 * m_blendFactor;
		unsigned m_blendSampleMask;
		std::vector<SR_Vector4*> m_renderTargetViewClearColors;
		D3D11_CLEAR_FLAG m_depthStencilClearFlag;
		float m_depthClearValue;
		unsigned m_stencilClearValue;
		ID3D11RasterizerState *m_rasterizerState;
		unsigned m_viewportCount;
		std::vector<SR_Viewport*> m_viewports;
		unsigned m_scissorRectCount;
		std::vector<SR_Rectangle*> m_scissorRects;

	};

}