#pragma once

#include "SR_Effect.h"
#include "SR_Matrix5x4.h"
#include "SR_Vector4.h"

namespace SunrinEngine
{

	class SR_ColorMatrixEffect : public SR_Effect
	{
	public:
		explicit SR_ColorMatrixEffect() noexcept;

		virtual bool CreateEffect() override;
		virtual bool ProcessImage(ID2D1Image * image, ID2D1Image ** out_image) override;

		void SetColor(SR_Vector4 * color) { m_colorMatrix.m_11 = color->m_x; m_colorMatrix.m_22 = color->m_y; m_colorMatrix.m_33 = color->m_z; m_colorMatrix.m_44 = color->m_w; }

	private:
		SR_Matrix5x4 m_colorMatrix;

	};

}