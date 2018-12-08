#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	enum class SR_KeyCode : unsigned char
	{
		Up				= DIK_UP,			// ↑ 방향 키
		Down			= DIK_DOWN,			// ↓ 방향 키
		Left			= DIK_LEFT,			// ← 방향 키
		Right			= DIK_RIGHT,		// → 방향 키

		Num_1			= DIK_1,			// 상단 숫자 1 키
		Num_2			= DIK_2,			// 상단 숫자 2 키
		Num_3			= DIK_3,			// 상단 숫자 3 키
		Num_4			= DIK_4,			// 상단 숫자 4 키
		Num_5			= DIK_5,			// 상단 숫자 5 키
		Num_6			= DIK_6,			// 상단 숫자 6 키
		Num_7			= DIK_7,			// 상단 숫자 7 키
		Num_8			= DIK_8,			// 상단 숫자 8 키
		Num_9			= DIK_9,			// 상단 숫자 9 키
		Num_0			= DIK_0,			// 상단 숫자 0 키

		Pad_1			= DIK_NUMPAD1,		// 패드 숫자 1 키
		Pad_2			= DIK_NUMPAD2,		// 패드 숫자 2 키
		Pad_3			= DIK_NUMPAD3,		// 패드 숫자 3 키
		Pad_4			= DIK_NUMPAD4,		// 패드 숫자 4 키
		Pad_5			= DIK_NUMPAD5,		// 패드 숫자 5 키
		Pad_6			= DIK_NUMPAD6,		// 패드 숫자 6 키
		Pad_7			= DIK_NUMPAD7,		// 패드 숫자 7 키
		Pad_8			= DIK_NUMPAD8,		// 패드 숫자 8 키
		Pad_9			= DIK_NUMPAD9,		// 패드 숫자 9 키
		Pad_0			= DIK_NUMPAD0,		// 패드 숫자 0 키

		Pad_Enter		= DIK_NUMPADENTER,	// 패드 엔터 키
		Pad_Plus		= DIK_ADD,			// 패드 + 키
		Pad_Minus		= DIK_SUBTRACT,		// 패드 - 키
		Pad_Multiply	= DIK_MULTIPLY,		// 패드 * 키
		Pad_Divide		= DIK_DIVIDE,		// 패드 \ 키
		Pad_Decimal		= DIK_DECIMAL,		// 패드 . 키

		F_01			= DIK_F1,			// 상단 펑션 숫자  1 키
		F_02			= DIK_F2,			// 상단 펑션 숫자  2 키
		F_03			= DIK_F3,			// 상단 펑션 숫자  3 키
		F_04			= DIK_F4,			// 상단 펑션 숫자  4 키
		F_05			= DIK_F5,			// 상단 펑션 숫자  5 키
		F_06			= DIK_F6,			// 상단 펑션 숫자  6 키
		F_07			= DIK_F7,			// 상단 펑션 숫자  7 키
		F_08			= DIK_F8,			// 상단 펑션 숫자  8 키
		F_09			= DIK_F9,			// 상단 펑션 숫자  9 키
		F_10			= DIK_F10,			// 상단 펑션 숫자 10 키
		F_11			= DIK_F11,			// 상단 펑션 숫자 11 키
		F_12			= DIK_F12,			// 상단 펑션 숫자 12 키

		A				= DIK_A,			// 알파벳 A 키
		B				= DIK_B,			// 알파벳 B 키
		C				= DIK_C,			// 알파벳 C 키
		D				= DIK_D,			// 알파벳 D 키
		E				= DIK_E,			// 알파벳 E 키
		F				= DIK_F,			// 알파벳 F 키
		G				= DIK_G,			// 알파벳 G 키
		H				= DIK_H,			// 알파벳 H 키
		I				= DIK_I,			// 알파벳 I 키
		J				= DIK_J,			// 알파벳 J 키
		K				= DIK_K,			// 알파벳 K 키
		L				= DIK_L,			// 알파벳 L 키
		M				= DIK_M,			// 알파벳 M 키
		N				= DIK_N,			// 알파벳 N 키
		O				= DIK_O,			// 알파벳 O 키
		P				= DIK_P,			// 알파벳 P 키
		Q				= DIK_Q,			// 알파벳 Q 키
		R				= DIK_R,			// 알파벳 R 키
		S				= DIK_S,			// 알파벳 S 키
		T				= DIK_T,			// 알파벳 T 키
		U				= DIK_U,			// 알파벳 U 키
		V				= DIK_V,			// 알파벳 V 키
		W				= DIK_W,			// 알파벳 W 키
		X				= DIK_X,			// 알파벳 X 키
		Y				= DIK_Y,			// 알파벳 Y 키
		Z				= DIK_Z,			// 알파벳 Z 키

		Escape			= DIK_ESCAPE,		// ESC 키
		Space			= DIK_SPACE,		// 스페이스 키
		Backspace		= DIK_BACK,			// 백스페이스 키
		Enter			= DIK_RETURN,		// 엔터 키
		Tab				= DIK_TAB,			// 탭 키
		Bracket_left	= DIK_LBRACKET,		// 여는 대괄호 키
		Bracket_right	= DIK_RBRACKET,		// 닫는 대괄호 키
		Control_right	= DIK_RCONTROL,		// 오른쪽 컨트롤 키
		Control_left	= DIK_LCONTROL,		// 왼쪽 컨트롤 키
		Alt_left		= DIK_LMENU,		// 왼쪽 알트 키
		Alt_right		= DIK_RMENU,		// 오른쪽 알트 키
		Shift_left		= DIK_LSHIFT,		// 왼쪽 쉬프트 키
		Shift_right		= DIK_RSHIFT,		// 오른쪽 쉬프트 키
		Windows_left	= DIK_LWIN,			// 왼쪽 윈도우 키
		Windows_right	= DIK_RWIN,			// 오른쪽 윈도우 키
		Semicolon		= DIK_SEMICOLON,	// 세미콜론 키
		Apostrophe		= DIK_APOSTROPHE,	// 따옴표 키
		Equals			= DIK_EQUALS,		// 등호 키
		Minus			= DIK_MINUS,		// 마이너스 키
		Grave			= DIK_GRAVE,		// 억음 키
		Comma			= DIK_COMMA,		// 쉼표 키
		Period			= DIK_PERIOD,		// 마침표 키
		Slash			= DIK_SLASH,		// 슬래쉬 키
		Backslash		= DIK_BACKSLASH,	// 백슬래쉬 키
		CapsLock		= DIK_CAPITAL,		// Caps Lock 키
		NumLock			= DIK_NUMLOCK,		// Num Lock 키
		ScrollLock		= DIK_SCROLL,		// Scroll Lock 키
		Volume_mute		= DIK_MUTE,			// 볼륨 음소거 키
		Volume_up		= DIK_VOLUMEUP,		// 볼륨 상승 키
		Volume_down		= DIK_VOLUMEDOWN,	// 볼륨 하락 키
		Playpause		= DIK_PLAYPAUSE,	// 영상 플레이와 중지 키
		Home			= DIK_HOME,			// 홈 키
		End				= DIK_END,			// 엔드 키
		Page_up			= DIK_PRIOR,		// 페이지 업 키
		Page_down		= DIK_NEXT,			// 페이지 다운 키
		PrintScreen		= DIK_SYSRQ,		// 프린트 스크린 키
		Insert			= DIK_INSERT,		// 인서트 키
		Delete			= DIK_DELETE,		// 제거 키
		AppMenu			= DIK_APPS,			// 앱 메뉴 키
	};

}