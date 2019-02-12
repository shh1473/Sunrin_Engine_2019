#pragma once

#include "SR_CommonPass.h"

namespace SunrinEngine
{

	class SR_DrawPass : public SR_CommonPass
	{
	public:
		explicit SR_DrawPass(SR_Component * owner) noexcept;

		virtual bool Render(unsigned threadID) override;

		void SetVertexCount(unsigned vertexCount) noexcept { m_vertexCount = vertexCount; }
		void SetStartVertexLocation(unsigned startVertexLocation) noexcept { m_startVertexLocation = startVertexLocation; }

	private:
		unsigned m_vertexCount;
		unsigned m_startVertexLocation;

	};

}