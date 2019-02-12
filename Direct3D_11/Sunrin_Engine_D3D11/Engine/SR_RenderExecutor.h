#pragma once

#include "SR_Executor.h"
#include "SR_RenderTask.h"
#include "SR_TargetStage.h"
#include "SR_Camera.h"
#include "SR_UICamera.h"

namespace SunrinEngine
{

	class SR_RenderExecutor : public SR_Executor
	{
	public:
		explicit SR_RenderExecutor() noexcept;

		bool Render();

		unsigned AddForwardRenderer(SR_ForwardRenderer * forwardRenderer);
		unsigned AddDeferredRenderer(SR_DeferredRenderer * deferredRenderer);
		unsigned AddPackingRenderer(SR_PackingRenderer * packingRenderer);
		unsigned AddComputeRenderer(SR_ComputeRenderer * computeRenderer);
		void RemoveForwardRenderer(SR_ForwardRenderer * forwardRenderer, unsigned threadID);
		void RemoveDeferredRenderer(SR_DeferredRenderer * deferredRenderer, unsigned threadID);
		void RemovePackingRenderer(SR_PackingRenderer * packingRenderer, unsigned threadID);
		void RemoveComputeRenderer(SR_ComputeRenderer * computeRenderer, unsigned threadID);

		void AddUIRenderer(SR_UIRenderer * UIRenderer);
		void RemoveUIRenderer(SR_UIRenderer * UIRenderer);

		void AddForwardCamera(SR_ForwardCamera * forwardCamera);
		void AddDeferredCamera(SR_DeferredCamera * deferredCamera);
		void AddPackingCamera(SR_PackingCamera * packingCamera);
		void AddUICamera(SR_UICamera * UICamera);
		void RemoveForwardCamera(SR_ForwardCamera * forwardCamera);
		void RemoveDeferredCamera(SR_DeferredCamera * deferredCamera);
		void RemovePackingCamera(SR_PackingCamera * packingCamera);
		void RemoveUICamera(SR_UICamera * UICamera);

		SR_TargetStage & GetTargetStage() noexcept { return m_targetStage; }
		SR_CommonCamera * GetCurrentCamera() const noexcept { return m_currentCamera; }
		SR_UICamera * GetCurrentUICamera() const noexcept { return m_currentUICamera; }
		SR_RenderTask & GetRenderTask(unsigned index) noexcept { return m_renderTasks[index]; }

	private:
		unsigned NextRendererAddIndex();

	private:
		unsigned m_nowRendererAddIndex;
		std::mutex m_addForwardRendererMutex;
		std::mutex m_addPackingRendererMutex;
		std::mutex m_addDeferredRendererMutex;
		std::mutex m_addComputeRendererMutex;
		std::mutex m_addUIRendererMutex;
		std::mutex m_addForwardCameraMutex;
		std::mutex m_addDeferredCameraMutex;
		std::mutex m_addPackingCameraMutex;
		std::mutex m_addUICameraMutex;

	private:
		SR_TargetStage m_targetStage;

		std::vector<SR_UIRenderer*> m_UIRenderers;
		SR_CommonCamera * m_currentCamera;
		SR_UICamera * m_currentUICamera;
		std::vector<SR_ForwardCamera*> m_forwardCameras;
		std::vector<SR_DeferredCamera*> m_deferredCameras;
		std::vector<SR_PackingCamera*> m_packingCameras;
		std::vector<SR_UICamera*> m_UICameras;

		std::array<Microsoft::WRL::ComPtr<ID3D11CommandList>, SR_MAX_THREAD_COUNT> m_commandLists;

		std::array<SR_RenderTask, SR_MAX_THREAD_COUNT> m_renderTasks;
		std::future<bool> m_renderFutures[SR_MAX_THREAD_COUNT];

	};

}