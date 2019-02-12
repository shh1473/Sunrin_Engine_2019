#pragma once

#include "SR_UIPass.h"

namespace SunrinEngine
{

	class SR_UITechnique : public SR_NonCopyable
	{
	public:
		explicit SR_UITechnique(unsigned passSlotCount) noexcept;

		bool Update();
		bool Render();

		void SetPass(unsigned index, SR_UIPass * pass) noexcept { m_passes[index] = pass; }

	private:
		std::vector<SR_UIPass*> m_passes;

	};

}