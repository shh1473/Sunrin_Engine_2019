#pragma once

#include "ColorPass.h"

namespace Example
{

	class ColorEntity : public SR_Entity
	{
	public:
		explicit ColorEntity(SR_GameScene * gameScene, const std::wstring & name);

		bool Initialize(
			SR_Mesh * mesh,
			SR_VertexShader * vertexShader,
			SR_PixelShader * pixelShader,
			ID3D11Buffer * vs_matrixBuffer);

	private:
		SR_ForwardRenderer * m_colorRenderer;

		std::unique_ptr<SR_RenderTechnique> m_renderTechnique;
		std::unique_ptr<ColorPass> m_colorPass;

	};

}