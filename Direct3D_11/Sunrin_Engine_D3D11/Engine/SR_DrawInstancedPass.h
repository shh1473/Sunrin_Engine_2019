#pragma once

#include "SR_CommonPass.h"

namespace SunrinEngine
{

	class SR_DrawInstancedPass : public SR_CommonPass
	{
	public:
		explicit SR_DrawInstancedPass(SR_Component * owner) noexcept;

		virtual bool Render(unsigned threadID) override;

		void SetVertexCountPerInstance(unsigned count) noexcept { m_vertexCountPerInstance = count; }
		void SetInstanceCount(unsigned count) noexcept { m_instanceCount = count; }
		void SetStartVertexLocation(unsigned location) noexcept { m_startVertexLocation = location; }
		void SetStartInstanceLocation(unsigned location) noexcept { m_startInstanceLocation = location; }

	private:
		unsigned m_vertexCountPerInstance;
		unsigned m_instanceCount;
		unsigned m_startVertexLocation;
		unsigned m_startInstanceLocation;

	};

}