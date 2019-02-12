#pragma once

#include "SR_CommonShader.h"

namespace SunrinEngine
{

	class SR_ComputeShader : public SR_CommonShader
	{
	public:
		explicit SR_ComputeShader() noexcept;

		bool CreateComputeShader(const std::wstring & filePath, ID3D11ClassLinkage * classLinkage, const std::vector<D3D_SHADER_MACRO> * macros);

		ID3D11ComputeShader * GetComputeShader() const noexcept { return m_computeShader.Get(); }

	private:
		Microsoft::WRL::ComPtr<ID3D11ComputeShader> m_computeShader;

	};

}