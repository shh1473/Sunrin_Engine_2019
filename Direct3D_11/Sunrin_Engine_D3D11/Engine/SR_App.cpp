#include "SR_PCH.h"
#include "SR_App.h"
#include "SR_Converter.h"

namespace SunrinEngine
{

	std::unique_ptr<SR_App> SR_App::m_instance{};

	SR_App::SR_App() noexcept :
		m_isWindowResized		{},
		m_clientWidth			{},
		m_clientHeight			{},
		m_centerWidth			{},
		m_centerHeight			{},
		m_windowHandle			{},
		m_windowInstanceHandle	{},
		m_programSettingXML		{},
		m_log					{},
		m_time					{},
		m_input					{}
	{
		
	}

	bool SR_App::Initialize()
	{
		SR_RF_BOOL(InitializeLog());
		SR_RF_BOOL(InitializeProgramSettingXML());
		SR_RF_BOOL(InitializeWindow());
		SR_RF_BOOL(InitializeTime());
		SR_RF_BOOL(InitializeInput());

		return true;
	}

	void SR_App::Run()
	{
		MSG message;
		ZeroMemory(&message, sizeof(MSG));

		while (message.message != WM_QUIT)
		{
			if (PeekMessageW(&message, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&message);
				DispatchMessageW(&message);
			}
			else
			{
				if (!DoFrameMove())
				{
					DestroyWindow(m_windowHandle);
				}
			}
		}
	}

	bool SR_App::DoFrameMove()
	{
		return true;
	}

	void SR_App::HandleMessage(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
	{
		switch (iMessage)
		{
			case WM_SIZE:
			{
				if (m_isWindowResized)
				{
					m_isWindowResized = false;

					RECT rt{ 0L, 0L, 0L, 0L };
					SR_LOG_BOOL_AUTO(GetWindowRect(m_windowHandle, &rt));

					m_programSettingXML.SetWindowWidth(static_cast<unsigned>(rt.right));
					m_programSettingXML.SetWindowHeight(static_cast<unsigned>(rt.bottom));

					//ODK_LOG_BOOL_AUTO(m_DGraphic->ResizeSwapChainBuffers(m_clientWidth, m_clientHeight));
				}
			}
			break;
			case WM_DESTROY:
			{
				RECT rt{ 0L, 0L, 0L, 0L };
				SR_LOG_BOOL_AUTO(GetWindowRect(m_windowHandle, &rt));

				m_programSettingXML.SetWindowPositionX(static_cast<unsigned>(rt.left));
				m_programSettingXML.SetWindowPositionY(static_cast<unsigned>(rt.top));

				m_programSettingXML.Save();
			}
			break;
		}
	}

	void SR_App::CreateInstance()
	{
		m_instance.reset(new SR_App());
	}

	const std::unique_ptr<SR_App> & SR_App::GetInstance() noexcept
	{
		return m_instance;
	}

	bool SR_App::InitializeProgramSettingXML()
	{
		m_programSettingXML.Initialize();

		return true;
	}

	bool SR_App::InitializeWindow()
	{
		m_windowInstanceHandle = GetModuleHandleW(NULL);
		SR_LOG_RF_BOOL(m_windowInstanceHandle,
					   L"윈도우 인스턴스의 핸들을 가져오는 데 실패했습니다.");

		std::wstring windowTitle{ SR_Converter::ToUnicode(m_programSettingXML.GetWindowTitle()) };

		WNDCLASSEXW windowClass;
		ZeroMemory(&windowClass, sizeof(WNDCLASSEXW));
		windowClass.cbSize = sizeof(WNDCLASSEXW);
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = 0;
		windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		windowClass.hCursor = LoadCursorW(NULL, IDC_ARROW);
		windowClass.hIcon = LoadIconW(NULL, IDI_APPLICATION);
		windowClass.hIconSm = LoadIconW(NULL, IDI_APPLICATION);
		windowClass.hInstance = m_windowInstanceHandle;
		windowClass.lpfnWndProc = WndProc;
		windowClass.lpszClassName = windowTitle.c_str();
		windowClass.lpszMenuName = NULL;
		windowClass.style = CS_HREDRAW | CS_VREDRAW;

		SR_LOG_RF_BOOL_AUTO(RegisterClassExW(&windowClass));

		m_windowHandle = CreateWindowExW(
			WS_EX_APPWINDOW,
			windowTitle.c_str(),
			windowTitle.c_str(),
			WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
			m_programSettingXML.GetWindowPositionX(), m_programSettingXML.GetWindowPositionY(),
			m_programSettingXML.GetWindowWidth(), m_programSettingXML.GetWindowHeight(),
			NULL, NULL, m_windowInstanceHandle, NULL);
		SR_LOG_RF_BOOL(m_windowHandle,
					   L"윈도우를 생성하는 데 실패했습니다.");

		ShowWindow(m_windowHandle, SW_SHOW);

		RECT rt{ 0L, 0L, 0L, 0L };
		SR_LOG_BOOL_AUTO(GetClientRect(m_windowHandle, &rt));

		m_clientWidth = rt.right;
		m_clientHeight = rt.bottom;
		m_centerWidth = static_cast<float>(m_clientWidth) * 0.5f;
		m_centerHeight = static_cast<float>(m_clientHeight) * 0.5f;
		m_centerHeight = static_cast<float>(m_clientHeight) * 0.5f;

		return true;
	}

	bool SR_App::InitializeDGraphic()
	{
		return true;
	}

	bool SR_App::InitializeDSound()
	{
		return true;
	}

	bool SR_App::InitializeLog()
	{
		SR_RF_BOOL(m_log.Initialize());

		return true;
	}

	bool SR_App::InitializeTime()
	{
		m_time.Initialize();

		return true;
	}

	bool SR_App::InitializeInput()
	{
		SR_RF_BOOL(m_input.Initialize());

		return true;
	}

	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
	{
		SR_App::GetInstance()->HandleMessage(hWnd, iMessage, wParam, lParam);

		switch (iMessage)
		{
			case WM_DESTROY:
				PostQuitMessage(0);
				return 0;
		}

		return DefWindowProcW(hWnd, iMessage, wParam, lParam);
	}

}