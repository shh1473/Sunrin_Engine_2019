#pragma once

#include "..\SunrinEngine.h"
using namespace SunrinEngine;

namespace Example
{

	class ColorPass : public SR_DrawPass
	{
	public:
		struct VS_MatrixBuffer
		{
			SR_Matrix4x4 m_WVPMatrix;
		};

	public:
		class DirtyFlag_MatrixBuffer
		{
		public:
			explicit DirtyFlag_MatrixBuffer()
			{
				m_worldMatrix.Set(SR_Matrix4x4::m_IDENTITY);
				m_viewMatrix.Set(SR_Matrix4x4::m_IDENTITY);
				m_projMatrix.Set(SR_Matrix4x4::m_IDENTITY);

				m_worldMatrix.Reset();
				m_viewMatrix.Reset();
				m_projMatrix.Reset();
			}

			bool Check()
			{
				return
					m_worldMatrix.Check() ||
					m_viewMatrix.Check() ||
					m_projMatrix.Check();
			}

			void Reset()
			{
				m_worldMatrix.Reset();
				m_viewMatrix.Reset();
				m_projMatrix.Reset();
			}

		public:
			SR_DirtyFlagMatrix4x4 m_worldMatrix;
			SR_DirtyFlagMatrix4x4 m_viewMatrix;
			SR_DirtyFlagMatrix4x4 m_projMatrix;

		};

	public:
		explicit ColorPass(SR_ForwardRenderer * owner) noexcept;

		bool Initialize(
			SR_Mesh * mesh,
			SR_VertexShader * vertexShader,
			SR_PixelShader * pixelShader,
			ID3D11Buffer * vs_matrixBuffer);

	protected:
		virtual bool MapBuffers() override;

	private:
		std::unique_ptr<SR_InputParameterSet> m_inputParameterSet;
		std::unique_ptr<SR_VertexShaderParameterSet> m_vertexShaderParameterSet;
		std::unique_ptr<SR_PixelShaderParameterSet> m_pixelShaderParameterSet;

		ID3D11Buffer * m_vs_matrixBuffer;
		DirtyFlag_MatrixBuffer m_df_matrixBuffer;

	};

}