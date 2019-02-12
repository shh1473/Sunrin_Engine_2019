#include "SR_PCH.h"

#include "LoadingScene.h"

namespace Example
{

	LoadingScene::LoadingScene() :
		SR_GameScene(L"LoadingScene")
	{

	}

	bool LoadingScene::OnEnter()
	{
		std::cout << "LoadingScene - Enter" << std::endl;

		return true;
	}

	bool LoadingScene::OnExit()
	{
		std::cout << "LoadingScene - Exit" << std::endl;

		return true;
	}

	bool LoadingScene::Initialize()
	{
		std::cout << "LoadingScene - Initialize" << std::endl;

		m_loadedScene = SR_App::GetInstance()->GetScene().AddGameScene(new LoadedScene());
		SR_RF_BOOL(m_loadedScene->Initialize());

		m_loadingTimer.SetTargetTime(3.0f);
		m_loadingTimer.SetFunction([&]()
		{
			SR_RF_BOOL(Load_01());

			return true;
		});
		m_loadingTimer.Start();

		return true;
	}

	bool LoadingScene::Update()
	{
		SR_RF_BOOL(m_loadingTimer.Update());

		return true;
	}

	bool LoadingScene::FixedUpdate()
	{
		return true;
	}

	bool LoadingScene::LateUpdate()
	{
		return true;
	}

	bool LoadingScene::Load_01()
	{
		std::cout << "Load_01" << std::endl;

		SR_RF_BOOL(m_loadedScene->InitializeData_01());

		m_loadingTimer.Reset();
		m_loadingTimer.SetFunction([&]()
		{
			SR_RF_BOOL(Load_02());

			return true;
		});
		m_loadingTimer.Start();

		return true;
	}

	bool LoadingScene::Load_02()
	{
		std::cout << "Load_02" << std::endl;

		SR_RF_BOOL(m_loadedScene->InitializeData_02());

		m_loadingTimer.Reset();
		m_loadingTimer.SetFunction([&]()
		{
			SR_RF_BOOL(Load_03());

			return true;
		});
		m_loadingTimer.Start();

		return true;
	}

	bool LoadingScene::Load_03()
	{
		std::cout << "Load_03" << std::endl;

		SR_RF_BOOL(m_loadedScene->InitializeData_03());

		m_loadingTimer.Reset();

		// Change scene to loadedScene
		SR_App::GetInstance()->GetScene().ChangeScene(m_loadedScene->GetName());

		// Destroy itself
		SetIsDestroyed(true);

		return true;
	}

}