#pragma once

#include "SR_DeferredStage.h"

namespace SunrinEngine
{

	class SR_CommonProgrammableStage : public SR_DeferredStage
	{
	public:
		explicit SR_CommonProgrammableStage() noexcept;

		void SetClassInstances(unsigned count, const std::vector<ID3D11ClassInstance*> & classInstances);
		void SetConstantBuffers(unsigned start, unsigned count, const std::vector<ID3D11Buffer*> & constantBuffers);
		void SetShaderResourceViews(unsigned start, unsigned count, const std::vector<ID3D11ShaderResourceView*> & shaderResourceViews);
		void SetSamplerStates(unsigned start, unsigned count, const std::vector<ID3D11SamplerState*> & samplerStates);

	protected:
		unsigned GetClassInstanceCount() const noexcept { return m_classInstanceCount; }
		ID3D11ClassInstance * const * GetClassInstances() const noexcept { return m_classInstances; }
		unsigned GetConstantBufferStartSlot() const noexcept { return m_constantBufferStartSlot; }
		unsigned GetConstantBufferCount() const noexcept { return m_constantBufferCount; }
		ID3D11Buffer * const * GetConstantBuffers() const noexcept { return m_constantBuffers; }
		unsigned GetShaderResourceViewStartSlot() const noexcept { return m_shaderResourceViewStartSlot; }
		unsigned GetShaderResourceViewCount() const noexcept { return m_shaderResourceViewCount; }
		ID3D11ShaderResourceView * const * GetShaderResourceViews() const noexcept { return m_shaderResourceViews; }
		unsigned GetSamplerStateStartSlot() const noexcept { return m_samplerStateStartSlot; }
		unsigned GetSamplerStateCount() const noexcept { return m_samplerStateCount; }
		ID3D11SamplerState * const * GetSamplerStates() const noexcept { return m_samplerStates; }

	private:
		unsigned m_classInstanceCount;
		ID3D11ClassInstance * m_classInstances[256];
		unsigned m_constantBufferStartSlot;
		unsigned m_constantBufferCount;
		ID3D11Buffer * m_constantBuffers[D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT];
		unsigned m_shaderResourceViewStartSlot;
		unsigned m_shaderResourceViewCount;
		ID3D11ShaderResourceView * m_shaderResourceViews[D3D11_COMMONSHADER_INPUT_RESOURCE_REGISTER_COUNT];
		unsigned m_samplerStateStartSlot;
		unsigned m_samplerStateCount;
		ID3D11SamplerState * m_samplerStates[D3D11_COMMONSHADER_SAMPLER_REGISTER_COUNT];

	};

}