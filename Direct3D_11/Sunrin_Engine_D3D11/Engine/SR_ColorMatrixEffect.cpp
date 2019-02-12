#include "SR_PCH.h"

#include "SR_ColorMatrixEffect.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_ColorMatrixEffect::SR_ColorMatrixEffect() noexcept :
		m_colorMatrix{}
	{

	}

	bool SR_ColorMatrixEffect::CreateEffect()
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD2DDeviceContext()->CreateEffect(CLSID_D2D1ColorMatrix, GetEffect().GetAddressOf()));

		return true;
	}

	bool SR_ColorMatrixEffect::ProcessImage(ID2D1Image * image, ID2D1Image ** out_image)
	{
		GetEffect()->SetInput(0, image);

		SR_LOG_RF_HR_AUTO(GetEffect()->SetValue(D2D1_COLORMATRIX_PROP_COLOR_MATRIX, m_colorMatrix));

		GetEffect()->GetOutput(out_image);

		return true;
	}

}