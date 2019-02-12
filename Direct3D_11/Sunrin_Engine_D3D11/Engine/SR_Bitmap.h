#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_Bitmap : public SR_NonCopyable
	{
	public:
		explicit SR_Bitmap() noexcept;

		bool CreateBitmap(const std::wstring & filePath);

		ID2D1Bitmap1 * GetBitmap() const noexcept { return m_bitmap.Get(); }

	private:
		Microsoft::WRL::ComPtr<ID2D1Bitmap1> m_bitmap;

	};

}