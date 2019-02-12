#include "SR_PCH.h"

#include "SR_ComputeShader.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_ComputeShader::SR_ComputeShader() noexcept :
		m_computeShader{ nullptr }
	{

	}

	bool SR_ComputeShader::CreateComputeShader(const std::wstring & filePath, ID3D11ClassLinkage * classLinkage, const std::vector<D3D_SHADER_MACRO> * macros)
	{
		SR_RF_BOOL(CreateShaderBuffer(filePath, "cs_main", "cs_5_0", macros));

		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateComputeShader(GetShaderBuffer()->GetBufferPointer(), GetShaderBuffer()->GetBufferSize(), classLinkage, m_computeShader.GetAddressOf()));

		return true;
	}

}