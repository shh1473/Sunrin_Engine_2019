#include "SR_PCH.h"

#include "SR_UIComponent.h"

namespace SunrinEngine
{

	SR_UIComponent::SR_UIComponent(SR_UI * owner) noexcept :
		m_isActivate	{ true },
		m_owner			{ owner }
	{

	}

	SR_UIComponent::~SR_UIComponent() noexcept
	{

	}

	bool SR_UIComponent::Update()
	{
		return true;
	}

}