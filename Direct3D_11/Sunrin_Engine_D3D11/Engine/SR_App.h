#pragma once

#include "SR_PCH.h"
#include "SR_ProgramSettingXML.h"
#include "SR_Log.h"
#include "SR_Time.h"
#include "SR_Input.h"

namespace SunrinEngine
{

	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	class SR_App : public SR_NonCopyable
	{
	public:
		bool Initialize();

		void Run();

		bool DoFrameMove();

		//bool ResizeWindow(unsigned width, unsigned height);

		void HandleMessage(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

		unsigned GetClientWidth() const noexcept { return m_clientWidth; }
		unsigned GetClientHeight() const noexcept { return m_clientHeight; }
		float GetCenterWidth() const noexcept { return m_centerWidth; }
		float GetCenterHeight() const noexcept { return m_centerHeight; }
		HWND GetWindowHandle() const noexcept { return m_windowHandle; }
		HINSTANCE GetWindowInstanceHandle() const noexcept { return m_windowInstanceHandle; }
		SR_Log & GetLog() noexcept { return m_log; }
		SR_Time & GetTime() noexcept { return m_time; }
		SR_Input & GetInput() noexcept { return m_input; }

	public:
		static void CreateInstance();
		static const std::unique_ptr<SR_App> & GetInstance() noexcept;

	private:
		explicit SR_App() noexcept;

		bool InitializeProgramSettingXML();
		bool InitializeWindow();
		bool InitializeDGraphic();
		bool InitializeDSound();
		bool InitializeLog();
		bool InitializeTime();
		bool InitializeInput();

	private:
		static std::unique_ptr<SR_App> M_instance;

		bool m_isWindowResized;
		unsigned m_clientWidth;
		unsigned m_clientHeight;
		float m_centerWidth;
		float m_centerHeight;
		HWND m_windowHandle;
		HINSTANCE m_windowInstanceHandle;
		SR_ProgramSettingXML m_programSettingXML;
		SR_Log m_log;
		SR_Time m_time;
		SR_Input m_input;

	};

}

#pragma region MACRO

#define SR_LOG_BOOL(b, s)													\
{																			\
	if (!(b))																\
	{																		\
		SunrinEngine::SR_App::GetInstance()->GetLog().WriteLine((s));		\
	}																		\
}
#define SR_LOG_HR(hr, s)													\
{																			\
	if (FAILED((hr)))														\
	{																		\
		SunrinEngine::SR_App::GetInstance()->GetLog().WriteLine((s));		\
	}																		\
}
#define SR_LOG_BOOL_AUTO(b)													\
{																			\
	if (!(b))																\
	{																		\
		SunrinEngine::SR_App::GetInstance()->GetLog().WriteLine((L#b));		\
	}																		\
}
#define SR_LOG_HR_AUTO(hr)													\
{																			\
	if (FAILED((hr)))														\
	{																		\
		SunrinEngine::SR_App::GetInstance()->GetLog().WriteLine((L#hr));	\
	}																		\
}
#define SR_LOG_RF_FORCE(s)													\
{																			\
	SunrinEngine::SR_App::GetInstance()->GetLog().WriteLine((s));			\
	return false;															\
}
#define SR_LOG_RF_BOOL(b, s)												\
{																			\
	if (!(b))																\
	{																		\
		SunrinEngine::SR_App::GetInstance()->GetLog().WriteLine((s));		\
		return false;														\
	}																		\
}
#define SR_LOG_RF_HR(hr, s)													\
{																			\
	if (FAILED((hr)))														\
	{																		\
		SunrinEngine::SR_App::GetInstance()->GetLog().WriteLine((s));		\
		return false;														\
	}																		\
}
#define SR_LOG_RF_BOOL_AUTO(b)												\
{																			\
	if (!(b))																\
	{																		\
		SunrinEngine::SR_App::GetInstance()->GetLog().WriteLine((L#b));		\
		return false;														\
	}																		\
}
#define SR_LOG_RF_HR_AUTO(hr)												\
{																			\
	if (FAILED((hr)))														\
	{																		\
		SunrinEngine::SR_App::GetInstance()->GetLog().WriteLine((L#hr));	\
		return false;														\
	}																		\
}

#pragma endregion