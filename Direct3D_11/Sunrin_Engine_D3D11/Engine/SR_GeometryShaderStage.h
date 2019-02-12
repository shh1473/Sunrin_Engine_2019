#pragma once

#include "SR_CommonProgrammableStage.h"

namespace SunrinEngine
{

	class SR_GeometryShaderStage : public SR_CommonProgrammableStage
	{
	public:
		explicit SR_GeometryShaderStage() noexcept;

		void Apply(bool isBindShader, bool isBindCB, bool isBindSRV, bool isBindSS);

		void SetGeometryShader(ID3D11GeometryShader * geometryShader) noexcept { m_geometryShader = geometryShader; }

	private:
		ID3D11GeometryShader * m_geometryShader;

	};

}