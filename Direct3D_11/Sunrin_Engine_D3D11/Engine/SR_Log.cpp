#include "SR_PCH.h"
#include "SR_Log.h"

namespace SunrinEngine
{

	SR_Log::SR_Log() noexcept :
		m_isGood	{ false },
		m_fileName	{},
		m_file		{}
	{

	}

	SR_Log::~SR_Log() noexcept
	{
		if (m_isGood)
		{
			m_file.close();
		}
	}

	bool SR_Log::Initialize()
	{
		m_file.open(L"Log\\SunrinEngine_Log.txt");
		m_isGood = m_file.good();

		return m_isGood;
	}

	void SR_Log::WriteSpace(const std::wstring & str) noexcept
	{
		m_file << str << L" ";
		m_file.flush();

#if defined(DEBUG) || defined(_DEBUG)
		OutputDebugStringW(str.c_str());
		OutputDebugStringW(L" ");
#endif
	}

	void SR_Log::WriteSpace(std::wstring && str) noexcept
	{
		m_file << str << L" ";
		m_file.flush();

#if defined(DEBUG) || defined(_DEBUG)
		OutputDebugStringW(str.c_str());
		OutputDebugStringW(L" ");
#endif
	}

	void SR_Log::WriteLine(const std::wstring & str) noexcept
	{
		m_file << str << L"\n";
		m_file.flush();

#if defined(DEBUG) || defined(_DEBUG)
		OutputDebugStringW(str.c_str());
		OutputDebugStringW(L"\n");
#endif
	}

	void SR_Log::WriteLine(std::wstring && str) noexcept
	{
		m_file << str << L"\n";
		m_file.flush();

#if defined(DEBUG) || defined(_DEBUG)
		OutputDebugStringW(str.c_str());
		OutputDebugStringW(L"\n");
#endif
	}

	void SR_Log::NextLine() noexcept
	{
		m_file << L"\n";
		m_file.flush();

#if defined(DEBUG) || defined(_DEBUG)
		OutputDebugStringW(L"\n");
#endif
	}

	void SR_Log::LineOpen() noexcept
	{
		WriteLine(L"-----------------------------------------------------------------\n");
	}

	void SR_Log::LineClose() noexcept
	{
		WriteLine(L"\n-----------------------------------------------------------------");
	}

}