#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

namespace SunrinEngine
{

	class SR_InputElement : public SR_NonCopyable
	{
	public:
		explicit SR_InputElement() noexcept;

		void AddElement(const D3D11_INPUT_ELEMENT_DESC & inputElementDesc);
		void AddElement(
			const char * semanticName,
			unsigned semanticIndex,
			DXGI_FORMAT format,
			unsigned inputSlot,
			unsigned alignedByOffset,
			D3D11_INPUT_CLASSIFICATION inputSlotClass,
			unsigned instanceDataStepRate);
		
	public:
		std::vector<D3D11_INPUT_ELEMENT_DESC> m_descs;

	};

}