#include "SR_PCH.h"

#include "SR_VertexShader.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_VertexShader::SR_VertexShader() noexcept :
		m_vertexShader	{ nullptr },
		m_inputLayout	{ nullptr }
	{

	}

	bool SR_VertexShader::CreateVertexShader(const std::wstring & filePath, ID3D11ClassLinkage * classLinkage, const std::vector<D3D_SHADER_MACRO> * macros)
	{
		SR_RF_BOOL(CreateShaderBuffer(filePath, "vs_main", "vs_5_0", macros));

		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateVertexShader(GetShaderBuffer()->GetBufferPointer(), GetShaderBuffer()->GetBufferSize(), classLinkage, m_vertexShader.GetAddressOf()));

		return true;
	}

	bool SR_VertexShader::CreateInputLayout(const std::vector<D3D11_INPUT_ELEMENT_DESC> & inputElements)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateInputLayout(&inputElements[0], inputElements.size(), GetShaderBuffer()->GetBufferPointer(), GetShaderBuffer()->GetBufferSize(), m_inputLayout.GetAddressOf()));

		return true;
	}

}