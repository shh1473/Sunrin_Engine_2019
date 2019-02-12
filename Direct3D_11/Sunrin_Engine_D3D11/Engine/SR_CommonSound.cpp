#include "SR_PCH.h"

#include "SR_CommonSound.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_CommonSound::SR_CommonSound(const std::wstring & name) noexcept :
		m_name					{ name },
		m_soundBufferCapability	{ 0L, 0L, 0L, 0L, 0L },
		m_soundBuffer			{ nullptr }
	{

	}

	SR_CommonSound::~SR_CommonSound() noexcept
	{

	}

	SR_CommonSound * SR_CommonSound::Duplicate(const std::wstring & name)
	{
		SR_CommonSound * duplicatedSound{ new SR_CommonSound(name) };

		IDirectSoundBuffer * duplicatedSoundBuffer{ nullptr };
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetSound().GetDirectSound()->DuplicateSoundBuffer(m_soundBuffer.Get(), &duplicatedSoundBuffer));

		duplicatedSound->m_soundBuffer = duplicatedSoundBuffer;

		DSBCAPS soundBufferCapability;
		soundBufferCapability.dwSize = sizeof(DSBCAPS);
		SR_LOG_RF_HR_AUTO(duplicatedSoundBuffer->GetCaps(&soundBufferCapability));

		duplicatedSound->m_soundBufferCapability = soundBufferCapability;
		duplicatedSound->m_bytePerPersentage = m_soundBufferCapability.dwBufferBytes / 100;

		return duplicatedSound;
	}

	bool SR_CommonSound::Play(bool isEnableLooping)
	{
		SR_LOG_RF_HR_AUTO(m_soundBuffer->Play(0, 0, (isEnableLooping) ? DSBPLAY_LOOPING : NULL));

		return true;
	}

	bool SR_CommonSound::Pause()
	{
		SR_LOG_RF_HR_AUTO(m_soundBuffer->Stop());

		return true;
	}

	bool SR_CommonSound::Reset()
	{
		SR_LOG_RF_HR_AUTO(m_soundBuffer->Stop());
		SR_LOG_RF_HR_AUTO(m_soundBuffer->SetCurrentPosition(0));

		return true;
	}

	bool SR_CommonSound::SetVolume(int volume)
	{
		m_soundBuffer->SetVolume(static_cast<long>(volume));

		return true;
	}

	bool SR_CommonSound::SetPan(int pan)
	{
		m_soundBuffer->SetPan(static_cast<long>(pan));

		return true;
	}

	bool SR_CommonSound::SetPosition(unsigned position)
	{
		m_soundBuffer->SetCurrentPosition(static_cast<unsigned long>(m_bytePerPersentage * position));

		return true;
	}

	void SR_CommonSound::SetSoundBufferCapability(const DSBCAPS & soundBufferCapability) noexcept
	{
		m_soundBufferCapability = soundBufferCapability;
		m_bytePerPersentage = m_soundBufferCapability.dwBufferBytes / 100;
	}

}