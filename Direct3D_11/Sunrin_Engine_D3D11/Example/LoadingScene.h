#pragma once

#include "LoadedScene.h"

namespace Example
{

	class LoadingScene : public SR_GameScene
	{
	public:
		explicit LoadingScene();

		virtual bool OnEnter() override;
		virtual bool OnExit() override;

		virtual bool Initialize() override;

		virtual bool FixedUpdate() override;
		virtual bool Update() override;
		virtual bool LateUpdate() override;

	private:
		bool Load_01();
		bool Load_02();
		bool Load_03();

	private:
		LoadedScene * m_loadedScene;

		SR_Timer m_loadingTimer;

	};

}