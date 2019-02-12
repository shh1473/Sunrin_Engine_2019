#pragma once

#include "SR_Transform.h"

namespace SunrinEngine
{

	class SR_GameScene;

	class SR_Entity : public SR_NonCopyable
	{
	public:
		explicit SR_Entity(SR_GameScene * gameScene, const std::wstring & name);
		virtual ~SR_Entity();

		virtual bool FixedUpdate();
		virtual bool Update();
		virtual bool LateUpdate();

		bool UpdateComponents();
		bool DefaultLateUpdate();

		void SetIsActivate(bool isActivate) noexcept { m_isActivate = isActivate; }
		void SetIsDestroyed(bool isDestroyed) noexcept { m_isDestroyed = isDestroyed; }

		bool GetIsActivate() const noexcept { return m_isActivate; }
		bool GetIsDestroyed() const noexcept { return m_isDestroyed; }
		const std::wstring & GetName() const noexcept { return m_name; }
		const std::map<std::wstring, std::unique_ptr<SR_Entity>> & GetChildren() const noexcept { return m_children; }
		const std::map<std::type_index, std::unique_ptr<SR_Component>> & GetComponents() const noexcept { return m_components; }
		SR_GameScene * GetGameScene() const noexcept { return m_gameScene; }
		SR_Entity * GetParent() const noexcept { return m_parent; }
		SR_Transform * GetTransform() const noexcept { return m_transform; }

	public:
		template <typename T>
		T * AddComponent()
		{
			T * component{ new T(this) };

			std::unique_ptr<T> com{ component };

			m_components[typeid(T)] = std::move(com);

			return component;
		}

		template <typename T>
		T * FindComponent()
		{
			assert(m_components.count(typeid(T)) > 0);

			return dynamic_cast<T*>(m_components[typeid(T)].get());
		}

		template <typename T>
		T * AddChild(T * entity)
		{
			std::lock_guard<std::mutex> lockGuard(m_addChildMutex);

			entity->m_parent = this;

			std::unique_ptr<T> ent{ entity };

			m_children[entity->GetName()] = std::move(ent);

			return entity;
		}

		template <typename T>
		T * FindChild(const std::wstring & name)
		{
			assert(m_children.count(name) > 0);

			return dynamic_cast<T*>(m_children[name].get());
		}

	private:
		std::mutex m_addChildMutex;

	private:
		bool m_isActivate;
		bool m_isDestroyed;
		unsigned m_threadID;
		std::wstring m_name;
		std::map<std::wstring, std::unique_ptr<SR_Entity>> m_children;
		std::map<std::type_index, std::unique_ptr<SR_Component>> m_components;
		SR_GameScene * m_gameScene;
		SR_Entity * m_parent;
		SR_Transform * m_transform;

	};

}