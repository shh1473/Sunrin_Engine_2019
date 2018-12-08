#include "SR_PCH.h"
#include "Engine\SR_App.h"

#if defined(DEBUG) || defined(_DEBUG)
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#endif

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR cmdParam, int cmdShow)
{
#if defined(DEBUG) || defined(_DEBUG)
	//_CrtSetBreakAlloc(1541);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(cmdParam);
	UNREFERENCED_PARAMETER(cmdShow);

	std::locale::global(std::locale("korean"));

	SunrinEngine::SR_App::CreateInstance();

	if (SunrinEngine::SR_App::GetInstance()->Initialize())
	{
		SunrinEngine::SR_App::GetInstance()->GetLog().LineOpen();
		SunrinEngine::SR_App::GetInstance()->GetLog().WriteLine(L"프로그램 초기화에 성공했습니다.");
		SunrinEngine::SR_App::GetInstance()->GetLog().LineClose();

		SunrinEngine::SR_App::GetInstance()->Run();
	}

	SunrinEngine::SR_App::GetInstance()->GetLog().LineOpen();
	SunrinEngine::SR_App::GetInstance()->GetLog().WriteLine(L"프로그램을 종료합니다.");
	SunrinEngine::SR_App::GetInstance()->GetLog().LineClose();

	return 0;
}