#pragma once

#include "SR_PCH.h"
#include "SR_KeyCode.h"

namespace SunrinEngine
{

	class SR_Input
	{
	public:
		explicit SR_Input() noexcept;

		bool Initialize();

		bool UpdateKeyboardInput();
		bool UpdateMouseInput();

		bool KeyPressed(SR_KeyCode key) const noexcept { return (m_oldKeyState[static_cast<unsigned char>(key)] != 0x80) && (m_nowKeyState[static_cast<unsigned char>(key)] == 0x80); }
		bool KeyPressing(SR_KeyCode key) const noexcept { return (m_oldKeyState[static_cast<unsigned char>(key)] == 0x80) && (m_nowKeyState[static_cast<unsigned char>(key)] == 0x80); }
		bool KeyReleased(SR_KeyCode key) const noexcept { return (m_oldKeyState[static_cast<unsigned char>(key)] == 0x80) && (m_nowKeyState[static_cast<unsigned char>(key)] != 0x80); }
		bool KeyReleasing(SR_KeyCode key) const noexcept { return (m_oldKeyState[static_cast<unsigned char>(key)] != 0x80) && (m_nowKeyState[static_cast<unsigned char>(key)] != 0x80); }
		bool MousePressed(unsigned index) const noexcept { return (m_oldMouseState.rgbButtons[index] != 0x80) && (m_nowMouseState.rgbButtons[index] == 0x80); }
		bool MousePressing(unsigned index) const noexcept { return (m_oldMouseState.rgbButtons[index] == 0x80) && (m_nowMouseState.rgbButtons[index] == 0x80); }
		bool MouseReleased(unsigned index) const noexcept { return (m_oldMouseState.rgbButtons[index] == 0x80) && (m_nowMouseState.rgbButtons[index] != 0x80); }
		bool MouseReleasing(unsigned index) const noexcept { return (m_oldMouseState.rgbButtons[index] != 0x80) && (m_nowMouseState.rgbButtons[index] != 0x80); }

		const DIMOUSESTATE2 & GetMouseState() const noexcept { return m_nowMouseState; }

	private:
		unsigned char m_oldKeyState[256];
		unsigned char m_nowKeyState[256];
		DIMOUSESTATE2 m_oldMouseState;
		DIMOUSESTATE2 m_nowMouseState;
		IDirectInput8W *m_directInput;
		IDirectInputDevice8W *m_keyboardInput;
		IDirectInputDevice8W *m_mouseInput;

	};

}