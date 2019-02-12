#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_Executor : public SR_NonCopyable
	{
	public:
		explicit SR_Executor() noexcept;
		virtual ~SR_Executor() noexcept;

	};

}