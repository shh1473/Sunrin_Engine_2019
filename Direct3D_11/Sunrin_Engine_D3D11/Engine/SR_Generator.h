#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_Generator : public SR_NonCopyable
	{
	public:
		explicit SR_Generator() noexcept;
		virtual ~SR_Generator() noexcept;

	};

}