#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_Sound : public SR_NonCopyable
	{
	public:
		explicit SR_Sound() noexcept;

		bool Initialize();

		IDirectSound8 * GetDirectSound() const noexcept { return m_directSound.Get(); }

	private:
		Microsoft::WRL::ComPtr<IDirectSound8> m_directSound;

	};

}