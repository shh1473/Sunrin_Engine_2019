#pragma once

#include "SR_Entity.h"
#include "SR_UI.h"
#include "SR_UpdateExecutor.h"
#include "SR_RenderExecutor.h"
#include "SR_ResourceGenerator.h"

namespace SunrinEngine
{

	class SR_GameScene : public SR_NonCopyable
	{
	public:
		explicit SR_GameScene(const std::wstring & name);
		virtual ~SR_GameScene();

		virtual bool OnEnter();
		virtual bool OnExit();

		virtual bool Initialize();

		virtual bool FixedUpdate();
		virtual bool Update();
		virtual bool LateUpdate();

		bool RenderFromExecutor();
		bool FixedUpdateFromExevutor();
		bool UpdateFromExevutor();
		bool DefaultLateUpdate();

		void SetIsDestroyed(bool isDestroyed) noexcept { m_isDestroyed = isDestroyed; }

		bool GetIsDestroy() const noexcept { return m_isDestroyed; }
		const std::wstring & GetName() const noexcept { return m_name; }
		SR_UpdateExecutor & GetUpdateExecutor() noexcept { return m_updateExecutor; }
		SR_RenderExecutor & GetRenderExecutor() noexcept { return m_renderExecutor; }
		SR_ResourceGenerator & GetResourceGenerator() noexcept { return m_resourceGenerator; }
		const std::map<std::wstring, std::unique_ptr<SR_Entity>> & GetEntities() const noexcept { return m_entities; }
		const std::map<std::wstring, std::unique_ptr<SR_UI>> & GetUIs() const noexcept { return m_UIs; }

	public:
		template <typename T>
		T * AddEntity(T * entity)
		{
			std::lock_guard<std::mutex> lockGuard(m_addEntityMutex);

			std::unique_ptr<T> ent{ entity };

			m_entities[entity->GetName()] = std::move(ent);

			return entity;
		}

		template <typename T>
		T * FindEntity(const std::wstring & name)
		{
			assert(m_entities.count(name) > 0);

			return dynamic_cast<T*>(m_entities[name].get());
		}

		template <typename T>
		T * AddUI(T * UI)
		{
			std::lock_guard<std::mutex> lockGuard(m_addUIMutex);

			std::unique_ptr<T> ui{ UI };

			m_UIs[UI->GetName()] = std::move(ui);

			return UI;
		}

		template <typename T>
		T * FindUI(const std::wstring & name)
		{
			assert(m_UIs.count(name) > 0);

			return dynamic_cast<T*>(m_UIs[name].get());
		}

	private:
		std::mutex m_addEntityMutex;
		std::mutex m_addUIMutex;

	private:
		bool m_isDestroyed;
		std::wstring m_name;
		SR_UpdateExecutor m_updateExecutor;
		SR_RenderExecutor m_renderExecutor;
		SR_ResourceGenerator m_resourceGenerator;
		std::map<std::wstring, std::unique_ptr<SR_Entity>> m_entities;
		std::map<std::wstring, std::unique_ptr<SR_UI>> m_UIs;

	};

}