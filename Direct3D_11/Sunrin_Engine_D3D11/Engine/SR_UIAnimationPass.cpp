#include "SR_PCH.h"

#include "SR_UIAnimationPass.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_UIAnimationPass::SR_UIAnimationPass(SR_UIComponent * owner, unsigned effectSlotCount) :
		SR_UIPass(owner, effectSlotCount),
		m_isPlaying			{ false },
		m_isEnableLoop		{ false },
		m_startFrameIndex	{ 0 },
		m_endFrameIndex		{ 0 },
		m_currentFrameIndex	{ 0 },
		m_widthRatio		{ 1.0f },
		m_cycleTime			{ 0.0f },
		m_targetTime		{ 0.0f },
		m_currentTime		{ 0.0f }
	{

	}

	bool SR_UIAnimationPass::Update()
	{
		if (m_isPlaying)
		{
			if (m_currentTime >= m_targetTime)
			{
				if (++m_currentFrameIndex > m_endFrameIndex)
				{
					m_currentFrameIndex = m_startFrameIndex;

					if (!m_isEnableLoop)
					{
						m_isPlaying = false;
					}
				}

				m_currentTime -= m_targetTime;
			}

			m_currentTime += SR_App::GetInstance()->GetTime().GetDeltaTime();
		}

		return true;
	}

	void SR_UIAnimationPass::Play()
	{
		m_isPlaying = true;
	}

	void SR_UIAnimationPass::Pause()
	{
		m_isPlaying = false;
	}

	void SR_UIAnimationPass::Reset()
	{
		m_isPlaying = false;
		m_currentFrameIndex = m_startFrameIndex;
		m_currentTime = 0.0f;
	}

	void SR_UIAnimationPass::SetStartFrameIndex(unsigned index)
	{
		m_startFrameIndex = index;
		m_widthRatio = 1.0f / static_cast<float>(m_endFrameIndex - m_startFrameIndex + 1);
		m_targetTime = m_cycleTime / static_cast<float>(m_endFrameIndex - m_startFrameIndex + 1);
	}

	void SR_UIAnimationPass::SetEndFrameIndex(unsigned index)
	{
		m_endFrameIndex = index;
		m_widthRatio = 1.0f / static_cast<float>(m_endFrameIndex - m_startFrameIndex + 1);
		m_targetTime = m_cycleTime / static_cast<float>(m_endFrameIndex - m_startFrameIndex + 1);
	}

	void SR_UIAnimationPass::SetCycleTime(float cycleTime)
	{
		m_cycleTime = cycleTime;
		m_targetTime = m_cycleTime / static_cast<float>(m_endFrameIndex - m_startFrameIndex + 1);
	}

	void SR_UIAnimationPass::UpdateVisibleRect()
	{
		SetVisibleRect(
			(GetSize().x * static_cast<float>(m_currentFrameIndex) + GetSize().x * GetRatio().left) * m_widthRatio,
			GetSize().y * GetRatio().top,
			(GetSize().x * static_cast<float>(m_currentFrameIndex) + GetSize().x * GetRatio().right) * m_widthRatio,
			GetSize().y * GetRatio().bottom);
	}

}