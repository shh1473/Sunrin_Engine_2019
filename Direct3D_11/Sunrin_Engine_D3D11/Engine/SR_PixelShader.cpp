#include "SR_PCH.h"

#include "SR_PixelShader.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_PixelShader::SR_PixelShader() noexcept :
		m_pixelShader{ nullptr }
	{

	}

	bool SR_PixelShader::CreatePixelShader(const std::wstring & filePath, ID3D11ClassLinkage * classLinkage, const std::vector<D3D_SHADER_MACRO> * macros)
	{
		SR_RF_BOOL(CreateShaderBuffer(filePath, "ps_main", "ps_5_0", macros));

		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreatePixelShader(GetShaderBuffer()->GetBufferPointer(), GetShaderBuffer()->GetBufferSize(), classLinkage, m_pixelShader.GetAddressOf()));

		return true;
	}

}