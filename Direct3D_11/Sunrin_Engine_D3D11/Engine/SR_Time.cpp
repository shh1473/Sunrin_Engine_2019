#include "SR_PCH.h"
#include "SR_Time.h"

namespace SunrinEngine
{

	SR_Time::SR_Time() noexcept :
		m_maxFixedTime	{ 0.0f },
		m_nowFixedTime	{ 0.0f },
		m_deltaTime		{ 0.0f },
		m_curTimePoint	{},
		m_oldTimePoint	{},
		m_duration		{}
	{

	}

	void SR_Time::Initialize() noexcept
	{
		m_maxFixedTime = 1.0f / 50.0f;

		m_curTimePoint = std::chrono::steady_clock::now();
		m_oldTimePoint = std::chrono::steady_clock::now();
	}

	void SR_Time::Update()
	{
		m_curTimePoint = std::chrono::steady_clock::now();
		m_duration = m_curTimePoint - m_oldTimePoint;
		m_oldTimePoint = m_curTimePoint;

		m_deltaTime = m_duration.count();
	}

	unsigned SR_Time::GetFixedUpdateCallCount() noexcept
	{
		static unsigned count{ 0 };

		count = 0;

		m_nowFixedTime += m_deltaTime;

		while (m_nowFixedTime > m_maxFixedTime)
		{
			++count;

			m_nowFixedTime -= m_maxFixedTime;
		}

		return count;
	}

}