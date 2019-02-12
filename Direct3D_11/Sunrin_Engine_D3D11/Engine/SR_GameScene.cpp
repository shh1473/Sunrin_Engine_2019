#include "SR_PCH.h"

#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_GameScene::SR_GameScene(const std::wstring & name) :
		m_isDestroyed		{ false },
		m_name				{ name },
		m_updateExecutor	{},
		m_renderExecutor	{},
		m_resourceGenerator	{},
		m_entities			{},
		m_UIs				{}
	{

	}

	SR_GameScene::~SR_GameScene()
	{

	}

	bool SR_GameScene::OnEnter()
	{
		return true;
	}

	bool SR_GameScene::OnExit()
	{
		return true;
	}

	bool SR_GameScene::Initialize()
	{
		return true;
	}

	bool SR_GameScene::FixedUpdate()
	{
		return true;
	}

	bool SR_GameScene::Update()
	{
		return true;
	}

	bool SR_GameScene::LateUpdate()
	{
		return true;
	}

	bool SR_GameScene::RenderFromExecutor()
	{
		return m_renderExecutor.Render();
	}

	bool SR_GameScene::FixedUpdateFromExevutor()
	{
		return m_updateExecutor.FixedUpdate();
	}

	bool SR_GameScene::UpdateFromExevutor()
	{
		return m_updateExecutor.Update();
	}

	bool SR_GameScene::DefaultLateUpdate()
	{
		for (auto iter = m_entities.begin(); iter != m_entities.end();)
		{
			if (iter->second->GetIsDestroyed())
			{
				iter->second.reset();

				m_entities.erase(iter);
			}
			else
			{
				++iter;
			}
		}

		for (auto iter = m_UIs.begin(); iter != m_UIs.end();)
		{
			if (iter->second->GetIsDestroyed())
			{
				iter->second.reset();

				m_UIs.erase(iter);
			}
			else
			{
				++iter;
			}
		}

		for (auto & iter : m_entities)
		{
			SR_RF_BOOL(iter.second->LateUpdate());
			SR_RF_BOOL(iter.second->DefaultLateUpdate());
		}

		for (auto & iter : m_UIs)
		{
			SR_RF_BOOL(iter.second->LateUpdate());
			SR_RF_BOOL(iter.second->DefaultLateUpdate());
		}

		return true;
	}

}