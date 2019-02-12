#pragma once

#include "SR_Executor.h"
#include "SR_UpdateTask.h"

namespace SunrinEngine
{

	class SR_UpdateExecutor : public SR_Executor
	{
	public:
		explicit SR_UpdateExecutor() noexcept;

		bool Update();
		bool FixedUpdate();

		unsigned AddEntity(SR_Entity * entity);
		unsigned AddUI(SR_UI * UI);
		void RemoveEntity(SR_Entity * entity, unsigned threadID);
		void RemoveUI(SR_UI * UI, unsigned threadID);

		SR_UpdateTask & GetUpdateTask(unsigned index) noexcept { return m_updateTasks[index]; }

	private:
		unsigned NextEntityAddIndex();
		unsigned NextUIAddIndex();

	private:
		unsigned m_nowEntityAddIndex;
		unsigned m_nowUIAddIndex;
		std::mutex m_addEntityMutex;
		std::mutex m_addUIMutex;

	private:
		std::array<SR_UpdateTask, SR_MAX_THREAD_COUNT> m_updateTasks;
		std::future<bool> m_updateFutures[SR_MAX_THREAD_COUNT];

	};

}