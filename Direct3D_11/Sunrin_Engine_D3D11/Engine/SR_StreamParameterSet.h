#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_Component;

	class SR_StreamParameterSet : public SR_NonCopyable
	{
	public:
		explicit SR_StreamParameterSet(
			SR_Component * owner,
			unsigned streamBufferSlotCount);

		void Apply(unsigned contextIndex);

		void SetIsBindStreamBuffer(bool isBindStreamBuffer) noexcept { m_isBindStreamBuffer = isBindStreamBuffer; }
		void SetStreamBufferCount(unsigned count) noexcept { m_streamBufferCount = count; }
		void SetStreamBuffer(unsigned index, ID3D11Buffer *streamBuffer) { m_streamBuffers[index] = streamBuffer; }
		void SetStreamBufferOffsets(unsigned index, unsigned offset) { m_streamBufferOffsets[index] = offset; }

		bool GetIsBindStreamBuffer() const noexcept { return m_isBindStreamBuffer; }

	private:
		SR_Component * m_owner;
		bool m_isBindStreamBuffer;
		unsigned m_streamBufferCount;
		std::vector<ID3D11Buffer*> m_streamBuffers;
		std::vector<unsigned> m_streamBufferOffsets;

	};

}