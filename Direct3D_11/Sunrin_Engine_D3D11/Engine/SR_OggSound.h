#pragma once

#include "SR_CommonSound.h"

#include "ExternalLibrary\Vorbis\include\vorbisfile.h"

#pragma comment(lib, "Engine/ExternalLibrary/Vorbis/lib/ogg_static.lib")
#pragma comment(lib, "Engine/ExternalLibrary/Vorbis/lib/vorbis_static.lib")
#pragma comment(lib, "Engine/ExternalLibrary/Vorbis/lib/vorbisfile_static.lib")

namespace SunrinEngine
{

	class SR_OggSound : public SR_CommonSound
	{
	public:
		explicit SR_OggSound(const std::wstring & name) noexcept;

		bool CreateSound(const std::wstring & filePath);

	};

}