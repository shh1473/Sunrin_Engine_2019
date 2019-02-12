#pragma once

#include "SR_Task.h"
#include "SR_Entity.h"
#include "SR_UI.h"

namespace SunrinEngine
{

	class SR_UpdateTask : public SR_Task
	{
	public:
		explicit SR_UpdateTask() noexcept;

		bool Update();
		bool FixedUpdate();

		void AddEntity(SR_Entity * entity);
		void AddUI(SR_UI * UI);
		void RemoveEntity(SR_Entity * entity);
		void RemoveUI(SR_UI * UI);

	private:
		std::vector<SR_Entity*> m_entities;
		std::vector<SR_UI*> m_UIs;

	};

}