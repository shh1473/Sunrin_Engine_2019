#include "SR_PCH.h"

#include "SR_RenderTask.h"

namespace SunrinEngine
{

	SR_RenderTask::SR_RenderTask() noexcept :
		m_inputAssemblerStage	{},
		m_streamOutputStage		{},
		m_vertexShaderStage		{},
		m_hullShaderStage		{},
		m_domainShaderStage		{},
		m_geometryShaderStage	{},
		m_pixelShaderStage		{},
		m_computeShaderStage	{},
		m_forwardRenderers		{},
		m_deferredRenderers		{},
		m_packingRenderers		{},
		m_computeRenderers		{}
	{

	}

	bool SR_RenderTask::RenderForward()
	{
		for (auto forwardRendererIter : m_forwardRenderers)
		{
			if (forwardRendererIter->GetIsActivate())
			{
				SR_RF_BOOL(forwardRendererIter->Render());
			}
		}

		return true;
	}

	bool SR_RenderTask::RenderDeferred()
	{
		for (auto packingRendererIter : m_packingRenderers)
		{
			if (packingRendererIter->GetIsActivate())
			{
				SR_RF_BOOL(packingRendererIter->Render());
			}
		}

		return true;
	}

	bool SR_RenderTask::RenderPacking()
	{
		for (auto deferredRendererIter : m_deferredRenderers)
		{
			if (deferredRendererIter->GetIsActivate())
			{
				SR_RF_BOOL(deferredRendererIter->Render());
			}
		}

		return true;
	}

	bool SR_RenderTask::RenderCompute()
	{
		for (auto computeRendererIter : m_computeRenderers)
		{
			if (computeRendererIter->GetIsActivate())
			{
				SR_RF_BOOL(computeRendererIter->Render());
			}
		}

		return true;
	}

	void SR_RenderTask::AddForwardRenderer(SR_ForwardRenderer * forwardRenderer)
	{
		m_forwardRenderers.push_back(forwardRenderer);
	}

	void SR_RenderTask::AddDeferredRenderer(SR_DeferredRenderer * deferredRenderer)
	{
		m_deferredRenderers.push_back(deferredRenderer);
	}

	void SR_RenderTask::AddPackingRenderer(SR_PackingRenderer * packingRenderer)
	{
		m_packingRenderers.push_back(packingRenderer);
	}

	void SR_RenderTask::AddComputeRenderer(SR_ComputeRenderer * computeRenderer)
	{
		m_computeRenderers.push_back(computeRenderer);
	}

	void SR_RenderTask::RemoveForwardRenderer(SR_ForwardRenderer * forwardRenderer)
	{
		m_forwardRenderers.erase(std::find(m_forwardRenderers.begin(), m_forwardRenderers.end(), forwardRenderer));
	}

	void SR_RenderTask::RemoveDeferredRenderer(SR_DeferredRenderer * deferredRenderer)
	{
		m_deferredRenderers.erase(std::find(m_deferredRenderers.begin(), m_deferredRenderers.end(), deferredRenderer));
	}

	void SR_RenderTask::RemovePackingRenderer(SR_PackingRenderer * packingRenderer)
	{
		m_packingRenderers.erase(std::find(m_packingRenderers.begin(), m_packingRenderers.end(), packingRenderer));
	}

	void SR_RenderTask::RemoveComputeRenderer(SR_ComputeRenderer * computeRenderer)
	{
		m_computeRenderers.erase(std::find(m_computeRenderers.begin(), m_computeRenderers.end(), computeRenderer));
	}

	void SR_RenderTask::SetThreadID(unsigned threadID) noexcept
	{
		SR_Task::SetThreadID(threadID);

		m_inputAssemblerStage.SetThreadID(threadID);
		m_outputMergerStage.SetThreadID(threadID);
		m_rasterizerStage.SetThreadID(threadID);
		m_streamOutputStage.SetThreadID(threadID);
		m_vertexShaderStage.SetThreadID(threadID);
		m_hullShaderStage.SetThreadID(threadID);
		m_domainShaderStage.SetThreadID(threadID);
		m_geometryShaderStage.SetThreadID(threadID);
		m_pixelShaderStage.SetThreadID(threadID);
		m_computeShaderStage.SetThreadID(threadID);
	}

}