#include "SR_PCH.h"

#include "SR_GeometryShader.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_GeometryShader::SR_GeometryShader() noexcept :
		m_geometryShader{ nullptr }
	{

	}

	bool SR_GeometryShader::CreateGeometryShader(const std::wstring & filePath, ID3D11ClassLinkage * classLinkage, const std::vector<D3D_SHADER_MACRO> * macros)
	{
		SR_RF_BOOL(CreateShaderBuffer(filePath, "gs_main", "gs_5_0", macros));

		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDevice()->CreateGeometryShader(GetShaderBuffer()->GetBufferPointer(), GetShaderBuffer()->GetBufferSize(), classLinkage, m_geometryShader.GetAddressOf()));

		return true;
	}

}