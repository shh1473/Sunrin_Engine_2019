#include "SR_PCH.h"

#include "SR_InputElement.h"

namespace SunrinEngine
{

	SR_InputElement::SR_InputElement() noexcept :
		m_descs{}
	{

	}

	void SR_InputElement::AddElement(const D3D11_INPUT_ELEMENT_DESC & inputElementDesc)
	{
		m_descs.push_back(inputElementDesc);
	}

	void SR_InputElement::AddElement(
		const char * semanticName,
		unsigned semanticIndex,
		DXGI_FORMAT format,
		unsigned inputSlot,
		unsigned alignedByOffset,
		D3D11_INPUT_CLASSIFICATION inputSlotClass,
		unsigned instanceDataStepRate)
	{
		m_descs.push_back({ semanticName, semanticIndex, format, inputSlot, alignedByOffset, inputSlotClass, instanceDataStepRate });
	}

}