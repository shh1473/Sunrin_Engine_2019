#pragma once

#include "SR_CommonSound.h"

namespace SunrinEngine
{

	class SR_WavSound : public SR_CommonSound
	{
	public:
		explicit SR_WavSound(const std::wstring & name) noexcept;

		bool CreateSound(const std::wstring & filePath);

	};

}