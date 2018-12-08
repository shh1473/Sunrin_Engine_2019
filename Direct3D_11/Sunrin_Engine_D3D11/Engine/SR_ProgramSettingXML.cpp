#include "SR_PCH.h"
#include "SR_ProgramSettingXML.h"

namespace SunrinEngine
{

	SR_ProgramSettingXML::SR_ProgramSettingXML() noexcept :
		m_isWindowed			{},
		m_windowPositionX		{},
		m_windowPositionY		{},
		m_windowWidth			{},
		m_windowHeight			{},
		m_windowTitle			{},
		m_isEnableVSync			{},
		m_VSyncLevel			{},
		m_adapterIndex			{},
		m_window				{ nullptr, "Window" },
		m_VSync					{ nullptr, "VSync" },
		m_adapter				{ nullptr, "Adapter" }
	{

	}

	void SR_ProgramSettingXML::Initialize()
	{
		Open("program_setting");

		PushElement(&m_window);
		PushElement(&m_VSync);
		PushElement(&m_adapter);

		Load();

		m_isWindowed = m_window.first->BoolAttribute("windowed");
		m_windowPositionX = m_window.first->UnsignedAttribute("x");
		m_windowPositionY = m_window.first->UnsignedAttribute("y");
		m_windowWidth = m_window.first->UnsignedAttribute("width");
		m_windowHeight = m_window.first->UnsignedAttribute("height");
		m_windowTitle = m_window.first->Attribute("title");

		m_isEnableVSync = m_VSync.first->BoolAttribute("enable");
		m_VSyncLevel = m_VSync.first->UnsignedAttribute("level");

		m_adapterIndex = m_adapter.first->UnsignedAttribute("index");
	}

	void SR_ProgramSettingXML::Save()
	{
		m_window.first->SetAttribute("windowed", m_isWindowed);
		m_window.first->SetAttribute("x", m_windowPositionX);
		m_window.first->SetAttribute("y", m_windowPositionY);
		m_window.first->SetAttribute("width", m_windowWidth);
		m_window.first->SetAttribute("height", m_windowHeight);

		m_VSync.first->SetAttribute("enable", m_isEnableVSync);
		m_VSync.first->SetAttribute("level", m_VSyncLevel);

		m_adapter.first->SetAttribute("index", m_adapterIndex);

		Apply();
	}

}