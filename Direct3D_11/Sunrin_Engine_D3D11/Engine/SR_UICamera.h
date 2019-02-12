#pragma once

#include "SR_UIComponent.h"
#include "SR_TargetParameterSet.h"

namespace SunrinEngine
{

	class SR_UICamera : public SR_UIComponent
	{
	public:
		explicit SR_UICamera(SR_UI * owner);
		virtual ~SR_UICamera();

		void Ready();

		void SetTargetParameterSet(SR_TargetParameterSet * targetParameterSet) noexcept { m_targetParameterSet = targetParameterSet; }

		SR_TargetParameterSet * GetTargetParameterSet() const noexcept { return m_targetParameterSet; }

	private:
		SR_TargetParameterSet * m_targetParameterSet;

	};

}