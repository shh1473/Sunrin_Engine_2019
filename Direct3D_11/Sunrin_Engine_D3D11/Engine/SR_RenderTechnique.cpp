#include "SR_PCH.h"

#include "SR_RenderTechnique.h"

namespace SunrinEngine
{

	SR_RenderTechnique::SR_RenderTechnique(unsigned passSlotCount) noexcept :
		m_passes{}
	{
		m_passes.assign(passSlotCount, nullptr);
	}

	bool SR_RenderTechnique::Render(unsigned threadID)
	{
		for (auto iter : m_passes)
		{
			SR_RF_BOOL(iter->Render(threadID));
		}

		return true;
	}

}