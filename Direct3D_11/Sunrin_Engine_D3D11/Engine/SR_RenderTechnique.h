#pragma once

#include "SR_DrawPass.h"
#include "SR_DrawInstancedPass.h"
#include "SR_DrawInstancedIndirectPass.h"

namespace SunrinEngine
{

	class SR_RenderTechnique : public SR_NonCopyable
	{
	public:
		explicit SR_RenderTechnique(unsigned passSlotCount) noexcept;

		bool Render(unsigned threadID);

		void SetPass(unsigned index, SR_CommonPass * pass) noexcept { m_passes[index] = pass; }

	private:
		std::vector<SR_CommonPass*> m_passes;

	};

}