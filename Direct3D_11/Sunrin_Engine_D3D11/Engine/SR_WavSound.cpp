#include "SR_PCH.h"

#include "SR_WavSound.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_WavSound::SR_WavSound(const std::wstring & name) noexcept :
		SR_CommonSound(name)
	{

	}

	bool SR_WavSound::CreateSound(const std::wstring & filePath)
	{
		std::wstring path{ L"Resources\\Sounds\\" + filePath };

		HMMIO waveFile{ mmioOpenW(const_cast<wchar_t*>(filePath.c_str()), 0, MMIO_ALLOCBUF | MMIO_READ) };
		SR_LOG_RF_BOOL_AUTO(waveFile);
		std::unique_ptr<HMMIO__, std::function<void(HMMIO)>> unique_waveFile{
			waveFile,
			[](HMMIO p) { mmioClose(p, 0); } };

		MMCKINFO parent;
		parent.ckid = 0L;
		parent.cksize = 0L;
		parent.fccType = mmioFOURCC('W', 'A', 'V', 'E');
		parent.dwDataOffset = 0L;
		parent.dwFlags = 0L;

		MMCKINFO child;
		child.ckid = 0L;
		child.cksize = 0L;
		child.fccType = mmioFOURCC('f', 'm', 't', ' ');
		child.dwDataOffset = 0L;
		child.dwFlags = 0L;

		SR_LOG_RF_BOOL_AUTO(mmioDescend(waveFile, &parent, nullptr, MMIO_FINDRIFF) == MMSYSERR_NOERROR);
		SR_LOG_RF_BOOL_AUTO(mmioDescend(waveFile, &child, &parent, MMIO_FINDCHUNK) == MMSYSERR_NOERROR);

		WAVEFORMATEX waveFormatEx{ 0, 0, 0L, 0L, 0, 0, 0 };

		SR_LOG_RF_BOOL_AUTO(mmioRead(waveFile, (HPSTR)&waveFormatEx, sizeof(WAVEFORMATEX)) == sizeof(WAVEFORMATEX));

		SR_LOG_RF_BOOL_AUTO(waveFormatEx.wFormatTag == WAVE_FORMAT_PCM);

		SR_LOG_RF_BOOL_AUTO(mmioAscend(waveFile, &child, 0) == MMSYSERR_NOERROR);

		child.ckid = mmioFOURCC('d', 'a', 't', 'a');

		SR_LOG_RF_BOOL_AUTO(mmioDescend(waveFile, &child, &parent, MMIO_FINDCHUNK) == MMSYSERR_NOERROR);

		DSBUFFERDESC soundBufferDesc;
		soundBufferDesc.dwSize = sizeof(DSBUFFERDESC);
		soundBufferDesc.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLPAN;
		soundBufferDesc.dwBufferBytes = child.cksize;
		soundBufferDesc.dwReserved = 0L;
		soundBufferDesc.lpwfxFormat = &waveFormatEx;
		soundBufferDesc.guid3DAlgorithm = { 0L, 0, 0, { 0, 0, 0, 0, 0, 0, 0, 0 } };

		IDirectSoundBuffer * soundBuffer{ nullptr };
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetSound().GetDirectSound()->CreateSoundBuffer(&soundBufferDesc, &soundBuffer, nullptr));
		SetSoundBuffer(soundBuffer);

		void * write1{ nullptr };
		void * write2{ nullptr };
		DWORD length1{ 0L };
		DWORD length2{ 0L };

		SR_LOG_RF_HR_AUTO(soundBuffer->Lock(0L, child.cksize, &write1, &length1, &write2, &length2, 0));

		if (write1)
		{
			SR_LOG_RF_BOOL_AUTO(mmioRead(waveFile, (HPSTR)write1, length1) == length1);
		}

		if (write2)
		{
			SR_LOG_RF_BOOL_AUTO(mmioRead(waveFile, (HPSTR)write2, length2) == length2);
		}

		SR_LOG_RF_HR_AUTO(soundBuffer->Unlock(write1, length1, write2, length2));

		DSBCAPS soundBufferCapability;
		soundBufferCapability.dwSize = sizeof(DSBCAPS);

		SR_LOG_RF_HR_AUTO(soundBuffer->GetCaps(&soundBufferCapability));
		SetSoundBufferCapability(soundBufferCapability);

		return true;
	}

}