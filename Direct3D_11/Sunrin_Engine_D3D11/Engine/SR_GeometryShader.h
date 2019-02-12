#pragma once

#include "SR_CommonShader.h"

namespace SunrinEngine
{

	class SR_GeometryShader : public SR_CommonShader
	{
	public:
		explicit SR_GeometryShader() noexcept;

		bool CreateGeometryShader(const std::wstring & filePath, ID3D11ClassLinkage * classLinkage, const std::vector<D3D_SHADER_MACRO> * macros);

		ID3D11GeometryShader * GetGeometryShader() const noexcept { return m_geometryShader.Get(); }

	private:
		Microsoft::WRL::ComPtr<ID3D11GeometryShader> m_geometryShader;

	};

}