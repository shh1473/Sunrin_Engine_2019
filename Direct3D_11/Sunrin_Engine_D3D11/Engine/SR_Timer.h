#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_Timer : public SR_NonCopyable
	{
	public:
		explicit SR_Timer() noexcept;

		bool Update();

		void Start();
		void Stop();
		void Reset();

		void SetIsActivated(bool isActivated) noexcept { m_isActivated = isActivated; }
		void SetIsEndless(bool isEndless) noexcept { m_isEndless = isEndless; }
		void SetRepeatCount(unsigned repeatCount) noexcept { m_maxRepeatCount = repeatCount; }
		void SetTargetTime(float targetTime) noexcept { m_targetTime = targetTime; }
		void SetFunction(const std::function<bool(void)> & function) noexcept { m_function = function; }

		bool GetIsActivated() const noexcept { return m_isActivated; }
		unsigned GetNowRepeatCount() const noexcept { return m_nowRepeatCount; }

	private:
		bool m_isActivated;
		bool m_isEndless;
		unsigned m_maxRepeatCount;
		unsigned m_nowRepeatCount;
		float m_targetTime;
		float m_currentTime;
		std::function<bool(void)> m_function;

	};

}