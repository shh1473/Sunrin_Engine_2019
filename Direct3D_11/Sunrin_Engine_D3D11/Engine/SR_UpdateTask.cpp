#include "SR_PCH.h"

#include "SR_UpdateTask.h"

namespace SunrinEngine
{

	SR_UpdateTask::SR_UpdateTask() noexcept :
		m_entities	{},
		m_UIs		{}
	{

	}

	bool SR_UpdateTask::Update()
	{
		for (auto iter : m_entities)
		{
			if (iter->GetIsActivate())
			{
				SR_RF_BOOL(iter->Update());
				SR_RF_BOOL(iter->UpdateComponents());
			}
		}

		for (auto iter : m_UIs)
		{
			if (iter->GetIsActivate())
			{
				SR_RF_BOOL(iter->Update());
				SR_RF_BOOL(iter->UpdateComponents());
			}
		}

		return true;
	}

	bool SR_UpdateTask::FixedUpdate()
	{
		for (auto iter : m_entities)
		{
			if (iter->GetIsActivate())
			{
				SR_RF_BOOL(iter->FixedUpdate());
			}
		}

		for (auto iter : m_UIs)
		{
			if (iter->GetIsActivate())
			{
				SR_RF_BOOL(iter->FixedUpdate());
			}
		}

		return true;
	}

	void SR_UpdateTask::AddEntity(SR_Entity * entity)
	{
		m_entities.push_back(entity);
	}

	void SR_UpdateTask::AddUI(SR_UI * UI)
	{
		m_UIs.push_back(UI);
	}

	void SR_UpdateTask::RemoveEntity(SR_Entity * entity)
	{
		m_entities.erase(std::find(m_entities.begin(), m_entities.end(), entity));
	}

	void SR_UpdateTask::RemoveUI(SR_UI * UI)
	{
		m_UIs.erase(std::find(m_UIs.begin(), m_UIs.end(), UI));
	}

}