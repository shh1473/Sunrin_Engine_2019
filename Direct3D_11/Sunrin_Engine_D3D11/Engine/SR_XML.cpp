#include "SR_PCH.h"
#include "SR_XML.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_XML::SR_XML() noexcept :
		m_path		{},
		m_document	{},
		m_root		{ nullptr },
		m_elements	{}
	{

	}

	void SR_XML::Open(std::string && fileName)
	{
		m_path = "Resources\\Game\\XML\\" + fileName + ".xml";
		m_root = m_document.NewElement("SunrinEngine_XML_Root");

		m_document.LinkEndChild(m_root);
	}

	void SR_XML::Load()
	{
		tinyxml2::XMLError error{ m_document.LoadFile(m_path.c_str()) };

		if (error != tinyxml2::XML_SUCCESS)
		{
			SR_App::GetInstance()->GetLog().WriteLine(L"XML Error: " + GetErrorString(error));
		}
		else
		{
			m_root = m_document.FirstChildElement();

			for (auto iter : m_elements)
			{
				iter->first = m_root->FirstChildElement(iter->second.c_str());
			}
		}
	}

	void SR_XML::Apply()
	{
		tinyxml2::XMLError error{ m_document.SaveFile(m_path.c_str()) };

		if (error != tinyxml2::XML_SUCCESS)
		{
			SR_App::GetInstance()->GetLog().WriteLine(L"XML Error: " + GetErrorString(error));
		}
	}

	void SR_XML::PushElement(SR_XML_ElementPair * elementPair)
	{
		elementPair->first = m_document.NewElement(elementPair->second.c_str());

		m_root->LinkEndChild(elementPair->first);

		m_elements.push_back(elementPair);
	}


	std::wstring SR_XML::GetErrorString(tinyxml2::XMLError error) noexcept
	{
		switch (error)
		{
			case tinyxml2::XML_NO_ATTRIBUTE:					return L"XML_NO_ATTRIBUTE";
			case tinyxml2::XML_WRONG_ATTRIBUTE_TYPE:			return L"XML_WRONG_ATTRIBUTE_TYPE";
			case tinyxml2::XML_ERROR_FILE_NOT_FOUND:			return L"XML_ERROR_FILE_NOT_FOUND";
			case tinyxml2::XML_ERROR_FILE_COULD_NOT_BE_OPENED:	return L"XML_ERROR_FILE_COULD_NOT_BE_OPENED";
			case tinyxml2::XML_ERROR_FILE_READ_ERROR:			return L"XML_ERROR_FILE_READ_ERROR";
			case tinyxml2::XML_ERROR_PARSING_ELEMENT:			return L"XML_ERROR_PARSING_ELEMENT";
			case tinyxml2::XML_ERROR_PARSING_ATTRIBUTE:			return L"XML_ERROR_PARSING_ATTRIBUTE";
			case tinyxml2::XML_ERROR_PARSING_TEXT:				return L"XML_ERROR_PARSING_TEXT";
			case tinyxml2::XML_ERROR_PARSING_CDATA:				return L"XML_ERROR_PARSING_CDATA";
			case tinyxml2::XML_ERROR_PARSING_COMMENT:			return L"XML_ERROR_PARSING_COMMENT";
			case tinyxml2::XML_ERROR_PARSING_DECLARATION:		return L"XML_ERROR_PARSING_DECLARATION";
			case tinyxml2::XML_ERROR_PARSING_UNKNOWN:			return L"XML_ERROR_PARSING_UNKNOWN";
			case tinyxml2::XML_ERROR_EMPTY_DOCUMENT:			return L"XML_ERROR_EMPTY_DOCUMENT";
			case tinyxml2::XML_ERROR_MISMATCHED_ELEMENT:		return L"XML_ERROR_MISMATCHED_ELEMENT";
			case tinyxml2::XML_ERROR_PARSING:					return L"XML_ERROR_PARSING";
			case tinyxml2::XML_CAN_NOT_CONVERT_TEXT:			return L"XML_CAN_NOT_CONVERT_TEXT";
			case tinyxml2::XML_NO_TEXT_NODE:					return L"XML_NO_TEXT_NODE";
			case tinyxml2::XML_ELEMENT_DEPTH_EXCEEDED:			return L"XML_ELEMENT_DEPTH_EXCEEDED";
			default: return L"Unknown";
		}
	}

}