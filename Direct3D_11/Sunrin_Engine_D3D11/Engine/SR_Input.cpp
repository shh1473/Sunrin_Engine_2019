#include "SR_PCH.h"
#include "SR_Input.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_Input::SR_Input() noexcept :
		m_oldKeyState	{},
		m_nowKeyState	{},
		m_oldMouseState	{},
		m_nowMouseState	{},
		m_directInput	{ nullptr },
		m_keyboardInput	{ nullptr },
		m_mouseInput	{ nullptr }
	{

	}

	bool SR_Input::Initialize()
	{
		static HRESULT result{};

		SR_LOG_RF_HR_AUTO(DirectInput8Create(SR_App::GetInstance()->GetWindowInstanceHandle(), DIRECTINPUT_VERSION, IID_IDirectInput8W, reinterpret_cast<void**>(&m_directInput), NULL));

		SR_LOG_RF_HR_AUTO(m_directInput->CreateDevice(GUID_SysKeyboard, &m_keyboardInput, NULL));
		SR_LOG_RF_HR_AUTO(m_keyboardInput->SetDataFormat(&c_dfDIKeyboard));
		SR_LOG_RF_HR_AUTO(m_keyboardInput->SetCooperativeLevel(SR_App::GetInstance()->GetWindowHandle(), DISCL_FOREGROUND | DISCL_EXCLUSIVE));
		result = m_keyboardInput->Acquire();
		SR_LOG_RF_HR_AUTO(result != DIERR_INVALIDPARAM && result != DIERR_NOTINITIALIZED);

		SR_LOG_RF_HR_AUTO(m_directInput->CreateDevice(GUID_SysMouse, &m_mouseInput, NULL));
		SR_LOG_RF_HR_AUTO(m_mouseInput->SetDataFormat(&c_dfDIMouse));;
		SR_LOG_RF_HR_AUTO(m_mouseInput->SetCooperativeLevel(SR_App::GetInstance()->GetWindowHandle(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE));
		result = m_mouseInput->Acquire();
		SR_LOG_RF_HR_AUTO(result != DIERR_INVALIDPARAM && result != DIERR_NOTINITIALIZED);

		return true;
	}

	bool SR_Input::UpdateKeyboardInput()
	{
		static HRESULT result{};

		CopyMemory(m_oldKeyState, m_nowKeyState, sizeof(m_nowKeyState));

		if (FAILED(m_keyboardInput->GetDeviceState(sizeof(m_nowKeyState), reinterpret_cast<void*>(&m_nowKeyState))))
		{
			result = m_keyboardInput->Acquire();
			SR_LOG_RF_HR_AUTO(result != DIERR_INVALIDPARAM && result != DIERR_NOTINITIALIZED);
		}

		return true;
	}

	bool SR_Input::UpdateMouseInput()
	{
		static HRESULT result{};

		CopyMemory(&m_oldMouseState, &m_nowMouseState, sizeof(m_nowMouseState));

		if (FAILED(m_mouseInput->GetDeviceState(sizeof(m_nowMouseState), reinterpret_cast<void*>(&m_nowMouseState))))
		{
			result = m_mouseInput->Acquire();
			SR_LOG_RF_HR_AUTO(result != DIERR_INVALIDPARAM && result != DIERR_NOTINITIALIZED);
		}

		return true;
	}

}