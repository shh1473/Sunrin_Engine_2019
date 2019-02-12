#pragma once

#include "SR_CommonShaderParameterSet.h"

namespace SunrinEngine
{

	class SR_Component;

	class SR_VertexShaderParameterSet : public SR_CommonShaderParameterSet
	{
	public:
		explicit SR_VertexShaderParameterSet(
			SR_Component * owner,
			unsigned classInstanceSlotCount,
			unsigned constantBufferSlotCount,
			unsigned shaderResourceViewSlotCount,
			unsigned samplerStateSlotCount);

		void Apply(unsigned contextIndex);

		void SetIsBindInputLayout(bool isBindInputLayout) noexcept { m_isBindInputLayout = isBindInputLayout; }
		void SetVertexShader(ID3D11VertexShader * vertexShader) noexcept { m_vertexShader = vertexShader; }
		void SetInputLayout(ID3D11InputLayout * inputLayout) noexcept { m_inputLayout = inputLayout; }

		bool GetIsBindInputLayout() const noexcept { return m_isBindInputLayout; }

	private:
		SR_Component * m_owner;
		bool m_isBindInputLayout;
		ID3D11VertexShader * m_vertexShader;
		ID3D11InputLayout * m_inputLayout;

	};

}