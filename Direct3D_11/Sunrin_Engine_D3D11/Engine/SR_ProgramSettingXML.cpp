#include "SR_PCH.h"

#include "SR_ProgramSettingXML.h"
#include "SR_Converter.h"

namespace SunrinEngine
{

	SR_ProgramSettingXML::SR_ProgramSettingXML() noexcept :
		m_isWindowed			{ true },
		m_windowPositionX		{ 0 },
		m_windowPositionY		{ 0 },
		m_clientWidth			{ 0 },
		m_clientHeight			{ 0 },
		m_windowTitle			{ L"Unknown" },
		m_isEnableVSync			{ false },
		m_VSyncLevel			{ 0 },
		m_window				{ nullptr, "Window" },
		m_VSync					{ nullptr, "VSync" }
	{

	}

	void SR_ProgramSettingXML::Initialize()
	{
		Open(L"program_setting.xml");

		PushElement(&m_window);
		PushElement(&m_VSync);

		Load();

		m_isWindowed = m_window.first->BoolAttribute("windowed");
		m_windowPositionX = m_window.first->UnsignedAttribute("x");
		m_windowPositionY = m_window.first->UnsignedAttribute("y");
		m_clientWidth = m_window.first->UnsignedAttribute("width");
		m_clientHeight = m_window.first->UnsignedAttribute("height");
		m_windowTitle = SR_Converter::ToUnicode(m_window.first->Attribute("title"));

		m_isEnableVSync = m_VSync.first->BoolAttribute("enable");
		m_VSyncLevel = m_VSync.first->UnsignedAttribute("level");
	}

	void SR_ProgramSettingXML::Save()
	{
		m_window.first->SetAttribute("windowed", m_isWindowed);
		m_window.first->SetAttribute("x", m_windowPositionX);
		m_window.first->SetAttribute("y", m_windowPositionY);
		m_window.first->SetAttribute("width", m_clientWidth);
		m_window.first->SetAttribute("height", m_clientHeight);

		m_VSync.first->SetAttribute("enable", m_isEnableVSync);
		m_VSync.first->SetAttribute("level", m_VSyncLevel);

		Apply();
	}

}