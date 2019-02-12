#include "SR_PCH.h"

#include "DefaultCamera.h"

namespace Example
{

	DefaultCamera::DefaultCamera(SR_Entity * owner) :
		SR_ForwardCamera(owner),
		m_cameraParameterSet{ nullptr }
	{

	}

	bool DefaultCamera::Initialize(
		ID3D11RenderTargetView * renderTargetView,
		ID3D11DepthStencilView * depthStencilView,
		ID3D11DepthStencilState * depthStencilState,
		ID3D11BlendState * blendState,
		ID3D11RasterizerState * rasterizerState,
		SR_Viewport * viewport,
		SR_Vector4 * clearColor)
	{
		m_cameraParameterSet = std::make_unique<SR_CameraParameterSet>(this, 1, 1, 0);
		m_cameraParameterSet->SetIsBindRenderTargetViewAndDepthStencilView(true);
		m_cameraParameterSet->SetIsBindDepthStencilState(true);
		m_cameraParameterSet->SetIsBindBlendState(true);
		m_cameraParameterSet->SetIsBindRasterizerState(true);
		m_cameraParameterSet->SetIsBindViewport(true);
		m_cameraParameterSet->SetIsBindScissorRect(false);
		m_cameraParameterSet->SetRenderTargetViewCount(1);
		m_cameraParameterSet->SetRenderTargetView(0, renderTargetView);
		m_cameraParameterSet->SetDepthStencilView(depthStencilView);
		m_cameraParameterSet->SetDepthStencilState(depthStencilState);
		m_cameraParameterSet->SetBlendState(blendState);
		m_cameraParameterSet->SetRasterizerState(rasterizerState);
		m_cameraParameterSet->SetViewportCount(1);
		m_cameraParameterSet->SetViewport(0, viewport);
		m_cameraParameterSet->SetRenderTargetViewClearColor(0, clearColor);

		SetCameraParameterSet(m_cameraParameterSet.get());

		return true;
	}

	void DefaultCamera::UpdateSize(ID3D11RenderTargetView * renderTargetView, ID3D11DepthStencilView * depthStencilView, SR_Viewport * viewport)
	{
		m_cameraParameterSet->SetRenderTargetView(0, renderTargetView);
		m_cameraParameterSet->SetDepthStencilView(depthStencilView);
		m_cameraParameterSet->SetViewport(0, viewport);
	}

}