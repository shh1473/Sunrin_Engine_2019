#pragma once

#include "SR_CommonShaderParameterSet.h"

namespace SunrinEngine
{

	class SR_Component;

	class SR_HullShaderParameterSet : public SR_CommonShaderParameterSet
	{
	public:
		explicit SR_HullShaderParameterSet(
			SR_Component * owner,
			unsigned classInstanceSlotCount,
			unsigned constantBufferSlotCount,
			unsigned shaderResourceViewSlotCount,
			unsigned samplerStateSlotCount);

		void Apply(unsigned contextIndex);

		void SetHullShader(ID3D11HullShader * hullShader) noexcept { m_hullShader = hullShader; }

	private:
		SR_Component * m_owner;
		ID3D11HullShader * m_hullShader;

	};

}