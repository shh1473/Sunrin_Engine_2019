#include "SR_PCH.h"

#include "SR_StreamOutputStage.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_StreamOutputStage::SR_StreamOutputStage() noexcept :
		m_streamBufferCount		{ 0 },
		m_streamBuffers			{ nullptr },
		m_streamBufferOffsets	{ 0 }
	{

	}

	void SR_StreamOutputStage::Apply(bool isBindSB)
	{
		if (isBindSB)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->SOSetTargets(
				m_streamBufferCount,
				m_streamBuffers,
				m_streamBufferOffsets);
		}
	}

	void SR_StreamOutputStage::SetStreamBuffers(unsigned count, const std::vector<ID3D11Buffer*> & streamBuffers, const std::vector<unsigned> & streamBufferOffsets)
	{
		m_streamBufferCount = count;

		for (unsigned i{ 0 }; i < m_streamBufferCount; ++i)
		{
			m_streamBuffers[i] = streamBuffers[i];
			m_streamBufferOffsets[i] = streamBufferOffsets[i];
		}
	}

}