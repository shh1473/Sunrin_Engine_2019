#include "SR_PCH.h"

#include "SR_StreamParameterSet.h"
#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_StreamParameterSet::SR_StreamParameterSet(SR_Component * owner, unsigned streamBufferSlotCount) :
		m_owner					{ owner },
		m_streamBufferCount		{ 0 },
		m_streamBuffers			{},
		m_streamBufferOffsets	{}
	{

	}

	void SR_StreamParameterSet::Apply(unsigned contextIndex)
	{
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetStreamOutputStage().SetStreamBuffers(m_streamBufferCount, m_streamBuffers, m_streamBufferOffsets);
	}

}