#pragma once

#include "SR_CommonProgrammableStage.h"

namespace SunrinEngine
{

	class SR_VertexShaderStage : public SR_CommonProgrammableStage
	{
	public:
		explicit SR_VertexShaderStage() noexcept;

		void Apply(bool isBindShader, bool isBindCB, bool isBindSRV, bool isBindSS);

		void SetVertexShader(ID3D11VertexShader * vertexShader) noexcept { m_vertexShader = vertexShader; }

	private:
		ID3D11VertexShader * m_vertexShader;

	};

}