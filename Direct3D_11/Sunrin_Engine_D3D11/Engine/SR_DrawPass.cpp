#include "SR_PCH.h"

#include "SR_DrawPass.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_DrawPass::SR_DrawPass(SR_Component * owner) noexcept :
		SR_CommonPass(owner),
		m_vertexCount			{ 0 },
		m_startVertexLocation	{ 0 }
	{

	}

	bool SR_DrawPass::Render(unsigned threadID)
	{
		SR_RF_BOOL(Apply(threadID));

		SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(threadID)->Draw(m_vertexCount, m_startVertexLocation);

		return true;
	}

}