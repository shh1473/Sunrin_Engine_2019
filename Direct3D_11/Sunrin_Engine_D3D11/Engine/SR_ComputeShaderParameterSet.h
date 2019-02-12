#pragma once

#include "SR_CommonShaderParameterSet.h"

namespace SunrinEngine
{

	class SR_Component;

	class SR_ComputeShaderParameterSet : public SR_CommonShaderParameterSet
	{
	public:
		explicit SR_ComputeShaderParameterSet(
			SR_Component * owner,
			unsigned classInstanceSlotCount,
			unsigned constantBufferSlotCount,
			unsigned shaderResourceViewSlotCount,
			unsigned unorderedAccessViewSlotCount,
			unsigned samplerStateSlotCount);

		void Apply(unsigned contextIndex);

		void SetIsBindUnorderedAccessView(bool isBindUnorderedAccessView) { m_isBindUnorderedAccessView = isBindUnorderedAccessView; }
		void SetComputeShader(ID3D11ComputeShader * computeShader) noexcept { m_computeShader = computeShader; }
		void SetUnorderedAccessViewStartSlot(unsigned startSlot) noexcept { m_unorderedAccessViewStartSlot = startSlot; }
		void SetUnorderedAccessViewCount(unsigned count) noexcept { m_unorderedAccessViewCount = count; }
		void SetUnorderedAccessView(unsigned index, ID3D11UnorderedAccessView * unorderedAccessView) { m_unorderedAccessViews[index] = unorderedAccessView; }
		void SetUnorderedAccessViewInitialCount(unsigned index, unsigned initialCount) { m_unorderedAccessViewInitialCounts[index] = initialCount; }

		bool GetIsBindUnorderedAccessView() const noexcept { return m_isBindUnorderedAccessView; }

	private:
		SR_Component * m_owner;
		bool m_isBindUnorderedAccessView;
		ID3D11ComputeShader * m_computeShader;
		unsigned m_unorderedAccessViewStartSlot;
		unsigned m_unorderedAccessViewCount;
		std::vector<ID3D11UnorderedAccessView*> m_unorderedAccessViews;
		std::vector<unsigned> m_unorderedAccessViewInitialCounts;

	};

}