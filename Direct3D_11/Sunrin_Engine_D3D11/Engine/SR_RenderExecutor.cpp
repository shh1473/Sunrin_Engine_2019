#include "SR_PCH.h"

#include "SR_RenderExecutor.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_RenderExecutor::SR_RenderExecutor() noexcept :
		m_nowRendererAddIndex	{ 0 },
		m_UIRenderers			{},
		m_currentCamera			{ nullptr },
		m_currentUICamera		{ nullptr },
		m_forwardCameras		{},
		m_deferredCameras		{},
		m_packingCameras		{},
		m_UICameras				{},
		m_commandLists			{ nullptr, nullptr, nullptr, nullptr },
		m_renderTasks			{}
	{
		m_renderTasks[0].SetThreadID(0);
		m_renderTasks[1].SetThreadID(1);
		m_renderTasks[2].SetThreadID(2);
		m_renderTasks[3].SetThreadID(3);
	}

	bool SR_RenderExecutor::Render()
	{
		for (auto forwardCameraIter : m_forwardCameras)
		{
			m_currentCamera = forwardCameraIter;
			m_currentCamera->Ready();

			m_renderFutures[0] = std::async([&]() { return m_renderTasks[0].RenderForward(); });
			m_renderFutures[1] = std::async([&]() { return m_renderTasks[1].RenderForward(); });
			m_renderFutures[2] = std::async([&]() { return m_renderTasks[2].RenderForward(); });
			m_renderFutures[3] = std::async([&]() { return m_renderTasks[3].RenderForward(); });

			SR_RF_BOOL(m_renderFutures[0].get());
			SR_RF_BOOL(m_renderFutures[1].get());
			SR_RF_BOOL(m_renderFutures[2].get());
			SR_RF_BOOL(m_renderFutures[3].get());
		}

		for (auto packingCameraIter : m_packingCameras)
		{
			m_currentCamera = packingCameraIter;
			m_currentCamera->Ready();

			m_renderFutures[0] = std::async([&]() { return m_renderTasks[0].RenderPacking(); });
			m_renderFutures[1] = std::async([&]() { return m_renderTasks[1].RenderPacking(); });
			m_renderFutures[2] = std::async([&]() { return m_renderTasks[2].RenderPacking(); });
			m_renderFutures[3] = std::async([&]() { return m_renderTasks[3].RenderPacking(); });

			SR_RF_BOOL(m_renderFutures[0].get());
			SR_RF_BOOL(m_renderFutures[1].get());
			SR_RF_BOOL(m_renderFutures[2].get());
			SR_RF_BOOL(m_renderFutures[3].get());
		}

		for (auto deferredCameraIter : m_deferredCameras)
		{
			m_currentCamera = deferredCameraIter;
			m_currentCamera->Ready();

			m_renderFutures[0] = std::async([&]() { return m_renderTasks[0].RenderDeferred(); });
			m_renderFutures[1] = std::async([&]() { return m_renderTasks[1].RenderDeferred(); });
			m_renderFutures[2] = std::async([&]() { return m_renderTasks[2].RenderDeferred(); });
			m_renderFutures[3] = std::async([&]() { return m_renderTasks[3].RenderDeferred(); });

			SR_RF_BOOL(m_renderFutures[0].get());
			SR_RF_BOOL(m_renderFutures[1].get());
			SR_RF_BOOL(m_renderFutures[2].get());
			SR_RF_BOOL(m_renderFutures[3].get());
		}

		m_renderFutures[0] = std::async([&]() { return m_renderTasks[0].RenderCompute(); });
		m_renderFutures[1] = std::async([&]() { return m_renderTasks[1].RenderCompute(); });
		m_renderFutures[2] = std::async([&]() { return m_renderTasks[2].RenderCompute(); });
		m_renderFutures[3] = std::async([&]() { return m_renderTasks[3].RenderCompute(); });

		SR_RF_BOOL(m_renderFutures[0].get());
		SR_RF_BOOL(m_renderFutures[1].get());
		SR_RF_BOOL(m_renderFutures[2].get());
		SR_RF_BOOL(m_renderFutures[3].get());

		for (unsigned i{ 0 }; i < SR_MAX_THREAD_COUNT; ++i)
		{
			SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DDeferredContext(i)->FinishCommandList(FALSE, m_commandLists[i].ReleaseAndGetAddressOf()));

			SR_App::GetInstance()->GetGraphic().GetD3DImmediateContext()->ExecuteCommandList(m_commandLists[i].Get(), FALSE);
		}

		SR_App::GetInstance()->GetGraphic().GetD2DDeviceContext()->BeginDraw();

		for (auto UICameraIter : m_UICameras)
		{
			m_currentUICamera = UICameraIter;
			m_currentUICamera->Ready();

			for (auto iter : m_UIRenderers)
			{
				SR_RF_BOOL(iter->Render());
			}
		}

		SR_App::GetInstance()->GetGraphic().GetD2DDeviceContext()->EndDraw();

		return true;
	}

	unsigned SR_RenderExecutor::AddForwardRenderer(SR_ForwardRenderer * forwardRenderer)
	{
		std::lock_guard<std::mutex> lockGuard(m_addForwardRendererMutex);

		unsigned contextIndex{ NextRendererAddIndex() };

		m_renderTasks[contextIndex].AddForwardRenderer(forwardRenderer);

		return contextIndex;
	}

	unsigned SR_RenderExecutor::AddDeferredRenderer(SR_DeferredRenderer * deferredRenderer)
	{
		std::lock_guard<std::mutex> lockGuard(m_addDeferredRendererMutex);

		unsigned contextIndex{ NextRendererAddIndex() };

		m_renderTasks[contextIndex].AddDeferredRenderer(deferredRenderer);

		return contextIndex;
	}

	unsigned SR_RenderExecutor::AddPackingRenderer(SR_PackingRenderer * packingRenderer)
	{
		std::lock_guard<std::mutex> lockGuard(m_addPackingRendererMutex);

		unsigned contextIndex{ NextRendererAddIndex() };

		m_renderTasks[contextIndex].AddPackingRenderer(packingRenderer);

		return contextIndex;
	}

	unsigned SR_RenderExecutor::AddComputeRenderer(SR_ComputeRenderer * computeRenderer)
	{
		std::lock_guard<std::mutex> lockGuard(m_addComputeRendererMutex);

		unsigned contextIndex{ NextRendererAddIndex() };

		m_renderTasks[contextIndex].AddComputeRenderer(computeRenderer);

		return contextIndex;
	}

	void SR_RenderExecutor::AddUIRenderer(SR_UIRenderer * UIRenderer)
	{
		std::lock_guard<std::mutex> lockGuard(m_addUIRendererMutex);

		m_UIRenderers.push_back(UIRenderer);
	}

	void SR_RenderExecutor::RemoveForwardRenderer(SR_ForwardRenderer * forwardRenderer, unsigned threadID)
	{
		m_renderTasks[threadID].RemoveForwardRenderer(forwardRenderer);
	}

	void SR_RenderExecutor::RemoveDeferredRenderer(SR_DeferredRenderer * deferredRenderer, unsigned threadID)
	{
		m_renderTasks[threadID].RemoveDeferredRenderer(deferredRenderer);
	}

	void SR_RenderExecutor::RemovePackingRenderer(SR_PackingRenderer * packingRenderer, unsigned threadID)
	{
		m_renderTasks[threadID].RemovePackingRenderer(packingRenderer);
	}

	void SR_RenderExecutor::RemoveComputeRenderer(SR_ComputeRenderer * computeRenderer, unsigned threadID)
	{
		m_renderTasks[threadID].RemoveComputeRenderer(computeRenderer);
	}

	void SR_RenderExecutor::RemoveUIRenderer(SR_UIRenderer * UIRenderer)
	{
		m_UIRenderers.erase(std::find(m_UIRenderers.begin(), m_UIRenderers.end(), UIRenderer));
	}

	void SR_RenderExecutor::AddForwardCamera(SR_ForwardCamera * forwardCamera)
	{
		std::lock_guard<std::mutex> lockGuard(m_addForwardCameraMutex);

		m_forwardCameras.push_back(forwardCamera);
	}

	void SR_RenderExecutor::AddDeferredCamera(SR_DeferredCamera * deferredCamera)
	{
		std::lock_guard<std::mutex> lockGuard(m_addDeferredCameraMutex);

		m_deferredCameras.push_back(deferredCamera);
	}

	void SR_RenderExecutor::AddPackingCamera(SR_PackingCamera * packingCamera)
	{
		std::lock_guard<std::mutex> lockGuard(m_addPackingCameraMutex);

		m_packingCameras.push_back(packingCamera);
	}

	void SR_RenderExecutor::AddUICamera(SR_UICamera * UICamera)
	{
		std::lock_guard<std::mutex> lockGuard(m_addUICameraMutex);

		m_UICameras.push_back(UICamera);
	}

	void SR_RenderExecutor::RemoveForwardCamera(SR_ForwardCamera * forwardCamera)
	{
		m_forwardCameras.erase(std::find(m_forwardCameras.begin(), m_forwardCameras.end(), forwardCamera));
	}

	void SR_RenderExecutor::RemoveDeferredCamera(SR_DeferredCamera * deferredCamera)
	{
		m_deferredCameras.erase(std::find(m_deferredCameras.begin(), m_deferredCameras.end(), deferredCamera));
	}

	void SR_RenderExecutor::RemovePackingCamera(SR_PackingCamera * packingCamera)
	{
		m_packingCameras.erase(std::find(m_packingCameras.begin(), m_packingCameras.end(), packingCamera));
	}

	void SR_RenderExecutor::RemoveUICamera(SR_UICamera * UICamera)
	{
		m_UICameras.erase(std::find(m_UICameras.begin(), m_UICameras.end(), UICamera));
	}

	unsigned SR_RenderExecutor::NextRendererAddIndex()
	{
		m_nowRendererAddIndex %= SR_MAX_THREAD_COUNT;

		return m_nowRendererAddIndex++;
	}

}