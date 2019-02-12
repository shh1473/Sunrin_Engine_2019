#include "SR_PCH.h"

#include "SR_Sound.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_Sound::SR_Sound() noexcept :
		m_directSound{ nullptr }
	{

	}

	bool SR_Sound::Initialize()
	{
		SR_LOG_RF_HR_AUTO(DirectSoundCreate8(nullptr, m_directSound.GetAddressOf(), nullptr));

		SR_LOG_RF_HR_AUTO(m_directSound->SetCooperativeLevel(SR_App::GetInstance()->GetWindowHandle(), DSSCL_PRIORITY));

		return true;
	}

}