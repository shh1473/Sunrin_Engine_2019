#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_UI;

	class SR_UIComponent : public SR_NonCopyable
	{
	public:
		explicit SR_UIComponent(SR_UI * owner) noexcept;
		virtual ~SR_UIComponent() noexcept;

		virtual bool Update();

		void SetIsActivate(bool isActivate) { m_isActivate = isActivate; }

		bool GetIsActivate() const noexcept { return m_isActivate; }
		SR_UI * GetOwner() const noexcept { return m_owner; }

	private:
		bool m_isActivate;
		SR_UI *m_owner;

	};

}