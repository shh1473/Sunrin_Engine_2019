#include "SR_PCH.h"

#include "SR_UI.h"
#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_UI::SR_UI(const std::wstring & name, SR_GameScene * gameScene) :
		m_isActivate	{ true },
		m_isDestroyed	{ false },
		m_threadID		{ gameScene->GetUpdateExecutor().AddUI(this) },
		m_name			{ name },
		m_children		{},
		m_components	{},
		m_gameScene		{ gameScene },
		m_parent		{ nullptr },
		m_transform		{ nullptr }
	{
		m_transform = AddComponent<SR_UITransform>();
	}

	SR_UI::~SR_UI()
	{
		m_gameScene->GetUpdateExecutor().RemoveUI(this, m_threadID);
	}

	bool SR_UI::FixedUpdate()
	{
		return true;
	}

	bool SR_UI::Update()
	{
		return true;
	}

	bool SR_UI::LateUpdate()
	{
		return true;
	}

	bool SR_UI::UpdateComponents()
	{
		for (auto & iter : m_components)
		{
			if (iter.second->GetIsActivate())
			{
				SR_RF_BOOL(iter.second->Update());
			}
		}

		return true;
	}

	bool SR_UI::DefaultLateUpdate()
	{
		for (auto iter = m_children.begin(); iter != m_children.end();)
		{
			if (iter->second->GetIsDestroyed())
			{
				iter->second.reset();

				iter = m_children.erase(iter);
			}
			else
			{
				++iter;
			}
		}

		for (auto & iter : m_children)
		{
			iter.second->LateUpdate();
			iter.second->DefaultLateUpdate();
		}

		return true;
	}

}