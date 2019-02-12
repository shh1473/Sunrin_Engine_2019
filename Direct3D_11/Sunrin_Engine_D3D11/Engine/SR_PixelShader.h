#pragma once

#include "SR_CommonShader.h"

namespace SunrinEngine
{

	class SR_PixelShader : public SR_CommonShader
	{
	public:
		explicit SR_PixelShader() noexcept;

		bool CreatePixelShader(const std::wstring & filePath, ID3D11ClassLinkage * classLinkage, const std::vector<D3D_SHADER_MACRO> * macros);

		ID3D11PixelShader * GetPixelShader() const noexcept { return m_pixelShader.Get(); }

	private:
		Microsoft::WRL::ComPtr<ID3D11PixelShader> m_pixelShader;

	};

}