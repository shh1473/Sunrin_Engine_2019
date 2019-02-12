#pragma once

#include "..\SunrinEngine.h"
using namespace SunrinEngine;

namespace Example
{

	class EmptyScene : public SR_GameScene
	{
	public:
		explicit EmptyScene();

		virtual bool OnEnter() override;
		virtual bool OnExit() override;

		virtual bool Initialize() override;

		virtual bool FixedUpdate() override;
		virtual bool Update() override;
		virtual bool LateUpdate() override;

	private:
		// Empty!

	};

}