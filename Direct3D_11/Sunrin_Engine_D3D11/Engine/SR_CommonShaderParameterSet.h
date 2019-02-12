#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_CommonShaderParameterSet : public SR_NonCopyable
	{
	public:
		explicit SR_CommonShaderParameterSet(
			unsigned classInstanceSlotCount,
			unsigned constantBufferSlotCount,
			unsigned shaderResourceViewSlotCount,
			unsigned samplerStateSlotCount);

		void SetIsBindShader(bool isBindShader) noexcept { m_isBindShader = isBindShader; }
		void SetIsBindConstantBuffer(bool isBindConstantBuffer) noexcept { m_isBindConstantBuffer = isBindConstantBuffer; }
		void SetIsBindShaderResourceView(bool isBindShaderResourceView) noexcept { m_isBindShaderResourceView = isBindShaderResourceView; }
		void SetIsBindSamplerState(bool isBindSamplerState) noexcept { m_isBindSamplerState = isBindSamplerState; }
		void SetClassInstanceCount(unsigned count) noexcept { m_classInstanceCount = count; }
		void SetClassInstance(unsigned index, ID3D11ClassInstance * classInstance) { m_classInstances[index] = classInstance; }
		void SetConstantBufferStartSlot(unsigned startSlot) noexcept { m_constantBufferStartSlot = startSlot; }
		void SetConstantBufferCount(unsigned count) noexcept { m_constantBufferCount = count; }
		void SetConstantBuffer(unsigned index, ID3D11Buffer * constantBuffer) { m_constantBuffers[index] = constantBuffer; }
		void SetShaderResourceViewStartSlot(unsigned startSlot) noexcept { m_shaderResourceViewStartSlot = startSlot; }
		void SetShaderResourceViewCount(unsigned count) noexcept { m_shaderResourceViewCount = count; }
		void SetShaderResourceView(unsigned index, ID3D11ShaderResourceView * shaderResourceView) { m_shaderResourceViews[index] = shaderResourceView; }
		void SetSamplerStateStartSlot(unsigned startSlot) noexcept { m_samplerStateStartSlot = startSlot; }
		void SetSamplerStateCount(unsigned count) noexcept { m_samplerStateCount = count; }
		void SetSamplerState(unsigned index, ID3D11SamplerState * samplerState) { m_samplerStates[index] = samplerState; }

		bool GetIsBindShader() const noexcept { return m_isBindShader; }
		bool GetIsBindConstantBuffer() const noexcept { return m_isBindConstantBuffer; }
		bool GetIsBindShaderResourceView() const noexcept { return m_isBindShaderResourceView; }
		bool GetIsBindSamplerState() const noexcept { return m_isBindSamplerState; }

	protected:
		unsigned GetClassInstanceCount() const noexcept { return m_classInstanceCount; }
		const std::vector<ID3D11ClassInstance*> & GetClassInstances() const noexcept { return m_classInstances; }
		unsigned GetConstantBufferStartSlot() const noexcept { return m_constantBufferStartSlot; }
		unsigned GetConstantBufferCount() const noexcept { return m_constantBufferCount; }
		const std::vector<ID3D11Buffer*> & GetConstantBuffers() const noexcept { return m_constantBuffers; }
		unsigned GetShaderResourceViewStartSlot() const noexcept { return m_shaderResourceViewStartSlot; }
		unsigned GetShaderResourceViewCount() const noexcept { return m_shaderResourceViewCount; }
		const std::vector<ID3D11ShaderResourceView*> & GetShaderResourceViews() const noexcept { return m_shaderResourceViews; }
		unsigned GetSamplerStateStartSlot() const noexcept { return m_samplerStateStartSlot; }
		unsigned GetSamplerStateCount() const noexcept { return m_samplerStateCount; }
		const std::vector<ID3D11SamplerState*> & GetSamplerStates() const noexcept { return m_samplerStates; }

	private:
		bool m_isBindShader;
		bool m_isBindConstantBuffer;
		bool m_isBindShaderResourceView;
		bool m_isBindSamplerState;
		unsigned m_classInstanceCount;
		std::vector<ID3D11ClassInstance*> m_classInstances;
		unsigned m_constantBufferStartSlot;
		unsigned m_constantBufferCount;
		std::vector<ID3D11Buffer*> m_constantBuffers;
		unsigned m_shaderResourceViewStartSlot;
		unsigned m_shaderResourceViewCount;
		std::vector<ID3D11ShaderResourceView*> m_shaderResourceViews;
		unsigned m_samplerStateStartSlot;
		unsigned m_samplerStateCount;
		std::vector<ID3D11SamplerState*> m_samplerStates;

	};

}