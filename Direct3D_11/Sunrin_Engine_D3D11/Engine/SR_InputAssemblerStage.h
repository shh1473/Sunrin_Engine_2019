#pragma once

#include "SR_DeferredStage.h"

namespace SunrinEngine
{

	class SR_InputAssemblerStage : public SR_DeferredStage
	{
	public:
		explicit SR_InputAssemblerStage() noexcept;

		void Apply(bool isBindVB, bool isBindInputLayout, bool isBindPrimitiveTopology);

		void SetVertexBuffers(unsigned start, unsigned count, const std::vector<ID3D11Buffer*> & vertexBuffers, const std::vector<unsigned> & vertexBufferStrides, const std::vector<unsigned> & vertexBufferOffsets);
		void SetInputLayout(ID3D11InputLayout * inputLayout) noexcept { m_inputLayout = inputLayout; }
		void SetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY primitiveTopology) noexcept { m_primitiveTopology = primitiveTopology; }

	private:
		unsigned m_vertexBufferStartSlot;
		unsigned m_vertexBufferCount;
		ID3D11Buffer * m_vertexBuffers[D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT];
		unsigned m_vertexBufferStrides[D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT];
		unsigned m_vertexBufferOffsets[D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT];
		ID3D11InputLayout* m_inputLayout;
		D3D11_PRIMITIVE_TOPOLOGY m_primitiveTopology;

	};

}