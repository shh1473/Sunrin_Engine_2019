#pragma once

#include "SR_CommonProgrammableStage.h"

namespace SunrinEngine
{

	class SR_PixelShaderStage : public SR_CommonProgrammableStage
	{
	public:
		explicit SR_PixelShaderStage() noexcept;

		void Apply(bool isBindShader, bool isBindCB, bool isBindSRV, bool isBindSS);

		void SetPixelShader(ID3D11PixelShader * pixelShader) noexcept { m_pixelShader = pixelShader; }

	private:
		ID3D11PixelShader * m_pixelShader;

	};

}