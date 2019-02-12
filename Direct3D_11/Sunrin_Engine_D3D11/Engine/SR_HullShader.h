#pragma once

#include "SR_CommonShader.h"

namespace SunrinEngine
{

	class SR_HullShader : public SR_CommonShader
	{
	public:
		explicit SR_HullShader() noexcept;

		bool CreateHullShader(const std::wstring & filePath, ID3D11ClassLinkage * classLinkage, const std::vector<D3D_SHADER_MACRO> * macros);

		ID3D11HullShader * GetHullShader() const noexcept { return m_hullShader.Get(); }

	private:
		Microsoft::WRL::ComPtr<ID3D11HullShader> m_hullShader;

	};

}