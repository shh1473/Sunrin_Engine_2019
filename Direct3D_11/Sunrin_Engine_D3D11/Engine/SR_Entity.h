#pragma once

#include "SR_Component.h"

namespace SunrinEngine
{

	class SR_Scene;

	class SR_Entity : public SR_NonCopyable
	{
	public:
		explicit SR_Entity(const std::string& name, SR_Scene *scene);
		virtual ~SR_Entity();

		virtual bool Initialize();
		virtual bool FixedUpdate();
		virtual bool Update();
		virtual bool LateUpdate();

		bool DefaultFixedUpdate();
		bool DefaultUpdate();
		bool DefaultLateUpdate();

		void AddChild(SR_Entity *child);
		SR_Entity* FindChild(const std::string& name);

		void SetIsActivate(bool isActivate) { m_isActivate = isActivate; }
		void SetIsDestroyed(bool isDestroyed) { m_isDestroyed = isDestroyed; }

		bool GetIsActivate()const { return m_isActivate; }
		bool GetIsDestroyed()const { return m_isDestroyed; }
		const std::wstring& GetName()const { return m_name; }
		const std::map<std::wstring, SR_Entity*>& GetChildren()const { return m_children; }
		const std::map<std::type_index, SR_Component*>& GetComponents()const { return m_components; }
		SR_Scene* GetScene()const { return m_scene; }
		SR_Entity* GetParent()const { return m_parent; }
		//OE_Transform* GetTransform()const { return m_transform; }

	public:
		template <typename T>
		T* AddComponent()
		{
			T *component = new (std::nothrow) T();
			if (!component)
			{
				return nullptr;
			}

			component->SetOwner(this);

			m_components[typeid(T)] = component;

			return component;
		}

		template <typename T>
		T* FindComponent()
		{
			if (m_components.count(typeid(T)) > 0)
			{
				return dynamic_cast<T*>(m_components[typeid(T)]);
			}
			else
			{
				return nullptr;
			}
		}

	private:
		bool m_isActivate;
		bool m_isDestroyed;
		std::wstring m_name;
		std::map<std::wstring, SR_Entity*> m_children;
		std::map<std::type_index, SR_Component*> m_components;
		SR_Scene *m_scene;
		SR_Entity *m_parent;
		//OE_Transform *m_transform;

	};

}