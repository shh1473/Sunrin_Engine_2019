#pragma once

#include "SR_PCH.h"

namespace SunrinEngine
{

	class SR_Converter
	{
	public:
		static std::wstring ToUnicode(const std::string & str) noexcept;
		static std::string ToAscii(const std::wstring & str) noexcept;

		static std::wstring DXDeviceFeatureLevel(D3D_FEATURE_LEVEL d3dFeatureevel) noexcept;
		static std::wstring DXPrimitive(D3D_PRIMITIVE d3dPrimitive) noexcept;
		static std::wstring DXPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY d3dPrimitivetopology) noexcept;
		static std::wstring DXTessellatorOutputPrimitive(D3D_TESSELLATOR_OUTPUT_PRIMITIVE d3dTessellatorOutputPrimitive) noexcept;
		static std::wstring DXTessellatorPartitioning(D3D_TESSELLATOR_PARTITIONING d3dTessellatorPartitioning) noexcept;
		static std::wstring DXTessellatorDomain(D3D_TESSELLATOR_DOMAIN d3dTessellatorDomain) noexcept;
		static std::wstring DXConstantBufferType(D3D_CBUFFER_TYPE d3dCBufferType) noexcept;
		static std::wstring DXShaderVariableClass(D3D_SHADER_VARIABLE_CLASS d3dShaderVariableClass) noexcept;
		static std::wstring DXShaderVariableType(D3D_SHADER_VARIABLE_TYPE d3dShaderVariableType) noexcept;
		static std::wstring DXShaderInputType(D3D_SHADER_INPUT_TYPE d3dShaderInputType) noexcept;
		static std::wstring DXResourceReturnType(D3D_RESOURCE_RETURN_TYPE d3dResourceReturnType) noexcept;
		static std::wstring DXShaderResourceViewDimension(D3D_SRV_DIMENSION d3dSRVDimension) noexcept;
		static std::wstring DXName(D3D_NAME d3dName) noexcept;
		static std::wstring DXRegisterComponentType(D3D_REGISTER_COMPONENT_TYPE d3dRegisterComponentType) noexcept;
		static std::wstring DXGIFormat(DXGI_FORMAT dxgiFormat) noexcept;
		static std::wstring DXGIModeScanlineOrdering(DXGI_MODE_SCANLINE_ORDER dxgiModeScanlineOrder) noexcept;
		static std::wstring DXGIModeScaling(DXGI_MODE_SCALING dxgiModeScaling) noexcept;

	private:
		explicit SR_Converter() noexcept;

	};

}