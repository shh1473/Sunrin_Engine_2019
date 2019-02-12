#pragma once

#include "SR_PCH.h"

#include "SR_NonCopyable.h"

#include <fbxsdk.h>

#pragma comment(lib, "libfbxsdk-md.lib")

namespace SunrinEngine
{

	class SR_Mesh : public SR_NonCopyable
	{
	public:
		explicit SR_Mesh() noexcept;

		bool CreateMesh(const std::wstring & filePath);

		unsigned GetVertexCount() const noexcept { return m_vertexCount; }
		ID3D11Buffer * GetPositionBuffer() const noexcept { return m_positionBuffer.Get(); }
		ID3D11Buffer * GetTexCoordBuffer() const noexcept { return m_texCoordBuffer.Get(); }
		ID3D11Buffer * GetNormalBuffer() const noexcept { return m_normalBuffer.Get(); }
		ID3D11Buffer * GetTangentBuffer() const noexcept { return m_tangentBuffer.Get(); }
		ID3D11Buffer * GetBinormalBuffer() const noexcept { return m_binormalBuffer.Get(); }

	private:
		unsigned m_vertexCount;
		Microsoft::WRL::ComPtr<ID3D11Buffer> m_positionBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> m_texCoordBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> m_normalBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> m_tangentBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> m_binormalBuffer;

	};

}