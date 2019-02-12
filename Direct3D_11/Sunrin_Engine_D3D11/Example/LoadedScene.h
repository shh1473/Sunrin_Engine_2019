#pragma once

#include "..\SunrinEngine.h"
using namespace SunrinEngine;

namespace Example
{

	class LoadingScene;

	class LoadedScene : public SR_GameScene
	{
	public:
		friend LoadingScene;

	public:
		explicit LoadedScene();

		virtual bool OnEnter() override;
		virtual bool OnExit() override;

		virtual bool Initialize() override;

		virtual bool FixedUpdate() override;
		virtual bool Update() override;
		virtual bool LateUpdate() override;

	private:
		bool InitializeData_01();
		bool InitializeData_02();
		bool InitializeData_03();

	private:
		unsigned m_data_01;
		unsigned m_data_02;
		unsigned m_data_03;

	};

}