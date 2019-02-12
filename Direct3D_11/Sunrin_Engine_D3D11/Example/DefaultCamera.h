#pragma once

#include "..\SunrinEngine.h"
using namespace SunrinEngine;

namespace Example
{

	class DefaultCamera : public SR_ForwardCamera
	{
	public:
		explicit DefaultCamera(SR_Entity * owner);

		bool Initialize(
			ID3D11RenderTargetView * renderTargetView,
			ID3D11DepthStencilView * depthStencilView,
			ID3D11DepthStencilState * depthStencilState,
			ID3D11BlendState * blendState,
			ID3D11RasterizerState * rasterizerState,
			SR_Viewport * viewport,
			SR_Vector4 * clearColor);

		void UpdateSize(
			ID3D11RenderTargetView * renderTargetView,
			ID3D11DepthStencilView * depthStencilView,
			SR_Viewport * viewport);

	private:
		std::unique_ptr<SR_CameraParameterSet> m_cameraParameterSet;

	};

}