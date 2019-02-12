#pragma once

#include "SR_CommonPass.h"

namespace SunrinEngine
{

	class SR_DrawInstancedIndirectPass : public SR_CommonPass
	{
	public:
		explicit SR_DrawInstancedIndirectPass(SR_Component * owner) noexcept;

		virtual bool Render(unsigned threadID) override;

		void SetArgBuffer(ID3D11Buffer * argBuffer) noexcept { m_argBuffer = argBuffer; }
		void SetOffset(unsigned offset) noexcept { m_offset = offset; }

	private:
		ID3D11Buffer * m_argBuffer;
		unsigned m_offset;

	};

}