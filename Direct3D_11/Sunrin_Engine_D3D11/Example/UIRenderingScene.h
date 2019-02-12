#pragma once

#include "..\SunrinEngine.h"
using namespace SunrinEngine;

namespace Example
{

	class UIRenderingScene : public SR_GameScene
	{
	public:
		explicit UIRenderingScene();

		virtual bool OnEnter() override;
		virtual bool OnExit() override;

		virtual bool Initialize() override;

		virtual bool FixedUpdate() override;
		virtual bool Update() override;
		virtual bool LateUpdate() override;

	private:
		bool CreateResources();

	private:
		SR_UI * m_UI_01;
		SR_UI * m_camera;

		SR_Bitmap * m_bitmap;

		std::unique_ptr<SR_UITechnique> m_technique;
		std::unique_ptr<SR_UIPass> m_pass;
		std::unique_ptr<SR_TargetParameterSet> m_targetParameterSet;

	};

}