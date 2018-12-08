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
		void SetWindowWidth(unsigned windowWidth) noexcept { m_windowWidth = windowWidth; }
		void SetWindowHeight(unsigned windowHeight) noexcept { m_windowHeight = windowHeight; }
		void SetIsEnableVSync(bool isEnableVSync) noexcept { m_isEnableVSync = isEnableVSync; }
		void SetVSyncLevel(unsigned VSyncLevel) noexcept { m_VSyncLevel = VSyncLevel; }
		void SetAdapterIndex(unsigned adapterIndex) noexcept { m_adapterIndex = adapterIndex; }

		bool GetIsWindowed() const noexcept { return m_isWindowed; }
		unsigned GetWindowPositionX() const noexcept { return m_windowPositionX; }
		unsigned GetWindowPositionY() const noexcept { return m_windowPositionY; }
		unsigned GetWindowWidth() const noexcept { return m_windowWidth; }
		unsigned GetWindowHeight() const noexcept { return m_windowHeight; }
		const std::string & GetWindowTitle() const noexcept { return m_windowTitle; }
		bool GetIsEnableVSync() const noexcept { return m_isEnableVSync; }
		unsigned GetVSyncLevel() const noexcept { return m_VSyncLevel; }
		unsigned GetAdapterIndex() const noexcept { return m_adapterIndex; }

	private:
		// Window
		bool m_isWindowed;
		unsigned m_windowPositionX;
		unsigned m_windowPositionY;
		unsigned m_windowWidth;
		unsigned m_windowHeight;
		std::string m_windowTitle;

		// VSync
		bool m_isEnableVSync;
		unsigned m_VSyncLevel;

		// Adapter
		unsigned m_adapterIndex;

		// Elements
		SR_XML_ElementPair m_window;
		SR_XML_ElementPair m_VSync;
		SR_XML_ElementPair m_adapter;

	};

}