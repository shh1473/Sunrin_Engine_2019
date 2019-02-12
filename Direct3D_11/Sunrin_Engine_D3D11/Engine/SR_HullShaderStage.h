#pragma once

#include "SR_CommonProgrammableStage.h"

namespace SunrinEngine
{

	class SR_HullShaderStage : public SR_CommonProgrammableStage
	{
	public:
		explicit SR_HullShaderStage() noexcept;

		void Apply(bool isBindShader, bool isBindCB, bool isBindSRV, bool isBindSS);

		void SetHullShader(ID3D11HullShader * hullShader) noexcept { m_hullShader = hullShader; }

	private:
		ID3D11HullShader * m_hullShader;

	};

}