#include "SR_PCH.h"

#include "SR_CommonProgrammableStage.h"

namespace SunrinEngine
{

	SR_CommonProgrammableStage::SR_CommonProgrammableStage() noexcept :
		m_classInstanceCount			{ 0 },
		m_classInstances				{ nullptr },
		m_constantBufferStartSlot		{ 0 },
		m_constantBufferCount			{ 0 },
		m_constantBuffers				{ nullptr },
		m_shaderResourceViewStartSlot	{ 0 },
		m_shaderResourceViewCount		{ 0 },
		m_shaderResourceViews			{ nullptr },
		m_samplerStateStartSlot			{ 0 },
		m_samplerStateCount				{ 0 },
		m_samplerStates					{ nullptr }
	{

	}

	void SR_CommonProgrammableStage::SetClassInstances(unsigned count, const std::vector<ID3D11ClassInstance*> & classInstances)
	{
		m_classInstanceCount = count;

		for (unsigned i{ 0 }; i < m_classInstanceCount; ++i)
		{
			m_classInstances[i] = classInstances[i];
		}
	}

	void SR_CommonProgrammableStage::SetConstantBuffers(unsigned start, unsigned count, const std::vector<ID3D11Buffer*> & constantBuffers)
	{
		m_constantBufferStartSlot = start;
		m_constantBufferCount = count;

		for (unsigned i{ m_constantBufferStartSlot }; i < m_constantBufferCount; ++i)
		{
			m_constantBuffers[i] = constantBuffers[i];
		}
	}

	void SR_CommonProgrammableStage::SetShaderResourceViews(unsigned start, unsigned count, const std::vector<ID3D11ShaderResourceView*> & shaderResourceViews)
	{
		m_shaderResourceViewStartSlot = start;
		m_shaderResourceViewCount = count;

		for (unsigned i{ m_shaderResourceViewStartSlot }; i < m_shaderResourceViewCount; ++i)
		{
			m_shaderResourceViews[i] = shaderResourceViews[i];
		}
	}

	void SR_CommonProgrammableStage::SetSamplerStates(unsigned start, unsigned count, const std::vector<ID3D11SamplerState*> & samplerStates)
	{
		m_samplerStateStartSlot = start;
		m_samplerStateCount = count;

		for (unsigned i{ m_samplerStateStartSlot }; i < m_samplerStateCount; ++i)
		{
			m_samplerStates[i] = samplerStates[i];
		}
	}

}