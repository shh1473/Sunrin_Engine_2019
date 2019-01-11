#pragma once

#define DIRECTINPUT_VERSION 0x0800

// C 헤더
#include <windows.h>
#include <assert.h>
#include <wincodec.h>

#pragma comment(lib, "winmm.lib")

// C++ 헤더
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <map>
#include <utility>
#include <exception>
#include <functional>
#include <memory>
#include <algorithm>
#include <codecvt>
#include <type_traits>
#include <typeindex>
#include <random>
#include <chrono>

// DXGI 헤더
#include <dxgi1_6.h>

#pragma comment(lib, "dxgi.lib")

// D3D / D2D 헤더
#include <d3d11_4.h>
#include <d2d1_3.h>
#include <d2d1_3helper.h>
#include <d3dcommon.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <directxpackedvector.h>
#include <directxcolors.h>
#include <directxcollision.h>
#include <dwrite_3.h>
#include <dinput.h>
#include <dsound.h>
#include <wrl.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dsound.lib")

// 외부 라이브러리
#include "..\ExternalLibrary\TinyXML2\tinyxml2.h"
#include "..\ExternalLibrary\Vorbis\include\vorbisfile.h"

auto _fprintf = fprintf;
auto _sprintf = sprintf;
#pragma comment(lib, "Vorbis/lib/ogg_static.lib")
#pragma comment(lib, "Vorbis/lib/vorbis_static.lib")
#pragma comment(lib, "Vorbis/lib/vorbisfile_static.lib")

#pragma region MACRO

#define SR_DELETE(p)		\
{							\
	if ((p))				\
	{						\
		delete (p);			\
		(p) = nullptr;		\
	}						\
}
#define SR_DELETE_ARR(p)	\
{							\
	if ((p))				\
	{						\
		delete[] (p);		\
		(p) = nullptr;		\
	}						\
}
#define SR_RELEASE(p)		\
{							\
	if ((p))				\
	{						\
		(p)->Release();		\
		(p) = nullptr;		\
	}						\
}
#define SR_RF_BOOL(b)		\
{							\
	if (!(b))				\
	{						\
		return false;		\
	}						\
}
#define SR_RF_HR(hr)		\
{							\
	if (FAILED((hr)))		\
	{						\
		return false;		\
	}						\
}

#pragma endregion