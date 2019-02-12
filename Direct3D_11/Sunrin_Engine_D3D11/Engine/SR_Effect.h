#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_Effect : public SR_NonCopyable
	{
	public:
		explicit SR_Effect() noexcept;

		virtual bool CreateEffect() = 0;
		virtual bool ProcessImage(ID2D1Image * image, ID2D1Image ** out_image) = 0;

		void SetIsActivate(bool isActivate) noexcept { m_isActivate = isActivate; }

		bool GetIsActivate() const noexcept { return m_isActivate; }

	protected:
		Microsoft::WRL::ComPtr<ID2D1Effect> & GetEffect() noexcept { return m_effect; }

	private:
		bool m_isActivate;
		Microsoft::WRL::ComPtr<ID2D1Effect> m_effect;

	};

}