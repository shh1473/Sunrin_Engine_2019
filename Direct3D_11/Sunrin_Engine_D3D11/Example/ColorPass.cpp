#include "SR_PCH.h"

#include "ColorPass.h"

namespace Example
{

	ColorPass::ColorPass(SR_ForwardRenderer * owner) noexcept :
		SR_DrawPass(owner),
		m_inputParameterSet			{ nullptr },
		m_vertexShaderParameterSet	{ nullptr },
		m_pixelShaderParameterSet	{ nullptr },
		m_vs_matrixBuffer			{ nullptr },
		m_df_matrixBuffer			{}
	{

	}

	bool ColorPass::Initialize(
		SR_Mesh * mesh,
		SR_VertexShader * vertexShader,
		SR_PixelShader * pixelShader,
		ID3D11Buffer * vs_matrixBuffer)
	{
		m_vs_matrixBuffer = vs_matrixBuffer;

		m_inputParameterSet = std::make_unique<SR_InputParameterSet>(GetOwner(), 1);
		m_inputParameterSet->SetIsBindVertexBuffer(true);
		m_inputParameterSet->SetIsBindPrimitiveTopology(true);
		m_inputParameterSet->SetVertexBufferStartSlot(0);
		m_inputParameterSet->SetVertexBufferCount(1);
		m_inputParameterSet->SetVertexBuffer(0, mesh->GetPositionBuffer());
		m_inputParameterSet->SetVertexBufferStride(0, sizeof(SR_Vector3));
		m_inputParameterSet->SetVertexBufferOffset(0, 0);
		m_inputParameterSet->SetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		m_vertexShaderParameterSet = std::make_unique<SR_VertexShaderParameterSet>(GetOwner(), 0, 1, 0, 0);
		m_vertexShaderParameterSet->SetIsBindShader(true);
		m_vertexShaderParameterSet->SetIsBindInputLayout(true);
		m_vertexShaderParameterSet->SetIsBindConstantBuffer(true);
		m_vertexShaderParameterSet->SetIsBindShaderResourceView(false);
		m_vertexShaderParameterSet->SetIsBindSamplerState(false);
		m_vertexShaderParameterSet->SetVertexShader(vertexShader->GetVertexShader());
		m_vertexShaderParameterSet->SetInputLayout(vertexShader->GetInputLayout());
		m_vertexShaderParameterSet->SetConstantBufferStartSlot(0);
		m_vertexShaderParameterSet->SetConstantBufferCount(1);
		m_vertexShaderParameterSet->SetConstantBuffer(0, m_vs_matrixBuffer);

		m_pixelShaderParameterSet = std::make_unique<SR_PixelShaderParameterSet>(GetOwner(), 0, 0, 0, 0);
		m_pixelShaderParameterSet->SetIsBindShader(true);
		m_pixelShaderParameterSet->SetIsBindConstantBuffer(false);
		m_pixelShaderParameterSet->SetIsBindShaderResourceView(false);
		m_pixelShaderParameterSet->SetIsBindSamplerState(false);
		m_pixelShaderParameterSet->SetPixelShader(pixelShader->GetPixelShader());

		SetInputParameterSet(m_inputParameterSet.get());
		SetVertexShaderParameterSet(m_vertexShaderParameterSet.get());
		SetPixelShaderParameterSet(m_pixelShaderParameterSet.get());

		SetVertexCount(mesh->GetVertexCount());
		SetStartVertexLocation(0);

		return true;
	}

	bool ColorPass::MapBuffers()
	{
		m_df_matrixBuffer.m_worldMatrix.Set(GetOwner()->GetOwner()->GetTransform()->GetWorldMatrix());
		m_df_matrixBuffer.m_viewMatrix.Set(GetOwner()->GetOwner()->GetGameScene()->GetRenderExecutor().GetCurrentCamera()->GetViewMatrix());
		m_df_matrixBuffer.m_projMatrix.Set(GetOwner()->GetOwner()->GetGameScene()->GetRenderExecutor().GetCurrentCamera()->GetProjMatrix());

		if (m_df_matrixBuffer.Check())
		{
			static VS_MatrixBuffer MatrixBuffer;

			MatrixBuffer.m_WVPMatrix = m_df_matrixBuffer.m_worldMatrix.GetValue();
			MatrixBuffer.m_WVPMatrix *= m_df_matrixBuffer.m_viewMatrix.GetValue();
			MatrixBuffer.m_WVPMatrix *= m_df_matrixBuffer.m_projMatrix.GetValue();
			MatrixBuffer.m_WVPMatrix.Transpose();

			SR_RF_BOOL(Map(m_vs_matrixBuffer, MatrixBuffer));

			m_df_matrixBuffer.Reset();
		}

		return true;
	}

}