#include "SR_PCH.h"

#include "SR_DrawInstancedIndirectPass.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_DrawInstancedIndirectPass::SR_DrawInstancedIndirectPass(SR_Component * owner) noexcept :
		SR_CommonPass(owner),
		m_argBuffer	{ nullptr },
		m_offset	{ 0 }
	{

	}

	bool SR_DrawInstancedIndirectPass::Render(unsigned threadID)
	{
		SR_RF_BOOL(Apply(threadID));

		SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(threadID)->DrawInstancedIndirect(m_argBuffer, m_offset);

		return true;
	}

}