#include "SR_PCH.h"

#include "SR_InputParameterSet.h"
#include "SR_GameScene.h"

namespace SunrinEngine
{

	SR_InputParameterSet::SR_InputParameterSet(SR_Component * owner, unsigned vertexBufferSlotCount) noexcept :
		m_owner						{ owner },
		m_isBindVertexBuffer		{ false },
		m_isBindPrimitiveTopology	{ false },
		m_vertexBufferStartSlot		{ 0 },
		m_vertexBufferCount			{ 0 },
		m_vertexBuffers				{},
		m_vertexBufferStrides		{},
		m_vertexBufferOffsets		{},
		m_primitiveTopology			{ D3D_PRIMITIVE_TOPOLOGY_UNDEFINED }
	{
		m_vertexBuffers.assign(vertexBufferSlotCount, nullptr);
		m_vertexBufferStrides.assign(vertexBufferSlotCount, 0);
		m_vertexBufferOffsets.assign(vertexBufferSlotCount, 0);
	}

	void SR_InputParameterSet::Apply(unsigned contextIndex)
	{
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetInputAssemblerStage().SetVertexBuffers(m_vertexBufferStartSlot, m_vertexBufferCount, m_vertexBuffers, m_vertexBufferStrides, m_vertexBufferOffsets);
		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(contextIndex).GetInputAssemblerStage().SetPrimitiveTopology(m_primitiveTopology);
	}

}