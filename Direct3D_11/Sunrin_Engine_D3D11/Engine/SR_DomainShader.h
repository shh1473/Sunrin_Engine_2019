#pragma once

#include "SR_CommonShader.h"

namespace SunrinEngine
{

	class SR_DomainShader : public SR_CommonShader
	{
	public:
		explicit SR_DomainShader() noexcept;

		bool CreateDomainShader(const std::wstring & filePath, ID3D11ClassLinkage * classLinkage, const std::vector<D3D_SHADER_MACRO> * macros);

		ID3D11DomainShader * GetDomainShader() const noexcept { return m_domainShader.Get(); }

	private:
		Microsoft::WRL::ComPtr<ID3D11DomainShader> m_domainShader;

	};

}