#include "SR_PCH.h"

#include "SR_UIPass.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_UIPass::SR_UIPass(SR_UIComponent * owner, unsigned effectSlotCount) noexcept :
		m_owner			{ owner },
		m_bitmap		{ nullptr },
		m_size			{ 0.0f, 0.0f },
		m_offset		{ 0.0f, 0.0f },
		m_ratio			{ 0.0f, 0.0f, 1.0f, 1.0f },
		m_visibleRect	{ 0.0f, 0.0f, 1.0f, 1.0f },
		m_effects		{}
	{
		if (effectSlotCount > 0)
		{
			m_effects.assign(effectSlotCount, nullptr);
		}
	}

	bool SR_UIPass::Update()
	{
		return true;
	}

	void SR_UIPass::UpdateVisibleRect()
	{
		m_visibleRect.left = m_size.x * m_ratio.left;
		m_visibleRect.top = m_size.y * m_ratio.top;
		m_visibleRect.right = m_size.x * m_ratio.right;
		m_visibleRect.bottom = m_size.y * m_ratio.bottom;
	}

	bool SR_UIPass::Render()
	{
		static ID2D1Image * curOutput{ nullptr };
		static ID2D1Image * oldOutput{ nullptr };

		curOutput = nullptr;
		oldOutput = m_bitmap->GetBitmap();

		for (unsigned i{ 0 }; i < m_effects.size(); ++i)
		{
			if (m_effects[i]->GetIsActivate())
			{
				SR_RF_BOOL(m_effects[i]->ProcessImage(oldOutput, &curOutput));

				if (oldOutput != m_bitmap->GetBitmap())
				{
					SR_RELEASE(oldOutput);
				}

				oldOutput = curOutput;
			}
		}

		SR_App::GetInstance()->GetGraphic().GetD2DDeviceContext()->SetTransform(m_owner->GetOwner()->GetTransform()->GetWorldMatrix().m_float3x2);

		UpdateVisibleRect();

		SR_App::GetInstance()->GetGraphic().GetD2DDeviceContext()->DrawImage((curOutput) ? curOutput : oldOutput, &m_offset, &m_visibleRect, D2D1_INTERPOLATION_MODE_NEAREST_NEIGHBOR, D2D1_COMPOSITE_MODE_SOURCE_OVER);

		SR_RELEASE(curOutput);

		return true;
	}

	void SR_UIPass::SetBitmap(SR_Bitmap * bitmap) noexcept
	{
		m_bitmap = bitmap;
		m_size.x = m_bitmap->GetBitmap()->GetSize().width;
		m_size.y = m_bitmap->GetBitmap()->GetSize().height;
	}

}