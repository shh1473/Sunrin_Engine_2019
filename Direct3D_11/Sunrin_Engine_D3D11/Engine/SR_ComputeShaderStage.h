#pragma once

#include "SR_CommonProgrammableStage.h"

namespace SunrinEngine
{

	class SR_ComputeShaderStage : public SR_CommonProgrammableStage
	{
	public:
		explicit SR_ComputeShaderStage() noexcept;

		void Apply(bool isBindShader, bool isBindCB, bool isBindSRV, bool isBindUAV, bool isBindSS);

		void SetComputeShader(ID3D11ComputeShader * computeShader) noexcept { m_computeShader = computeShader; }
		void SetUnorderedAccessViews(unsigned start, unsigned count, const std::vector<ID3D11UnorderedAccessView*> & unorderedAccessViews, const std::vector<unsigned> & unorderedAccessViewInitialCounts) noexcept;

	private:
		ID3D11ComputeShader * m_computeShader;
		unsigned m_unorderedAccessViewStartSlot;
		unsigned m_unorderedAccessViewCount;
		ID3D11UnorderedAccessView * m_unorderedAccessViews[D3D11_PS_CS_UAV_REGISTER_COUNT];
		unsigned m_unorderedAccessViewInitialCounts[D3D11_PS_CS_UAV_REGISTER_COUNT];

	};

}