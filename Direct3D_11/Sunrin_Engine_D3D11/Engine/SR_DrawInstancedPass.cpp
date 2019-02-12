#include "SR_PCH.h"

#include "SR_DrawInstancedPass.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_DrawInstancedPass::SR_DrawInstancedPass(SR_Component * owner) noexcept :
		SR_CommonPass(owner),
		m_vertexCountPerInstance	{ 0 },
		m_instanceCount				{ 0 },
		m_startVertexLocation		{ 0 },
		m_startInstanceLocation		{ 0 }
	{

	}

	bool SR_DrawInstancedPass::Render(unsigned threadID)
	{
		SR_RF_BOOL(Apply(threadID));

		SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(threadID)->DrawInstanced(m_vertexCountPerInstance, m_instanceCount, m_startVertexLocation, m_startInstanceLocation);

		return true;
	}

}