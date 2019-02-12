#pragma once

#include "SR_CommonProgrammableStage.h"

namespace SunrinEngine
{

	class SR_DomainShaderStage : public SR_CommonProgrammableStage
	{
	public:
		explicit SR_DomainShaderStage() noexcept;

		void Apply(bool isBindShader, bool isBindCB, bool isBindSRV, bool isBindSS);

		void SetDomainShader(ID3D11DomainShader * domainShader) noexcept { m_domainShader = domainShader; }

	private:
		ID3D11DomainShader * m_domainShader;

	};

}