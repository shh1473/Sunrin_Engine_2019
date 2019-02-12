#include "SR_PCH.h"

#include "SR_Timer.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_Timer::SR_Timer() noexcept :
		m_isActivated		{ false },
		m_isEndless			{ false },
		m_maxRepeatCount	{ 1 },
		m_nowRepeatCount	{ 0 },
		m_targetTime		{ 0.0f },
		m_currentTime		{ 0.0f },
		m_function			{ []() { return true; } }
	{

	}

	bool SR_Timer::Update()
	{
		if (m_isActivated && (m_isEndless || (m_maxRepeatCount > m_nowRepeatCount)))
		{
			m_currentTime += SR_App::GetInstance()->GetTime().GetDeltaTime();

			if (m_targetTime < m_currentTime)
			{
				m_currentTime -= m_targetTime;

				if (!m_isEndless)
				{
					++m_nowRepeatCount;
				}

				SR_RF_BOOL(m_function());
			}
		}

		return true;
	}

	void SR_Timer::Start()
	{
		m_isActivated = true;
	}

	void SR_Timer::Stop()
	{
		m_isActivated = false;
	}

	void SR_Timer::Reset()
	{
		m_isActivated = false;
		m_isEndless = false;
		m_nowRepeatCount = 0;
		m_currentTime = 0.0f;
	}

}