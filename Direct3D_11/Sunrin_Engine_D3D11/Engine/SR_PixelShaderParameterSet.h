#pragma once

#include "SR_CommonShaderParameterSet.h"

namespace SunrinEngine
{

	class SR_Component;

	class SR_PixelShaderParameterSet : public SR_CommonShaderParameterSet
	{
	public:
		explicit SR_PixelShaderParameterSet(
			SR_Component * owner,
			unsigned classInstanceSlotCount,
			unsigned constantBufferSlotCount,
			unsigned shaderResourceViewSlotCount,
			unsigned samplerStateSlotCount);

		void Apply(unsigned contextIndex);

		void SetPixelShader(ID3D11PixelShader * pixelShader) noexcept { m_pixelShader = pixelShader; }

	private:
		SR_Component * m_owner;
		ID3D11PixelShader * m_pixelShader;

	};

}