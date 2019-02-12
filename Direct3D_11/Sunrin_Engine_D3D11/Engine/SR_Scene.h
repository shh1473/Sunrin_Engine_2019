#pragma once

#include "SR_GameScene.h"

namespace SunrinEngine
{

	class SR_Scene : public SR_NonCopyable
	{
	public:
		explicit SR_Scene() noexcept;
		~SR_Scene();

		bool Initialize();

		void UpdateScene();
		bool FixedUpdate();
		bool Update();
		bool LateUpdate();
		bool Render();

		void ChangeScene(const std::wstring & name);

	public:
		template <typename T>
		T * AddGameScene(T * gameScene)
		{
			std::lock_guard<std::mutex> lockGuard(m_addGameSceneMutex);

			std::unique_ptr<T> sce{ gameScene };

			m_gameScenes[gameScene->GetName()] = std::move(sce);

			return gameScene;
		}

		template <typename T>
		T * FindGameScene(const std::wstring & name)
		{
			assert(m_gameScenes.count(name) > 0);

			return dynamic_cast<T*>(m_gameScenes[name].get());
		}

	private:
		std::mutex m_addGameSceneMutex;

	private:
		SR_GameScene * m_nowScene;
		SR_GameScene * m_nextScene;
		std::map<std::wstring, std::unique_ptr<SR_GameScene>> m_gameScenes;

	};

}