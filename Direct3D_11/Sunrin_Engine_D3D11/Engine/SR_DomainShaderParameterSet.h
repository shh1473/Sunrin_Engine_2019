#pragma once

#include "SR_CommonShaderParameterSet.h"

namespace SunrinEngine
{

	class SR_Component;

	class SR_DomainShaderParameterSet : public SR_CommonShaderParameterSet
	{
	public:
		explicit SR_DomainShaderParameterSet(
			SR_Component * owner,
			unsigned classInstanceSlotCount,
			unsigned constantBufferSlotCount,
			unsigned shaderResourceViewSlotCount,
			unsigned samplerStateSlotCount);

		void Apply(unsigned contextIndex);

		void SetDomainShader(ID3D11DomainShader * domainShader) noexcept { m_domainShader = domainShader; }

	private:
		SR_Component * m_owner;
		ID3D11DomainShader * m_domainShader;

	};

}