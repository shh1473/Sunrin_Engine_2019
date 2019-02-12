#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_CommonSound : public SR_NonCopyable
	{
	public:
		explicit SR_CommonSound(const std::wstring & name) noexcept;
		virtual ~SR_CommonSound() noexcept;

		SR_CommonSound * Duplicate(const std::wstring & name);

		bool Play(bool isEnableLooping);
		bool Pause();
		bool Reset();

		bool SetVolume(int volume);
		bool SetPan(int pan);
		bool SetPosition(unsigned position);

		const std::wstring & GetName() const noexcept { return m_name; }

	protected:
		void SetSoundBufferCapability(const DSBCAPS & soundBufferCapability) noexcept;
		void SetSoundBuffer(IDirectSoundBuffer * soundBuffer) { m_soundBuffer = soundBuffer; }

	private:
		std::wstring m_name;
		unsigned m_bytePerPersentage;
		DSBCAPS m_soundBufferCapability;
		Microsoft::WRL::ComPtr<IDirectSoundBuffer> m_soundBuffer;

	};

}