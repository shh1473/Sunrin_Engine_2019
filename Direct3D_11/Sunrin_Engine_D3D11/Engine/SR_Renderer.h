#pragma once

#include "SR_Component.h"
#include "SR_RenderTechnique.h"

namespace SunrinEngine
{

	class SR_CommonRenderer : public SR_Component
	{
	public:
		explicit SR_CommonRenderer(SR_Entity * owner, unsigned threadID);

		bool Render();

		void SetTechnique(SR_RenderTechnique * technique) { m_technique = technique; }

	protected:
		unsigned GetThreadID() const noexcept { return m_threadID; }

	private:
		unsigned m_threadID;
		SR_RenderTechnique * m_technique;

	};

	class SR_ForwardRenderer : public SR_CommonRenderer
	{
	public:
		explicit SR_ForwardRenderer(SR_Entity * owner);
		virtual ~SR_ForwardRenderer();

	};

	class SR_DeferredRenderer : public SR_CommonRenderer
	{
	public:
		explicit SR_DeferredRenderer(SR_Entity * owner);
		virtual ~SR_DeferredRenderer();

	};

	class SR_PackingRenderer : public SR_CommonRenderer
	{
	public:
		explicit SR_PackingRenderer(SR_Entity * owner);
		virtual ~SR_PackingRenderer();

	};

	class SR_ComputeRenderer : public SR_CommonRenderer
	{
	public:
		explicit SR_ComputeRenderer(SR_Entity * owner);
		virtual ~SR_ComputeRenderer();

	};

}