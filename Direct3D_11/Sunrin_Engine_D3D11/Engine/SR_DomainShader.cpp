#include "SR_PCH.h"

#include "SR_DomainShader.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_DomainShader::SR_DomainShader() noexcept :
		m_domainShader{ nullptr }
	{

	}

	bool SR_DomainShader::CreateDomainShader(const std::wstring & filePath, ID3D11ClassLinkage * classLinkage, const std::vector<D3D_SHADER_MACRO> * macros)
	{
		SR_RF_BOOL(CreateShaderBuffer(filePath, "ds_main", "ds_5_0", macros));

		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateDomainShader(GetShaderBuffer()->GetBufferPointer(), GetShaderBuffer()->GetBufferSize(), classLinkage, m_domainShader.GetAddressOf()));

		return true;
	}

}