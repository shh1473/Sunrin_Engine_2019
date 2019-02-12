#include "SR_PCH.h"

#include "CameraEntity.h"

namespace Example
{

	CameraEntity::CameraEntity(SR_GameScene * gameScene, const std::wstring & name) :
		SR_Entity(gameScene, name),
		m_defaultCamera{ nullptr }
	{

	}

	bool CameraEntity::Initialize(
		ID3D11RenderTargetView * renderTargetView,
		ID3D11DepthStencilView * depthStencilView,
		ID3D11DepthStencilState * depthStencilState,
		ID3D11BlendState * blendState,
		ID3D11RasterizerState * rasterizerState,
		SR_Viewport * viewport,
		SR_Vector4 * clearColor)
	{
		m_defaultCamera = AddComponent<DefaultCamera>();

		SR_RF_BOOL(m_defaultCamera->Initialize(
			renderTargetView,
			depthStencilView,
			depthStencilState,
			blendState,
			rasterizerState,
			viewport,
			clearColor));

		return true;
	}

}