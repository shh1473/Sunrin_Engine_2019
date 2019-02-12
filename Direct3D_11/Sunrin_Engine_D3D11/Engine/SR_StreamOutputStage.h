#pragma once

#include "SR_DeferredStage.h"

namespace SunrinEngine
{

	class SR_StreamOutputStage : public SR_DeferredStage
	{
	public:
		explicit SR_StreamOutputStage() noexcept;

		void Apply(bool isBindSB);

		void SetStreamBuffers(unsigned count, const std::vector<ID3D11Buffer*> & streamBuffers, const std::vector<unsigned> & streamBufferOffsets);

	private:
		unsigned m_streamBufferCount;
		ID3D11Buffer* m_streamBuffers[D3D11_SO_BUFFER_SLOT_COUNT];
		unsigned m_streamBufferOffsets[D3D11_SO_BUFFER_SLOT_COUNT];

	};

}