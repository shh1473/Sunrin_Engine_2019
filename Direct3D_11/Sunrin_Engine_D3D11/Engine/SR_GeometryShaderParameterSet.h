#pragma once

#include "SR_CommonShaderParameterSet.h"

namespace SunrinEngine
{

	class SR_Component;

	class SR_GeometryShaderParameterSet : public SR_CommonShaderParameterSet
	{
	public:
		explicit SR_GeometryShaderParameterSet(
			SR_Component * owner,
			unsigned classInstanceSlotCount,
			unsigned constantBufferSlotCount,
			unsigned shaderResourceViewSlotCount,
			unsigned samplerStateSlotCount);

		void Apply(unsigned contextIndex);

		void SetGeometryShader(ID3D11GeometryShader * geometryShader) noexcept { m_geometryShader = geometryShader; }

	private:
		SR_Component * m_owner;
		ID3D11GeometryShader * m_geometryShader;

	};

}