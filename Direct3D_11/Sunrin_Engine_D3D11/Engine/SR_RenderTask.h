#pragma once

#include "SR_Task.h"
#include "SR_Renderer.h"
#include "SR_UIRenderer.h"
#include "SR_InputAssemblerStage.h"
#include "SR_OutputMergerStage.h"
#include "SR_RasterizerStage.h"
#include "SR_StreamOutputStage.h"
#include "SR_VertexShaderStage.h"
#include "SR_HullShaderStage.h"
#include "SR_DomainShaderStage.h"
#include "SR_GeometryShaderStage.h"
#include "SR_PixelShaderStage.h"
#include "SR_ComputeShaderStage.h"

namespace SunrinEngine
{

	class SR_RenderTask : public SR_Task
	{
	public:
		explicit SR_RenderTask() noexcept;

		bool RenderForward();
		bool RenderDeferred();
		bool RenderPacking();
		bool RenderCompute();

		void AddForwardRenderer(SR_ForwardRenderer * forwardRenderer);
		void AddDeferredRenderer(SR_DeferredRenderer * deferredRenderer);
		void AddPackingRenderer(SR_PackingRenderer * packingRenderer);
		void AddComputeRenderer(SR_ComputeRenderer * computeRenderer);
		void RemoveForwardRenderer(SR_ForwardRenderer * forwardRenderer);
		void RemoveDeferredRenderer(SR_DeferredRenderer * deferredRenderer);
		void RemovePackingRenderer(SR_PackingRenderer * packingRenderer);
		void RemoveComputeRenderer(SR_ComputeRenderer * computeRenderer);

		virtual void SetThreadID(unsigned threadID) noexcept override;

		SR_InputAssemblerStage & GetInputAssemblerStage() noexcept { return m_inputAssemblerStage; }
		SR_OutputMergerStage & GetOutputMergerStage() noexcept { return m_outputMergerStage; }
		SR_RasterizerStage & GetRasterizerStage() noexcept { return m_rasterizerStage; }
		SR_StreamOutputStage & GetStreamOutputStage() noexcept { return m_streamOutputStage; }
		SR_VertexShaderStage & GetVertexShaderStage() noexcept { return m_vertexShaderStage; }
		SR_HullShaderStage & GetHullShaderStage() noexcept { return m_hullShaderStage; }
		SR_DomainShaderStage & GetDomainShaderStage() noexcept { return m_domainShaderStage; }
		SR_GeometryShaderStage & GetGeometryShaderStage() noexcept { return m_geometryShaderStage; }
		SR_PixelShaderStage & GetPixelShaderStage() noexcept { return m_pixelShaderStage; }
		SR_ComputeShaderStage & GetComputeShaderStage() noexcept { return m_computeShaderStage; }

	private:
		SR_InputAssemblerStage m_inputAssemblerStage;
		SR_OutputMergerStage m_outputMergerStage;
		SR_RasterizerStage m_rasterizerStage;
		SR_StreamOutputStage m_streamOutputStage;
		SR_VertexShaderStage m_vertexShaderStage;
		SR_HullShaderStage m_hullShaderStage;
		SR_DomainShaderStage m_domainShaderStage;
		SR_GeometryShaderStage m_geometryShaderStage;
		SR_PixelShaderStage m_pixelShaderStage;
		SR_ComputeShaderStage m_computeShaderStage;

		std::vector<SR_ForwardRenderer*> m_forwardRenderers;
		std::vector<SR_DeferredRenderer*> m_deferredRenderers;
		std::vector<SR_PackingRenderer*> m_packingRenderers;
		std::vector<SR_ComputeRenderer*> m_computeRenderers;

	};

}