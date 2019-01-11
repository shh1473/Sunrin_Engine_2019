#include "SR_PCH.h"
#include "SR_Component.h"

namespace SunrinEngine
{

	SR_Component::SR_Component() noexcept :
		m_isActivate	{ true },
		m_owner			{ nullptr }
	{

	}

	bool SR_Component::Update()
	{
		return true;
	}

}