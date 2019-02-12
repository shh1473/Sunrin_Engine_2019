#include "SR_PCH.h"

#include "SR_Scene.h"
#include "SR_App.h"
#include "..\Example\ColorRenderingScene.h"

namespace SunrinEngine
{

	SR_Scene::SR_Scene() noexcept :
		m_nowScene		{ nullptr },
		m_nextScene		{ nullptr },
		m_gameScenes	{}
	{

	}

	SR_Scene::~SR_Scene()
	{
		if (m_nowScene)
		{
			m_nowScene->OnExit();
		}
	}

	bool SR_Scene::Initialize()
	{
		SR_GameScene * firstScene{ AddGameScene(new Example::ColorRenderingScene()) };
		SR_RF_BOOL(firstScene->Initialize());

		ChangeScene(firstScene->GetName());

		return true;
	}

	void SR_Scene::UpdateScene()
	{
		if (m_nextScene)
		{
			if (m_nowScene)
			{
				m_nowScene->OnExit();
			}

			m_nowScene = m_nextScene;
			m_nextScene = nullptr;

			m_nowScene->OnEnter();
		}
	}

	bool SR_Scene::FixedUpdate()
	{
		SR_RF_BOOL(m_nowScene->FixedUpdate());
		SR_RF_BOOL(m_nowScene->FixedUpdateFromExevutor());

		return true;
	}

	bool SR_Scene::Update()
	{
		SR_RF_BOOL(m_nowScene->Update());
		SR_RF_BOOL(m_nowScene->UpdateFromExevutor());

		return true;
	}

	bool SR_Scene::LateUpdate()
	{
		for (auto iter = m_gameScenes.begin(); iter != m_gameScenes.end();)
		{
			if (iter->second.get() == m_nowScene) { ++iter;  continue; }

			if (iter->second->GetIsDestroy())
			{
				iter->second.reset();

				iter = m_gameScenes.erase(iter);
			}
			else
			{
				++iter;
			}
		}

		SR_RF_BOOL(m_nowScene->LateUpdate());
		SR_RF_BOOL(m_nowScene->DefaultLateUpdate());

		return true;
	}

	bool SR_Scene::Render()
	{
		SR_RF_BOOL(m_nowScene->RenderFromExecutor());

		return true;
	}

	void SR_Scene::ChangeScene(const std::wstring & name)
	{
		m_nextScene = FindGameScene<SR_GameScene>(name);
	}

}