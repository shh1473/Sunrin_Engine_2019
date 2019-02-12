#pragma once

#include "SR_PCH.h"
#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_Entity;

	class SR_Component : public SR_NonCopyable
	{
	public:
		explicit SR_Component(SR_Entity * owner) noexcept;
		virtual ~SR_Component() noexcept;

		virtual bool Update();

		void SetIsActivate(bool isActivate) noexcept { m_isActivate = isActivate; }

		bool GetIsActivate() const noexcept { return m_isActivate; }
		SR_Entity * GetOwner() const noexcept { return m_owner; }

	private:
		bool m_isActivate;
		SR_Entity * m_owner;

	};

}