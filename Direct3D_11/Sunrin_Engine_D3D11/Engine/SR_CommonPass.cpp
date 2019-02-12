#include "SR_PCH.h"

#include "SR_CommonPass.h"
#include "SR_App.h"

namespace SunrinEngine
{

	SR_CommonPass::SR_CommonPass(SR_Component * owner) noexcept :
		m_owner							{ owner },
		m_inputParameterSet				{ nullptr },
		m_streamParameterSet			{ nullptr },
		m_vertexShaderParameterSet		{ nullptr },
		m_hullShaderParameterSet		{ nullptr },
		m_domainShaderParameterSet		{ nullptr },
		m_geometryShaderParameterSet	{ nullptr },
		m_pixelShaderParameterSet		{ nullptr },
		m_computeShaderParameterSet		{ nullptr }
	{

	}

	bool SR_CommonPass::Apply(unsigned threadID)
	{
		SR_RF_BOOL(MapBuffers());

		if (m_inputParameterSet)
		{
			m_inputParameterSet->Apply(threadID);
		}

		if (m_streamParameterSet)
		{
			m_streamParameterSet->Apply(threadID);

			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(threadID).GetStreamOutputStage().Apply(
				m_streamParameterSet->GetIsBindStreamBuffer());
		}

		if (m_vertexShaderParameterSet)
		{
			m_vertexShaderParameterSet->Apply(threadID);

			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(threadID).GetVertexShaderStage().Apply(
				m_vertexShaderParameterSet->GetIsBindShader(),
				m_vertexShaderParameterSet->GetIsBindConstantBuffer(),
				m_vertexShaderParameterSet->GetIsBindShaderResourceView(),
				m_vertexShaderParameterSet->GetIsBindSamplerState());
		}

		if (m_hullShaderParameterSet)
		{
			m_hullShaderParameterSet->Apply(threadID);

			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(threadID).GetHullShaderStage().Apply(
				m_hullShaderParameterSet->GetIsBindShader(),
				m_hullShaderParameterSet->GetIsBindConstantBuffer(),
				m_hullShaderParameterSet->GetIsBindShaderResourceView(),
				m_hullShaderParameterSet->GetIsBindSamplerState());
		}

		if (m_domainShaderParameterSet)
		{
			m_domainShaderParameterSet->Apply(threadID);

			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(threadID).GetDomainShaderStage().Apply(
				m_domainShaderParameterSet->GetIsBindShader(),
				m_domainShaderParameterSet->GetIsBindConstantBuffer(),
				m_domainShaderParameterSet->GetIsBindShaderResourceView(),
				m_domainShaderParameterSet->GetIsBindSamplerState());
		}

		if (m_geometryShaderParameterSet)
		{
			m_geometryShaderParameterSet->Apply(threadID);

			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(threadID).GetGeometryShaderStage().Apply(
				m_geometryShaderParameterSet->GetIsBindShader(),
				m_geometryShaderParameterSet->GetIsBindConstantBuffer(),
				m_geometryShaderParameterSet->GetIsBindShaderResourceView(),
				m_geometryShaderParameterSet->GetIsBindSamplerState());
		}

		if (m_pixelShaderParameterSet)
		{
			m_pixelShaderParameterSet->Apply(threadID);

			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(threadID).GetPixelShaderStage().Apply(
				m_pixelShaderParameterSet->GetIsBindShader(),
				m_pixelShaderParameterSet->GetIsBindConstantBuffer(),
				m_pixelShaderParameterSet->GetIsBindShaderResourceView(),
				m_pixelShaderParameterSet->GetIsBindSamplerState());
		}

		if (m_computeShaderParameterSet)
		{
			m_computeShaderParameterSet->Apply(threadID);

			m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(threadID).GetComputeShaderStage().Apply(
				m_computeShaderParameterSet->GetIsBindShader(),
				m_computeShaderParameterSet->GetIsBindConstantBuffer(),
				m_computeShaderParameterSet->GetIsBindShaderResourceView(),
				m_computeShaderParameterSet->GetIsBindUnorderedAccessView(),
				m_computeShaderParameterSet->GetIsBindSamplerState());
		}

		m_owner->GetOwner()->GetGameScene()->GetRenderExecutor().GetRenderTask(threadID).GetInputAssemblerStage().Apply(
			m_inputParameterSet->GetIsBindVertexBuffer(),
			m_vertexShaderParameterSet->GetIsBindInputLayout(),
			m_inputParameterSet->GetIsBindPrimitiveTopology());

		return true;
	}

	bool SR_CommonPass::MapBuffers()
	{
		return true;
	}

	bool SR_CommonPass::MapOpen(ID3D11Buffer * buffer, D3D11_MAPPED_SUBRESOURCE * mappedSubresource)
	{
		SR_LOG_RF_HR_AUTO(SR_App::GetInstance()->GetGraphic().GetD3DImmediateContext()->Map(buffer, 0, D3D11_MAP_WRITE_DISCARD, NULL, mappedSubresource));

		return true;
	}

	void SR_CommonPass::MapClose(ID3D11Buffer * buffer)
	{
		SR_App::GetInstance()->GetGraphic().GetD3DImmediateContext()->Unmap(buffer, 0);
	}

}