#pragma once

#include "ColorEntity.h"
#include "CameraEntity.h"

namespace Example
{

	class ColorRenderingScene : public SR_GameScene
	{
	public:
		explicit ColorRenderingScene();

		virtual bool OnEnter() override;
		virtual bool OnExit() override;

		virtual bool Initialize() override;

		virtual bool FixedUpdate() override;
		virtual bool Update() override;
		virtual bool LateUpdate() override;

	private:
		bool CreateResources();

	private:
		ColorEntity * m_colorEntity;
		CameraEntity * m_cameraEntity;

		// ColorEntity Resources
		SR_Mesh * m_mesh;
		SR_VertexShader * m_vertexShader;
		SR_PixelShader * m_pixelShader;
		ID3D11Buffer * m_vs_matrixBuffer;

		// CameraEntity Resources
		ID3D11DepthStencilState * m_depthStencilState;
		ID3D11BlendState * m_blendState;
		ID3D11RasterizerState * m_rasterizerState;
		SR_Vector4 * m_clearColor;

	};

}