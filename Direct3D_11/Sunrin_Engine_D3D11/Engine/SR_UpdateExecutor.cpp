#include "SR_PCH.h"

#include "SR_UpdateExecutor.h"

namespace SunrinEngine
{

	SR_UpdateExecutor::SR_UpdateExecutor() noexcept :
		m_nowEntityAddIndex	{ 0 },
		m_nowUIAddIndex		{ 0 },
		m_updateTasks		{}
	{
		m_updateTasks[0].SetThreadID(0);
		m_updateTasks[1].SetThreadID(1);
		m_updateTasks[2].SetThreadID(2);
		m_updateTasks[3].SetThreadID(3);
	}

	bool SR_UpdateExecutor::Update()
	{
		m_updateFutures[0] = std::async([&]() { return m_updateTasks[0].Update(); });
		m_updateFutures[1] = std::async([&]() { return m_updateTasks[1].Update(); });
		m_updateFutures[2] = std::async([&]() { return m_updateTasks[2].Update(); });
		m_updateFutures[3] = std::async([&]() { return m_updateTasks[3].Update(); });

		SR_RF_BOOL(m_updateFutures[0].get());
		SR_RF_BOOL(m_updateFutures[1].get());
		SR_RF_BOOL(m_updateFutures[2].get());
		SR_RF_BOOL(m_updateFutures[3].get());

		return true;
	}

	bool SR_UpdateExecutor::FixedUpdate()
	{
		m_updateFutures[0] = std::async([&]() { return m_updateTasks[0].FixedUpdate(); });
		m_updateFutures[1] = std::async([&]() { return m_updateTasks[1].FixedUpdate(); });
		m_updateFutures[2] = std::async([&]() { return m_updateTasks[2].FixedUpdate(); });
		m_updateFutures[3] = std::async([&]() { return m_updateTasks[3].FixedUpdate(); });

		SR_RF_BOOL(m_updateFutures[0].get());
		SR_RF_BOOL(m_updateFutures[1].get());
		SR_RF_BOOL(m_updateFutures[2].get());
		SR_RF_BOOL(m_updateFutures[3].get());

		return true;
	}

	unsigned SR_UpdateExecutor::AddEntity(SR_Entity * entity)
	{
		std::lock_guard<std::mutex> lockGuard(m_addEntityMutex);

		unsigned contextIndex{ NextEntityAddIndex() };

		m_updateTasks[contextIndex].AddEntity(entity);

		return contextIndex;
	}

	unsigned SR_UpdateExecutor::AddUI(SR_UI * UI)
	{
		std::lock_guard<std::mutex> lockGuard(m_addUIMutex);

		unsigned contextIndex{ NextUIAddIndex() };

		m_updateTasks[contextIndex].AddUI(UI);

		return contextIndex;
	}

	void SR_UpdateExecutor::RemoveEntity(SR_Entity * entity, unsigned threadID)
	{
		m_updateTasks[threadID].RemoveEntity(entity);
	}

	void SR_UpdateExecutor::RemoveUI(SR_UI * UI, unsigned threadID)
	{
		m_updateTasks[threadID].RemoveUI(UI);
	}

	unsigned SR_UpdateExecutor::NextEntityAddIndex()
	{
		m_nowEntityAddIndex %= SR_MAX_THREAD_COUNT;

		return m_nowEntityAddIndex++;
	}

	unsigned SR_UpdateExecutor::NextUIAddIndex()
	{
		m_nowUIAddIndex %= SR_MAX_THREAD_COUNT;

		return m_nowUIAddIndex++;
	}

}