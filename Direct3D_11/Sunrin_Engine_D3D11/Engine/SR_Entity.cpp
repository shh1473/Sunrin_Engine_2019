#include "SR_PCH.h"

#include "SR_Entity.h"
#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_Entity::SR_Entity(SR_GameScene * gameScene, const std::wstring & name) :
		m_isActivate	{ true },
		m_isDestroyed	{ false },
		m_threadID		{ gameScene->GetUpdateExecutor().AddEntity(this) },
		m_name			{ name },
		m_children		{},
		m_components	{},
		m_gameScene		{ gameScene },
		m_parent		{ nullptr },
		m_transform		{ nullptr }
	{
		m_transform = AddComponent<SR_Transform>();
	}

	SR_Entity::~SR_Entity()
	{
		m_gameScene->GetUpdateExecutor().RemoveEntity(this, m_threadID);
	}

	bool SR_Entity::FixedUpdate()
	{
		return true;
	}

	bool SR_Entity::Update()
	{
		return true;
	}

	bool SR_Entity::LateUpdate()
	{
		return true;
	}

	bool SR_Entity::UpdateComponents()
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

	bool SR_Entity::DefaultLateUpdate()
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