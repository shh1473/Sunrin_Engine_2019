#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_Component;

	class SR_InputParameterSet : public SR_NonCopyable
	{
	public:
		explicit SR_InputParameterSet(
			SR_Component * owner,
			unsigned vertexBufferSlotCount) noexcept;

		void Apply(unsigned contextIndex);

		void SetIsBindVertexBuffer(bool isBindVertexBuffer) noexcept { m_isBindVertexBuffer = isBindVertexBuffer; }
		void SetIsBindPrimitiveTopology(bool isBindPrimitiveTopology) noexcept { m_isBindPrimitiveTopology = isBindPrimitiveTopology; }
		void SetVertexBufferStartSlot(unsigned startSlot) noexcept { m_vertexBufferStartSlot = startSlot; }
		void SetVertexBufferCount(unsigned count) noexcept { m_vertexBufferCount = count; }
		void SetVertexBuffer(unsigned index, ID3D11Buffer *vertexBuffer) noexcept { m_vertexBuffers[index] = vertexBuffer; }
		void SetVertexBufferStride(unsigned index, unsigned stride) noexcept { m_vertexBufferStrides[index] = stride; }
		void SetVertexBufferOffset(unsigned index, unsigned offset) noexcept { m_vertexBufferOffsets[index] = offset; }
		void SetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY primitiveTopology) noexcept { m_primitiveTopology = primitiveTopology; }

		bool GetIsBindVertexBuffer() const noexcept { return m_isBindVertexBuffer; }
		bool GetIsBindPrimitiveTopology() const noexcept { return m_isBindPrimitiveTopology; }

	private:
		SR_Component * m_owner;
		bool m_isBindVertexBuffer;
		bool m_isBindPrimitiveTopology;
		unsigned m_vertexBufferStartSlot;
		unsigned m_vertexBufferCount;
		std::vector<ID3D11Buffer*> m_vertexBuffers;
		std::vector<unsigned> m_vertexBufferStrides;
		std::vector<unsigned> m_vertexBufferOffsets;
		D3D_PRIMITIVE_TOPOLOGY m_primitiveTopology;

	};

}