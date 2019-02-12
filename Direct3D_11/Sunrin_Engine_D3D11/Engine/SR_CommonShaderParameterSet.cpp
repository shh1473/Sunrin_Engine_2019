#include "SR_PCH.h"

#include "SR_CommonShaderParameterSet.h"

namespace SunrinEngine
{

	SR_CommonShaderParameterSet::SR_CommonShaderParameterSet(
		unsigned classInstanceSlotCount,
		unsigned constantBufferSlotCount,
		unsigned shaderResourceViewSlotCount,
		unsigned samplerStateSlotCount) :
		m_isBindShader					{ false },
		m_isBindConstantBuffer			{ false },
		m_isBindShaderResourceView		{ false },
		m_isBindSamplerState			{ false },
		m_classInstanceCount			{ 0 },
		m_classInstances				{},
		m_constantBufferStartSlot		{ 0 },
		m_constantBufferCount			{ 0 },
		m_constantBuffers				{},
		m_shaderResourceViewStartSlot	{ 0 },
		m_shaderResourceViewCount		{ 0 },
		m_shaderResourceViews			{},
		m_samplerStateStartSlot			{ 0 },
		m_samplerStateCount				{ 0 },
		m_samplerStates					{}
	{
		m_classInstances.assign(classInstanceSlotCount, nullptr);
		m_constantBuffers.assign(constantBufferSlotCount, nullptr);
		m_shaderResourceViews.assign(shaderResourceViewSlotCount, nullptr);
		m_samplerStates.assign(samplerStateSlotCount, nullptr);
	}

}