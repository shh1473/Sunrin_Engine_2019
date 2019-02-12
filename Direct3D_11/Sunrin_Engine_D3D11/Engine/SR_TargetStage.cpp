#include "SR_PCH.h"

#include "SR_TargetStage.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_TargetStage::SR_TargetStage() :
		m_targetImage		{ nullptr },
		m_primitiveBlend	{ D2D1_PRIMITIVE_BLEND_ADD },
		m_renderingControls	{},
		m_unitMode			{ D2D1_UNIT_MODE_PIXELS },
		m_clearColor		{}
	{

	}

	void SR_TargetStage::Apply(bool isBindTarget, bool isBindPrimitiveBlend, bool isBindRenderingControls, bool isBindUnitMode)
	{
		if (isBindTarget)
		{
			SR_App::GetInstance()->GetGraphic().GetD2DDeviceContext()->SetTarget(m_targetImage);
		}

		if (isBindPrimitiveBlend)
		{
			SR_App::GetInstance()->GetGraphic().GetD2DDeviceContext()->SetPrimitiveBlend(m_primitiveBlend);
		}

		if (isBindRenderingControls)
		{
			SR_App::GetInstance()->GetGraphic().GetD2DDeviceContext()->SetRenderingControls(m_renderingControls);
		}

		if (isBindUnitMode)
		{
			SR_App::GetInstance()->GetGraphic().GetD2DDeviceContext()->SetUnitMode(m_unitMode);
		}
	}

	void SR_TargetStage::ClearView()
	{
		SR_App::GetInstance()->GetGraphic().GetD2DDeviceContext()->Clear(m_clearColor);
	}

}