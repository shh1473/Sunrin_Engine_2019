#pragma once

#include "SR_PCH.h"
#include "SR_NonCopyable.h"

namespace SunrinEngine
{
	
	class SR_Log : public SR_NonCopyable
	{
	public:
		explicit SR_Log() noexcept;
		~SR_Log() noexcept;

		bool Initialize();

		void WriteSpace(const std::wstring & str) noexcept;
		void WriteSpace(std::wstring && str) noexcept;

		void WriteLine(const std::wstring & str) noexcept;
		void WriteLine(std::wstring && str) noexcept;

		void NextLine() noexcept;

		void LineOpen() noexcept;
		void LineClose() noexcept;

	private:
		bool m_isGood;
		std::wstring m_fileName;
		std::wofstream m_file;

	};

}