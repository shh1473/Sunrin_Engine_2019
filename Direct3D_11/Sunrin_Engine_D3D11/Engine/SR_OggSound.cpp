#include "SR_PCH.h"

#include "SR_OggSound.h"
#include "SR_App.h"
#include "SR_Converter.h"

namespace SunrinEngine
{

	SR_OggSound::SR_OggSound(const std::wstring & name) noexcept :
		SR_CommonSound(name)
	{

	}

	bool SR_OggSound::CreateSound(const std::wstring & filePath)
	{
		std::string path{ "Resources\\Sounds\\" + SR_Converter::ToAscii(filePath) };

		FILE * file;
		SR_LOG_RF_BOOL_AUTO(fopen_s(&file, path.c_str(), "rb") == 0);
		std::unique_ptr<FILE, std::function<void(FILE*)>> unique_file{
			file,
			[](FILE *p) { fclose(p); } };

		OggVorbis_File oggVorbisFile;
		SR_LOG_RF_BOOL_AUTO(ov_open(file, &oggVorbisFile, nullptr, 0L) == 0);

		vorbis_info *vorbisInfo{ ov_info(&oggVorbisFile, -1) };
		SR_LOG_RF_BOOL_AUTO(vorbisInfo);

		WAVEFORMATEX waveFormatEx;
		waveFormatEx.wFormatTag = 1;
		waveFormatEx.nChannels = vorbisInfo->channels;
		waveFormatEx.nSamplesPerSec = vorbisInfo->rate;
		waveFormatEx.nAvgBytesPerSec = vorbisInfo->rate * vorbisInfo->channels * 2;
		waveFormatEx.nBlockAlign = vorbisInfo->channels * 2;
		waveFormatEx.wBitsPerSample = 16;
		waveFormatEx.cbSize = sizeof(WAVEFORMATEX);

		DSBUFFERDESC soundBufferDesc;
		soundBufferDesc.dwSize = sizeof(DSBUFFERDESC);
		soundBufferDesc.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLPAN;
		soundBufferDesc.dwBufferBytes = 1048576L * 60L;
		soundBufferDesc.dwReserved = 0L;
		soundBufferDesc.lpwfxFormat = &waveFormatEx;
		soundBufferDesc.guid3DAlgorithm = { 0L, 0, 0,{ 0, 0, 0, 0, 0, 0, 0, 0 } };

		Microsoft::WRL::ComPtr<IDirectSoundBuffer> tempBuffer{ nullptr };
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetSound().GetDirectSound()->CreateSoundBuffer(&soundBufferDesc, &tempBuffer, nullptr));

		void * tempWrite{ nullptr };
		void * write{ nullptr };
		DWORD size{ soundBufferDesc.dwBufferBytes };
		DWORD position{ 0L };
		int bitstream{ 0 };
		long result{ 1L };

		SR_LOG_RF_HR_AUTO(tempBuffer->Lock(0L, soundBufferDesc.dwBufferBytes, &tempWrite, &size, nullptr, nullptr, DSBLOCK_ENTIREBUFFER));

		do {
			result = ov_read(&oggVorbisFile, reinterpret_cast<char*>(tempWrite) + position, size - position, 0, 2, 1, &bitstream);
			position += result;
		} while (result && position < size);

		SR_LOG_RF_HR_AUTO(tempBuffer->Unlock(tempWrite, size, nullptr, 0L));

		size = soundBufferDesc.dwBufferBytes = position;

		IDirectSoundBuffer * soundBuffer{ nullptr };
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetSound().GetDirectSound()->CreateSoundBuffer(&soundBufferDesc, &soundBuffer, nullptr));
		SetSoundBuffer(soundBuffer);

		SR_LOG_RF_HR_AUTO(soundBuffer->Lock(0L, soundBufferDesc.dwBufferBytes, &write, &size, nullptr, nullptr, DSBLOCK_ENTIREBUFFER));

		CopyMemory(write, tempWrite, size);

		SR_LOG_RF_HR_AUTO(soundBuffer->Unlock(write, size, nullptr, 0L));

		SR_LOG_RF_BOOL_AUTO(ov_clear(&oggVorbisFile) == 0);

		DSBCAPS soundBufferCapability;
		soundBufferCapability.dwSize = sizeof(DSBCAPS);

		SR_LOG_RF_HR_AUTO(soundBuffer->GetCaps(&soundBufferCapability));
		SetSoundBufferCapability(soundBufferCapability);

		return true;
	}

}