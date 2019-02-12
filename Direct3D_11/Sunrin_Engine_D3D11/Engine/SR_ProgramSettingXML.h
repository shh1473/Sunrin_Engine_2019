#pragma once

#include "SR_XML.h"

namespace SunrinEngine
{

	class SR_ProgramSettingXML : public SR_XML
	{
	public:
		explicit SR_ProgramSettingXML() noexcept;

		void Initialize();

		void Save();

		void SetIsWindowed(bool isWindowed) noexcept { m_isWindowed = isWindowed; }
		void SetWindowPositionX(unsigned windowPositionX) noexcept { m_windowPositionX = windowPositionX; }
		void SetWindowPositionY(unsigned windowPositionY) noexcept { m_windowPositionY = windowPositionY; }
		void SetClientWidth(unsigned clientWidth) noexcept { m_clientWidth = clientWidth; }
		void SetClientHeight(unsigned clientHeight) noexcept { m_clientHeight = clientHeight; }
		void SetIsEnableVSync(bool isEnableVSync) noexcept { m_isEnableVSync = isEnableVSync; }
		void SetVSyncLevel(unsigned VSyncLevel) noexcept { m_VSyncLevel = VSyncLevel; }

		bool GetIsWindowed() const noexcept { return m_isWindowed; }
		unsigned GetWindowPositionX() const noexcept { return m_windowPositionX; }
		unsigned GetWindowPositionY() const noexcept { return m_windowPositionY; }
		unsigned GetClientWidth() const noexcept { return m_clientWidth; }
		unsigned GetClientHeight() const noexcept { return m_clientHeight; }
		const std::wstring & GetWindowTitle() const noexcept { return m_windowTitle; }
		bool GetIsEnableVSync() const noexcept { return m_isEnableVSync; }
		unsigned GetVSyncLevel() const noexcept { return m_VSyncLevel; }

	private:
		// Window
		bool m_isWindowed;
		unsigned m_windowPositionX;
		unsigned m_windowPositionY;
		unsigned m_clientWidth;
		unsigned m_clientHeight;
		std::wstring m_windowTitle;

		// VSync
		bool m_isEnableVSync;
		unsigned m_VSyncLevel;

		// Elements
		SR_XML_ElementPair m_window;
		SR_XML_ElementPair m_VSync;

	};

}