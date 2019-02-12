#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_CommonShader : public SR_NonCopyable
	{
	public:
		explicit SR_CommonShader() noexcept;
		virtual ~SR_CommonShader() noexcept;

	protected:
		bool CreateShaderBuffer(const std::wstring & filePath, const std::string & functionName, const std::string & shaderModel, const std::vector<D3D_SHADER_MACRO> * macros);

		ID3DBlob * GetShaderBuffer() const noexcept { return m_shaderBuffer.Get(); }

	private:
		Microsoft::WRL::ComPtr<ID3DBlob> m_shaderBuffer;

	};

}