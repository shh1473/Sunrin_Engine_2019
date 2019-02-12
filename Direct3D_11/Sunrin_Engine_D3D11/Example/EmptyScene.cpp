#include "SR_PCH.h"

#include "EmptyScene.h"

namespace Example
{

	EmptyScene::EmptyScene() :
		SR_GameScene(L"EmptyScene")
	{

	}

	bool EmptyScene::OnEnter()
	{
		std::cout << "EmptyScene - Enter" << std::endl;

		return true;
	}

	bool EmptyScene::OnExit()
	{
		std::cout << "EmptyScene - Exit" << std::endl;

		return true;
	}

	bool EmptyScene::Initialize()
	{
		std::cout << "EmptyScene - Initialize" << std::endl;

		return true;
	}

	bool EmptyScene::Update()
	{
		//std::cout << "EmptyScene - Update" << std::endl;

		return true;
	}

	bool EmptyScene::FixedUpdate()
	{
		//std::cout << "EmptyScene - FixedUpdate" << std::endl;

		return true;
	}

	bool EmptyScene::LateUpdate()
	{
		//std::cout << "EmptyScene - LateUpdate" << std::endl;

		return true;
	}

}