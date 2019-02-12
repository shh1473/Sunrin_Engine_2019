#include "SR_PCH.h"

#include "SR_CommonShader.h"
#include "SR_App.h"
#include "SR_Converter.h"

namespace SunrinEngine
{

	SR_CommonShader::SR_CommonShader() noexcept :
		m_shaderBuffer{ nullptr }
	{

	}

	SR_CommonShader::~SR_CommonShader() noexcept
	{

	}

	bool SR_CommonShader::CreateShaderBuffer(const std::wstring & filePath, const std::string & functionName, const std::string & shaderModel, const std::vector<D3D_SHADER_MACRO> * macros)
	{
		std::wstring path{ L"Resources\\Shaders\\" + filePath };

		UINT flags{ 0 };
		Microsoft::WRL::ComPtr<ID3DBlob> errorMessage{ nullptr };

#if defined(DEBUG) || defined(_DEBUG)
		flags |= D3DCOMPILE_DEBUG;
		flags |= D3DCOMPILE_SKIP_OPTIMIZATION;
#endif

		if (FAILED(D3DCompileFromFile(
			path.c_str(),
			(macros) ? &(*macros)[0] : nullptr,
			nullptr,
			functionName.c_str(),
			shaderModel.c_str(),
			flags,
			0,
			m_shaderBuffer.GetAddressOf(),
			errorMessage.GetAddressOf())))
		{
			SR_App::GetInstance()->GetLog().LineOpen();

			SR_App::GetInstance()->GetLog().WriteLine(L"셰이더 파일을 불러오는 데 실패했습니다.");

			if (errorMessage)
			{
				std::string message{ reinterpret_cast<char*>(errorMessage->GetBufferPointer()) };

				SR_App::GetInstance()->GetLog().WriteLine(L"에러 메시지 >>>");
				SR_App::GetInstance()->GetLog().WriteLine(SR_Converter::ToUnicode(message));
			}

			SR_App::GetInstance()->GetLog().LineClose();

			return false;
		}

		return true;
	}

}