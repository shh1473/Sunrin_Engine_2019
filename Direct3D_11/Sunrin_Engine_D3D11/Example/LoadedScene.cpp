#include "SR_PCH.h"

#include "LoadedScene.h"

namespace Example
{

	LoadedScene::LoadedScene() :
		SR_GameScene(L"LoadedScene"),
		m_data_01{ 0 },
		m_data_02{ 0 },
		m_data_03{ 0 }
	{

	}

	bool LoadedScene::OnEnter()
	{
		std::cout << "LoadedScene - Enter" << std::endl;

		std::cout << "Data 01 : " << m_data_01 << std::endl;
		std::cout << "Data 02 : " << m_data_02 << std::endl;
		std::cout << "Data 03 : " << m_data_03 << std::endl;

		return true;
	}

	bool LoadedScene::OnExit()
	{
		std::cout << "LoadedScene - Exit" << std::endl;

		return true;
	}

	bool LoadedScene::Initialize()
	{
		std::cout << "LoadedScene - Initialize" << std::endl;

		return true;
	}

	bool LoadedScene::Update()
	{
		return true;
	}

	bool LoadedScene::FixedUpdate()
	{
		return true;
	}

	bool LoadedScene::LateUpdate()
	{
		return true;
	}

	bool LoadedScene::InitializeData_01()
	{
		m_data_01 = 10;

		return true;
	}

	bool LoadedScene::InitializeData_02()
	{
		m_data_02 = 20;

		return true;
	}

	bool LoadedScene::InitializeData_03()
	{
		m_data_03 = 30;

		return true;
	}

}