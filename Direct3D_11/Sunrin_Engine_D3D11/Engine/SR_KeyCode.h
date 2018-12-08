#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	enum class SR_KeyCode : unsigned char
	{
		Up				= DIK_UP,			// �� ���� Ű
		Down			= DIK_DOWN,			// �� ���� Ű
		Left			= DIK_LEFT,			// �� ���� Ű
		Right			= DIK_RIGHT,		// �� ���� Ű

		Num_1			= DIK_1,			// ��� ���� 1 Ű
		Num_2			= DIK_2,			// ��� ���� 2 Ű
		Num_3			= DIK_3,			// ��� ���� 3 Ű
		Num_4			= DIK_4,			// ��� ���� 4 Ű
		Num_5			= DIK_5,			// ��� ���� 5 Ű
		Num_6			= DIK_6,			// ��� ���� 6 Ű
		Num_7			= DIK_7,			// ��� ���� 7 Ű
		Num_8			= DIK_8,			// ��� ���� 8 Ű
		Num_9			= DIK_9,			// ��� ���� 9 Ű
		Num_0			= DIK_0,			// ��� ���� 0 Ű

		Pad_1			= DIK_NUMPAD1,		// �е� ���� 1 Ű
		Pad_2			= DIK_NUMPAD2,		// �е� ���� 2 Ű
		Pad_3			= DIK_NUMPAD3,		// �е� ���� 3 Ű
		Pad_4			= DIK_NUMPAD4,		// �е� ���� 4 Ű
		Pad_5			= DIK_NUMPAD5,		// �е� ���� 5 Ű
		Pad_6			= DIK_NUMPAD6,		// �е� ���� 6 Ű
		Pad_7			= DIK_NUMPAD7,		// �е� ���� 7 Ű
		Pad_8			= DIK_NUMPAD8,		// �е� ���� 8 Ű
		Pad_9			= DIK_NUMPAD9,		// �е� ���� 9 Ű
		Pad_0			= DIK_NUMPAD0,		// �е� ���� 0 Ű

		Pad_Enter		= DIK_NUMPADENTER,	// �е� ���� Ű
		Pad_Plus		= DIK_ADD,			// �е� + Ű
		Pad_Minus		= DIK_SUBTRACT,		// �е� - Ű
		Pad_Multiply	= DIK_MULTIPLY,		// �е� * Ű
		Pad_Divide		= DIK_DIVIDE,		// �е� \ Ű
		Pad_Decimal		= DIK_DECIMAL,		// �е� . Ű

		F_01			= DIK_F1,			// ��� ��� ����  1 Ű
		F_02			= DIK_F2,			// ��� ��� ����  2 Ű
		F_03			= DIK_F3,			// ��� ��� ����  3 Ű
		F_04			= DIK_F4,			// ��� ��� ����  4 Ű
		F_05			= DIK_F5,			// ��� ��� ����  5 Ű
		F_06			= DIK_F6,			// ��� ��� ����  6 Ű
		F_07			= DIK_F7,			// ��� ��� ����  7 Ű
		F_08			= DIK_F8,			// ��� ��� ����  8 Ű
		F_09			= DIK_F9,			// ��� ��� ����  9 Ű
		F_10			= DIK_F10,			// ��� ��� ���� 10 Ű
		F_11			= DIK_F11,			// ��� ��� ���� 11 Ű
		F_12			= DIK_F12,			// ��� ��� ���� 12 Ű

		A				= DIK_A,			// ���ĺ� A Ű
		B				= DIK_B,			// ���ĺ� B Ű
		C				= DIK_C,			// ���ĺ� C Ű
		D				= DIK_D,			// ���ĺ� D Ű
		E				= DIK_E,			// ���ĺ� E Ű
		F				= DIK_F,			// ���ĺ� F Ű
		G				= DIK_G,			// ���ĺ� G Ű
		H				= DIK_H,			// ���ĺ� H Ű
		I				= DIK_I,			// ���ĺ� I Ű
		J				= DIK_J,			// ���ĺ� J Ű
		K				= DIK_K,			// ���ĺ� K Ű
		L				= DIK_L,			// ���ĺ� L Ű
		M				= DIK_M,			// ���ĺ� M Ű
		N				= DIK_N,			// ���ĺ� N Ű
		O				= DIK_O,			// ���ĺ� O Ű
		P				= DIK_P,			// ���ĺ� P Ű
		Q				= DIK_Q,			// ���ĺ� Q Ű
		R				= DIK_R,			// ���ĺ� R Ű
		S				= DIK_S,			// ���ĺ� S Ű
		T				= DIK_T,			// ���ĺ� T Ű
		U				= DIK_U,			// ���ĺ� U Ű
		V				= DIK_V,			// ���ĺ� V Ű
		W				= DIK_W,			// ���ĺ� W Ű
		X				= DIK_X,			// ���ĺ� X Ű
		Y				= DIK_Y,			// ���ĺ� Y Ű
		Z				= DIK_Z,			// ���ĺ� Z Ű

		Escape			= DIK_ESCAPE,		// ESC Ű
		Space			= DIK_SPACE,		// �����̽� Ű
		Backspace		= DIK_BACK,			// �齺���̽� Ű
		Enter			= DIK_RETURN,		// ���� Ű
		Tab				= DIK_TAB,			// �� Ű
		Bracket_left	= DIK_LBRACKET,		// ���� ���ȣ Ű
		Bracket_right	= DIK_RBRACKET,		// �ݴ� ���ȣ Ű
		Control_right	= DIK_RCONTROL,		// ������ ��Ʈ�� Ű
		Control_left	= DIK_LCONTROL,		// ���� ��Ʈ�� Ű
		Alt_left		= DIK_LMENU,		// ���� ��Ʈ Ű
		Alt_right		= DIK_RMENU,		// ������ ��Ʈ Ű
		Shift_left		= DIK_LSHIFT,		// ���� ����Ʈ Ű
		Shift_right		= DIK_RSHIFT,		// ������ ����Ʈ Ű
		Windows_left	= DIK_LWIN,			// ���� ������ Ű
		Windows_right	= DIK_RWIN,			// ������ ������ Ű
		Semicolon		= DIK_SEMICOLON,	// �����ݷ� Ű
		Apostrophe		= DIK_APOSTROPHE,	// ����ǥ Ű
		Equals			= DIK_EQUALS,		// ��ȣ Ű
		Minus			= DIK_MINUS,		// ���̳ʽ� Ű
		Grave			= DIK_GRAVE,		// ���� Ű
		Comma			= DIK_COMMA,		// ��ǥ Ű
		Period			= DIK_PERIOD,		// ��ħǥ Ű
		Slash			= DIK_SLASH,		// ������ Ű
		Backslash		= DIK_BACKSLASH,	// �齽���� Ű
		CapsLock		= DIK_CAPITAL,		// Caps Lock Ű
		NumLock			= DIK_NUMLOCK,		// Num Lock Ű
		ScrollLock		= DIK_SCROLL,		// Scroll Lock Ű
		Volume_mute		= DIK_MUTE,			// ���� ���Ұ� Ű
		Volume_up		= DIK_VOLUMEUP,		// ���� ��� Ű
		Volume_down		= DIK_VOLUMEDOWN,	// ���� �϶� Ű
		Playpause		= DIK_PLAYPAUSE,	// ���� �÷��̿� ���� Ű
		Home			= DIK_HOME,			// Ȩ Ű
		End				= DIK_END,			// ���� Ű
		Page_up			= DIK_PRIOR,		// ������ �� Ű
		Page_down		= DIK_NEXT,			// ������ �ٿ� Ű
		PrintScreen		= DIK_SYSRQ,		// ����Ʈ ��ũ�� Ű
		Insert			= DIK_INSERT,		// �μ�Ʈ Ű
		Delete			= DIK_DELETE,		// ���� Ű
		AppMenu			= DIK_APPS,			// �� �޴� Ű
	};

}