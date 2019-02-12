#pragma once

#include "SR_CommonShader.h"
#include "SR_InputElement.h"

namespace SunrinEngine
{

	class SR_VertexShader : public SR_CommonShader
	{
	public:
		explicit SR_VertexShader() noexcept;

		bool CreateVertexShader(const std::wstring & filePath, ID3D11ClassLinkage * classLinkage, const std::vector<D3D_SHADER_MACRO> * macros);
		bool CreateInputLayout(const std::vector<D3D11_INPUT_ELEMENT_DESC> & inputElements);

		ID3D11VertexShader * GetVertexShader() const noexcept { return m_vertexShader.Get(); }
		ID3D11InputLayout * GetInputLayout() const noexcept { return m_inputLayout.Get(); }

	private:
		Microsoft::WRL::ComPtr<ID3D11VertexShader> m_vertexShader;
		Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;

	};

}