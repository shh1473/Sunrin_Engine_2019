#include "SR_PCH.h"

#include "SR_InputAssemblerStage.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_InputAssemblerStage::SR_InputAssemblerStage() noexcept :
		m_vertexBufferStartSlot	{ 0 },
		m_vertexBufferCount		{ 0 },
		m_vertexBuffers			{ nullptr },
		m_vertexBufferStrides	{ 0 },
		m_vertexBufferOffsets	{ 0 },
		m_inputLayout			{ nullptr },
		m_primitiveTopology		{ D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED }
	{

	}

	void SR_InputAssemblerStage::Apply(bool isBindVB, bool isBindInputLayout, bool isBindPrimitiveTopology)
	{
		if (isBindVB)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->IASetVertexBuffers(
				m_vertexBufferStartSlot,
				m_vertexBufferCount,
				m_vertexBuffers,
				m_vertexBufferStrides,
				m_vertexBufferOffsets);
		}

		if (isBindInputLayout)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->IASetInputLayout(
				m_inputLayout);
		}

		if (isBindPrimitiveTopology)
		{
			SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(GetThreadID())->IASetPrimitiveTopology(
				m_primitiveTopology);
		}
	}

	void SR_InputAssemblerStage::SetVertexBuffers(unsigned start, unsigned count, const std::vector<ID3D11Buffer*> & vertexBuffers, const std::vector<unsigned> & vertexBufferStrides, const std::vector<unsigned> & vertexBufferOffsets)
	{
		m_vertexBufferStartSlot = start;
		m_vertexBufferCount = count;

		for (unsigned i{ m_vertexBufferStartSlot }; i < m_vertexBufferCount; ++i)
		{
			m_vertexBuffers[i] = vertexBuffers[i];
			m_vertexBufferStrides[i] = vertexBufferStrides[i];
			m_vertexBufferOffsets[i] = vertexBufferOffsets[i];
		}
	}

}