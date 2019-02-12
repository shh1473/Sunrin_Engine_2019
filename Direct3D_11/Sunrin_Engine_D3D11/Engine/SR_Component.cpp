#include "SR_PCH.h"
#include "SR_Component.h"

namespace SunrinEngine
{

	SR_Component::SR_Component(SR_Entity * owner) noexcept :
		m_isActivate	{ true },
		m_owner			{ owner }
	{

	}

	SR_Component::~SR_Component() noexcept
	{

	}

	bool SR_Component::Update()
	{
		return true;
	}

}