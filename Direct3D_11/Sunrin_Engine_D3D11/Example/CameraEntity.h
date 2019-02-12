#pragma once

#include "DefaultCamera.h"

namespace Example
{

	class CameraEntity : public SR_Entity
	{
	public:
		explicit CameraEntity(SR_GameScene * gameScene, const std::wstring & name);

		bool Initialize(
			ID3D11RenderTargetView * renderTargetView,
			ID3D11DepthStencilView * depthStencilView,
			ID3D11DepthStencilState * depthStencilState,
			ID3D11BlendState * blendState,
			ID3D11RasterizerState * rasterizerState,
			SR_Viewport * viewport,
			SR_Vector4 * clearColor);

		DefaultCamera * GetDefaultCamera() const noexcept { return m_defaultCamera; }

	private:
		DefaultCamera * m_defaultCamera;

	};

}