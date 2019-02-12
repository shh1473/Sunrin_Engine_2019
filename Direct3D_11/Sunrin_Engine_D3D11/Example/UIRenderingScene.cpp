#include "SR_PCH.h"

#include "UIRenderingScene.h"

namespace Example
{

	UIRenderingScene::UIRenderingScene() :
		SR_GameScene(L"UIRenderingScene")
	{

	}

	bool UIRenderingScene::OnEnter()
	{
		std::cout << "UIRenderingScene - Enter" << std::endl;

		return true;
	}

	bool UIRenderingScene::OnExit()
	{
		std::cout << "UIRenderingScene - Exit" << std::endl;

		return true;
	}

	bool UIRenderingScene::Initialize()
	{
		std::cout << "UIRenderingScene - Initialize" << std::endl;

		SR_RF_BOOL(CreateResources());

		m_UI_01 = AddUI(new SR_UI(L"UI_01", this));

		SR_UIRenderer * renderer_01{ m_UI_01->AddComponent<SR_UIRenderer>() };
		m_technique = std::make_unique<SR_UITechnique>(1);
		m_pass = std::make_unique<SR_UIPass>(renderer_01, 0);

		m_pass->SetBitmap(m_bitmap);
		m_technique->SetPass(0, m_pass.get());
		renderer_01->SetTechnique(m_technique.get());

		m_camera = AddUI(new SR_UI(L"Camera", this));

		SR_UICamera * camera{ m_camera->AddComponent<SR_UICamera>() };
		m_targetParameterSet = std::make_unique<SR_TargetParameterSet>(camera);
		
		m_targetParameterSet->SetIsBindTargetBitmap(true);
		m_targetParameterSet->SetIsBindPrimitiveBlend(false);
		m_targetParameterSet->SetIsBindRenderingControls(false);
		m_targetParameterSet->SetIsBindUnitMode(false);
		m_targetParameterSet->SetTargetBitmap(SR_App::GetInstance()->GetGraphic().GetSwapChainTargetBitmap());
		camera->SetTargetParameterSet(m_targetParameterSet.get());

		return true;
	}

	bool UIRenderingScene::Update()
	{
		//std::cout << "UIRenderingScene - Update" << std::endl;

		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::Up))
		{
			m_UI_01->GetTransform()->AddPositionY(-50.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}
		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::Left))
		{
			m_UI_01->GetTransform()->AddPositionX(-50.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}
		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::Down))
		{
			m_UI_01->GetTransform()->AddPositionY(50.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}
		if (SR_App::GetInstance()->GetInput().KeyPressing(SR_KeyCode::Right))
		{
			m_UI_01->GetTransform()->AddPositionX(50.0f * SR_App::GetInstance()->GetTime().GetDeltaTime());
		}

		return true;
	}

	bool UIRenderingScene::FixedUpdate()
	{
		//std::cout << "UIRenderingScene - FixedUpdate" << std::endl;

		return true;
	}

	bool UIRenderingScene::LateUpdate()
	{
		//std::cout << "UIRenderingScene - LateUpdate" << std::endl;

		return true;
	}

	bool UIRenderingScene::CreateResources()
	{
		SR_RF_BOOL(GetResourceGenerator().CreateBitmap(L"MenuBackground.png", &m_bitmap));

		return true;
	}

}