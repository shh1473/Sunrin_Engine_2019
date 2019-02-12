#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_Task : public SR_NonCopyable
	{
	public:
		explicit SR_Task() noexcept;

		virtual void SetThreadID(unsigned threadID) noexcept { m_threadID = threadID; }

		unsigned GetThreadID() const noexcept { return m_threadID; }

	private:
		unsigned m_threadID;

	};

}