#include "SR_PCH.h"

#include "SR_UITechnique.h"

namespace SunrinEngine
{

	SR_UITechnique::SR_UITechnique(unsigned passSlotCount) noexcept :
		m_passes{}
	{
		m_passes.assign(passSlotCount, nullptr);
	}

	bool SR_UITechnique::Update()
	{
		for (auto iter : m_passes)
		{
			SR_RF_BOOL(iter->Update());
		}

		return true;
	}

	bool SR_UITechnique::Render()
	{
		for (auto iter : m_passes)
		{
			SR_RF_BOOL(iter->Render());
		}

		return true;
	}

}