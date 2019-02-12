#include "SR_PCH.h"

#include "SR_App.h"

namespace SunrinEngine
{

	std::unique_ptr<SR_App> SR_App::m_INSTANCE{ nullptr };

	SR_App::SR_App() noexcept :
		m_isWindowResized		{ false },
		m_windowWidth			{ 0 },
		m_windowHeight			{ 0 },
		m_clientWidth			{ 0 },
		m_clientHeight			{ 0 },
		m_centerWidth			{ 0.0f },
		m_centerHeight			{ 0.0f },
		m_windowHandle			{ NULL },
		m_windowInstanceHandle	{ NULL },
		m_programSettingXML		{},
		m_log					{},
		m_time					{},
		m_input					{},
		m_graphic				{},
		m_sound					{},
		m_scene					{}
	{
		
	}

	bool SR_App::Initialize()
	{
		SR_RF_BOOL(InitializeLog());
		SR_RF_BOOL(InitializeProgramSettingXML());
		SR_RF_BOOL(InitializeWindow());
		SR_RF_BOOL(InitializeTime());
		SR_RF_BOOL(InitializeInput());
		SR_RF_BOOL(InitializeGraphic());
		SR_RF_BOOL(InitializeSound());
		SR_RF_BOOL(InitializeScene());

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
		SR_RF_BOOL(m_input.UpdateKeyboardInput());
		SR_RF_BOOL(m_input.UpdateMouseInput());

		m_time.Update();

		m_scene.UpdateScene();

		for (unsigned i{ 0 }; i < m_time.GetFixedUpdateCallCount(); ++i)
		{
			SR_RF_BOOL(m_scene.FixedUpdate());
		}

		SR_RF_BOOL(m_scene.Update());
		SR_RF_BOOL(m_scene.LateUpdate());
		SR_RF_BOOL(m_scene.Render());

		SR_RF_BOOL(m_graphic.Present());

		return true;
	}

	bool SR_App::ChangeResolution(unsigned width, unsigned height)
	{
		m_isWindowResized = true;

		m_clientWidth = width;
		m_clientHeight = height;
		m_windowWidth = m_clientWidth + SR_WINDOW_BORDER_LENGTH_X;
		m_windowHeight = m_clientHeight + SR_WINDOW_BORDER_LENGTH_Y;
		m_centerWidth = static_cast<float>(m_clientWidth) * 0.5f;
		m_centerHeight = static_cast<float>(m_clientHeight) * 0.5f;

		m_graphic.ResizeTarget(m_clientWidth, m_clientHeight);

		return false;
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

					SR_LOG_BOOL_AUTO(m_graphic.ResizeBuffers(m_clientWidth, m_clientHeight));
				}
			}
			break;
			case WM_DESTROY:
			{
				RECT rt{ 0L, 0L, 0L, 0L };
				SR_LOG_BOOL_AUTO(GetWindowRect(m_windowHandle, &rt));

				m_programSettingXML.SetWindowPositionX(static_cast<unsigned>(rt.left));
				m_programSettingXML.SetWindowPositionY(static_cast<unsigned>(rt.top));
				m_programSettingXML.SetClientWidth(m_clientWidth);
				m_programSettingXML.SetClientHeight(m_clientHeight);

				m_programSettingXML.Save();
			}
			break;
		}
	}

	void SR_App::CreateInstance()
	{
		m_INSTANCE.reset(new SR_App());
	}

	const std::unique_ptr<SR_App> & SR_App::GetInstance() noexcept
	{
		return m_INSTANCE;
	}

	bool SR_App::InitializeLog()
	{
		SR_RF_BOOL(m_log.Initialize());

		return true;
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
		windowClass.lpszClassName = m_programSettingXML.GetWindowTitle().c_str();
		windowClass.lpszMenuName = NULL;
		windowClass.style = CS_HREDRAW | CS_VREDRAW;

		SR_LOG_RF_BOOL_AUTO(RegisterClassExW(&windowClass));

		m_clientWidth = m_programSettingXML.GetClientWidth();
		m_clientHeight = m_programSettingXML.GetClientHeight();
		m_windowWidth = m_clientWidth + SR_WINDOW_BORDER_LENGTH_X;
		m_windowHeight = m_clientHeight + SR_WINDOW_BORDER_LENGTH_Y;
		m_centerWidth = static_cast<float>(m_clientWidth) * 0.5f;
		m_centerHeight = static_cast<float>(m_clientHeight) * 0.5f;

		m_windowHandle = CreateWindowExW(
			WS_EX_APPWINDOW,
			m_programSettingXML.GetWindowTitle().c_str(),
			m_programSettingXML.GetWindowTitle().c_str(),
			WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
			m_programSettingXML.GetWindowPositionX(), m_programSettingXML.GetWindowPositionY(),
			m_windowWidth, m_windowHeight,
			NULL, NULL, m_windowInstanceHandle, NULL);
		SR_LOG_RF_BOOL(m_windowHandle,
					   L"윈도우를 생성하는 데 실패했습니다.");

		ShowWindow(m_windowHandle, SW_SHOW);

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

	bool SR_App::InitializeGraphic()
	{
		SR_RF_BOOL(m_graphic.Initialize());

		return true;
	}

	bool SR_App::InitializeSound()
	{
		SR_RF_BOOL(m_sound.Initialize());

		return true;
	}

	bool SR_App::InitializeScene()
	{
		SR_RF_BOOL(m_scene.Initialize());

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