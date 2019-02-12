#pragma once

#include "SR_Bitmap.h"
#include "SR_Effect.h"

namespace SunrinEngine
{

	class SR_UIComponent;

	class SR_UIPass : public SR_NonCopyable
	{
	public:
		explicit SR_UIPass(SR_UIComponent * owner, unsigned effectSlotCount) noexcept;

		virtual bool Update();
		virtual void UpdateVisibleRect();

		bool Render();

		void SetBitmap(SR_Bitmap * bitmap) noexcept;
		void SetOffset(float x, float y) noexcept { m_offset.x = x; m_offset.y = y; }
		void SetOffsetX(float x) noexcept { m_offset.x = x; }
		void SetOffsetY(float y) noexcept { m_offset.y = y; }
		void SeRatio(float startX, float startY, float endX, float endY) noexcept { m_ratio.left = startX; m_ratio.top = startY; m_ratio.right = endX; m_ratio.bottom = endY; }
		void SeRatioStart(float x, float y) noexcept { m_ratio.left = x; m_ratio.top = y; }
		void SeRatioStartX(float x) noexcept { m_ratio.left = x; }
		void SeRatioStartY(float y) noexcept { m_ratio.top = y; }
		void SeRatioEnd(float x, float y) noexcept { m_ratio.right = x; m_ratio.bottom = y; }
		void SeRatioEndX(float x) noexcept { m_ratio.right = x; }
		void SeRatioEndY(float y) noexcept { m_ratio.bottom = y; }
		void SetVisibleRect(float left, float top, float right, float bottom) noexcept { m_visibleRect.left = left; m_visibleRect.top = top; m_visibleRect.right = right; m_visibleRect.bottom = bottom; }
		void SetEffect(unsigned index, SR_Effect * effect) noexcept { m_effects[index] = effect; }

		SR_Bitmap * GetBitmap() const noexcept { return m_bitmap; }
		const D2D1_POINT_2F & GetSize() const noexcept { return m_size; }
		const D2D1_POINT_2F & GetOffset() const noexcept { return m_offset; }
		const D2D1_RECT_F & GetRatio() const noexcept { return m_ratio; }
		const D2D1_RECT_F & GetVisibleRect() const noexcept { return m_visibleRect; }
		const std::vector<SR_Effect*> & GetEffects() const noexcept { return m_effects; }

	private:
		SR_UIComponent * m_owner;
		SR_Bitmap * m_bitmap;
		D2D1_POINT_2F m_size;
		D2D1_POINT_2F m_offset;
		D2D1_RECT_F m_ratio;
		D2D1_RECT_F m_visibleRect;
		std::vector<SR_Effect*> m_effects;

	};

}