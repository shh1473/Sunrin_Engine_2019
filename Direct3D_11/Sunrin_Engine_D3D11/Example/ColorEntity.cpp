#include "SR_PCH.h"

#include "ColorEntity.h"

namespace Example
{

	ColorEntity::ColorEntity(SR_GameScene * gameScene, const std::wstring & name) :
		SR_Entity(gameScene, name),
		m_colorRenderer		{ nullptr },
		m_renderTechnique	{ nullptr },
		m_colorPass			{ nullptr }
	{

	}

	bool ColorEntity::Initialize(
		SR_Mesh * mesh,
		SR_VertexShader * vertexShader,
		SR_PixelShader * pixelShader,
		ID3D11Buffer * vs_matrixBuffer)
	{
		m_colorRenderer = AddComponent<SR_ForwardRenderer>();

		m_renderTechnique = std::make_unique<SR_RenderTechnique>(1);
		m_colorPass = std::make_unique<ColorPass>(m_colorRenderer);

		SR_RF_BOOL(m_colorPass->Initialize(
			mesh,
			vertexShader,
			pixelShader,
			vs_matrixBuffer));

		m_renderTechnique->SetPass(0, m_colorPass.get());
		m_colorRenderer->SetTechnique(m_renderTechnique.get());

		return true;
	}

}