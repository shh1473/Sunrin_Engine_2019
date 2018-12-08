#pragma once

#include "SR_PCH.h"
#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	using SR_XML_ElementPair = std::pair<tinyxml2::XMLElement *, std::string>;

	class SR_XML : public SR_NonCopyable
	{
	public:
		explicit SR_XML() noexcept;

		void Open(std::string && fileName);
		void Load();
		void Apply();

	protected:
		void PushElement(SR_XML_ElementPair * elementPair);

	private:
		std::wstring GetErrorString(tinyxml2::XMLError error) noexcept;

	private:
		std::string	m_path;
		tinyxml2::XMLDocument m_document;
		tinyxml2::XMLElement * m_root;
		std::vector<SR_XML_ElementPair *> m_elements;

	};

}