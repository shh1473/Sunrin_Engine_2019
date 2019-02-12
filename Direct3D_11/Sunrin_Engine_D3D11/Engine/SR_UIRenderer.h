#pragma once

#include "SR_UIComponent.h"
#include "SR_UITechnique.h"

namespace SunrinEngine
{

	class SR_UIRenderer : public SR_UIComponent
	{
	public:
		explicit SR_UIRenderer(SR_UI * owner);
		virtual ~SR_UIRenderer();

		virtual bool Update() override;

		bool Render();

		void SetTechnique(SR_UITechnique * technique) noexcept { m_technique = technique; }

	private:
		SR_UITechnique * m_technique;

	};

}