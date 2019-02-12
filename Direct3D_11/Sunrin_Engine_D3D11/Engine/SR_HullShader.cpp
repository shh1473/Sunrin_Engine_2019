#include "SR_PCH.h"

#include "SR_HullShader.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_HullShader::SR_HullShader() noexcept :
		m_hullShader{ nullptr }
	{

	}

	bool SR_HullShader::CreateHullShader(const std::wstring & filePath, ID3D11ClassLinkage * classLinkage, const std::vector<D3D_SHADER_MACRO> * macros)
	{
		SR_RF_BOOL(CreateShaderBuffer(filePath, "hs_main", "hs_5_0", macros));

		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateHullShader(GetShaderBuffer()->GetBufferPointer(), GetShaderBuffer()->GetBufferSize(), classLinkage, m_hullShader.GetAddressOf()));

		return true;
	}

}