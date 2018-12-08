#pragma once

#include "SR_PCH.h"
#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_Time : public SR_NonCopyable
	{
	public:
		explicit SR_Time() noexcept;

		void Initialize() noexcept;

		void Update();

		unsigned GetFixedUpdateCallCount() noexcept;

		const float GetDeltaTime() const noexcept { return m_deltaTime; }

	private:
		float m_maxFixedTime;
		float m_nowFixedTime;
		float m_deltaTime;
		std::chrono::time_point<std::chrono::steady_clock> m_curTimePoint;
		std::chrono::time_point<std::chrono::steady_clock> m_oldTimePoint;
		std::chrono::duration<float> m_duration;

	};

}