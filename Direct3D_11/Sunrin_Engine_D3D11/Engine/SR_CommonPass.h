#pragma once

#include "SR_InputParameterSet.h"
#include "SR_StreamParameterSet.h"
#include "SR_VertexShaderParameterSet.h"
#include "SR_HullShaderParameterSet.h"
#include "SR_DomainShaderParameterSet.h"
#include "SR_GeometryShaderParameterSet.h"
#include "SR_PixelShaderParameterSet.h"
#include "SR_ComputeShaderParameterSet.h"

namespace SunrinEngine
{

	class SR_CommonPass : public SR_NonCopyable
	{
	public:
		explicit SR_CommonPass(SR_Component * owner) noexcept;

		virtual bool Render(unsigned threadID) = 0;

		void SetInputParameterSet(SR_InputParameterSet * inputParameterSet) noexcept { m_inputParameterSet = inputParameterSet; }
		void SetStreamParameterSet(SR_StreamParameterSet * streamParameterSet) noexcept { m_streamParameterSet = streamParameterSet; }
		void SetVertexShaderParameterSet(SR_VertexShaderParameterSet * vertexShaderParameterSet) noexcept { m_vertexShaderParameterSet = vertexShaderParameterSet; }
		void SetHullShaderParameterSet(SR_HullShaderParameterSet * hullShaderParameterSet) noexcept { m_hullShaderParameterSet = hullShaderParameterSet; }
		void SetDomainShaderParameterSet(SR_DomainShaderParameterSet * domainShaderParameterSet) noexcept { m_domainShaderParameterSet = domainShaderParameterSet; }
		void SetGeometryShaderParameterSet(SR_GeometryShaderParameterSet * geometryShaderParameterSet) noexcept { m_geometryShaderParameterSet = geometryShaderParameterSet; }
		void SetPixelShaderParameterSet(SR_PixelShaderParameterSet * pixelShaderParameterSet) noexcept { m_pixelShaderParameterSet = pixelShaderParameterSet; }
		void SetComputeShaderParameterSet(SR_ComputeShaderParameterSet * computeShaderParameterSet) noexcept { m_computeShaderParameterSet = computeShaderParameterSet; }

	public:
		template <typename T>
		bool Map(ID3D11Buffer * buffer, const T & data)
		{
			D3D11_MAPPED_SUBRESOURCE mappedSubresource{ nullptr, 0, 0 };

			SR_RF_BOOL(MapOpen(buffer, &mappedSubresource));

			*reinterpret_cast<T*>(mappedSubresource.pData) = data;

			MapClose(buffer);

			return true;
		}

	protected:
		bool Apply(unsigned threadID);

		virtual bool MapBuffers();

		SR_Component * GetOwner() const noexcept { return m_owner; }

	private:
		bool MapOpen(ID3D11Buffer * buffer, D3D11_MAPPED_SUBRESOURCE * mappedSubresource);
		void MapClose(ID3D11Buffer * buffer);

	private:
		SR_Component * m_owner;
		SR_InputParameterSet * m_inputParameterSet;
		SR_StreamParameterSet * m_streamParameterSet;
		SR_VertexShaderParameterSet * m_vertexShaderParameterSet;
		SR_HullShaderParameterSet * m_hullShaderParameterSet;
		SR_DomainShaderParameterSet * m_domainShaderParameterSet;
		SR_GeometryShaderParameterSet * m_geometryShaderParameterSet;
		SR_PixelShaderParameterSet * m_pixelShaderParameterSet;
		SR_ComputeShaderParameterSet * m_computeShaderParameterSet;

	};

}