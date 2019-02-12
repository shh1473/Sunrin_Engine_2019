#pragma once

#include "SR_UIPass.h"

namespace SunrinEngine
{

	class SR_UIAnimationPass : public SR_UIPass
	{
	public:
		explicit SR_UIAnimationPass(SR_UIComponent * owner, unsigned effectSlotCount);

		virtual bool Update() override;
		virtual void UpdateVisibleRect() override;

		void Play();
		void Pause();
		void Reset();

		void SetIsEnableLoop(bool isEnable) { m_isEnableLoop = isEnable; }
		void SetStartFrameIndex(unsigned index);
		void SetEndFrameIndex(unsigned index);
		void SetCycleTime(float cycleTime);

	private:
		bool m_isPlaying;
		bool m_isEnableLoop;
		unsigned m_startFrameIndex;
		unsigned m_endFrameIndex;
		unsigned m_currentFrameIndex;
		float m_widthRatio;
		float m_frameRatio;
		float m_cycleTime;
		float m_targetTime;
		float m_currentTime;

	};

}