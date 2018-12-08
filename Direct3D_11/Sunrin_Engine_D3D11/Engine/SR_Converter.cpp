#include "SR_PCH.h"
#include "SR_Converter.h"

namespace SunrinEngine
{

	SR_Converter::SR_Converter() noexcept
	{

	}

	std::wstring SR_Converter::ToUnicode(const std::string & str) noexcept
	{
		return std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().from_bytes(str);
	}

	std::string SR_Converter::ToAscii(const std::wstring & str) noexcept
	{
		return std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().to_bytes(str);
	}

	std::wstring SR_Converter::DXDeviceFeatureLevel(D3D_FEATURE_LEVEL d3dFeatureevel) noexcept
	{
		switch (d3dFeatureevel)
		{
			case D3D_FEATURE_LEVEL_9_1:		return L"9.1";
			case D3D_FEATURE_LEVEL_9_2:		return L"9.2";
			case D3D_FEATURE_LEVEL_9_3:		return L"9.3";
			case D3D_FEATURE_LEVEL_10_0:	return L"10.0";
			case D3D_FEATURE_LEVEL_10_1:	return L"10.1";
			case D3D_FEATURE_LEVEL_11_0:	return L"11.0";
			case D3D_FEATURE_LEVEL_11_1:	return L"11.1";
			case D3D_FEATURE_LEVEL_12_0:	return L"12.0";
			case D3D_FEATURE_LEVEL_12_1:	return L"12.1";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXPrimitive(D3D_PRIMITIVE d3dPrimitive) noexcept
	{
		switch (d3dPrimitive)
		{
			case D3D_PRIMITIVE_UNDEFINED:				return L"Undefined";
			case D3D_PRIMITIVE_POINT:					return L"Point";
			case D3D_PRIMITIVE_LINE:					return L"Line";
			case D3D_PRIMITIVE_TRIANGLE:				return L"Triangle";
			case D3D_PRIMITIVE_LINE_ADJ:				return L"Line adjacent primitives";
			case D3D_PRIMITIVE_TRIANGLE_ADJ:			return L"Triangle adjacent primitives";
			case D3D_PRIMITIVE_1_CONTROL_POINT_PATCH:	return L"01 Control point patch";
			case D3D_PRIMITIVE_2_CONTROL_POINT_PATCH:	return L"02 Control point patch";
			case D3D_PRIMITIVE_3_CONTROL_POINT_PATCH:	return L"03 Control point patch";
			case D3D_PRIMITIVE_4_CONTROL_POINT_PATCH:	return L"04 Control point patch";
			case D3D_PRIMITIVE_5_CONTROL_POINT_PATCH:	return L"05 Control point patch";
			case D3D_PRIMITIVE_6_CONTROL_POINT_PATCH:	return L"06 Control point patch";
			case D3D_PRIMITIVE_7_CONTROL_POINT_PATCH:	return L"07 Control point patch";
			case D3D_PRIMITIVE_8_CONTROL_POINT_PATCH:	return L"08 Control point patch";
			case D3D_PRIMITIVE_9_CONTROL_POINT_PATCH:	return L"09 Control point patch";
			case D3D_PRIMITIVE_10_CONTROL_POINT_PATCH:	return L"10 Control point patch";
			case D3D_PRIMITIVE_11_CONTROL_POINT_PATCH:	return L"11 Control point patch";
			case D3D_PRIMITIVE_12_CONTROL_POINT_PATCH:	return L"12 Control point patch";
			case D3D_PRIMITIVE_13_CONTROL_POINT_PATCH:	return L"13 Control point patch";
			case D3D_PRIMITIVE_14_CONTROL_POINT_PATCH:	return L"14 Control point patch";
			case D3D_PRIMITIVE_15_CONTROL_POINT_PATCH:	return L"15 Control point patch";
			case D3D_PRIMITIVE_16_CONTROL_POINT_PATCH:	return L"16 Control point patch";
			case D3D_PRIMITIVE_17_CONTROL_POINT_PATCH:	return L"17 Control point patch";
			case D3D_PRIMITIVE_18_CONTROL_POINT_PATCH:	return L"18 Control point patch";
			case D3D_PRIMITIVE_19_CONTROL_POINT_PATCH:	return L"19 Control point patch";
			case D3D_PRIMITIVE_20_CONTROL_POINT_PATCH:	return L"20 Control point patch";
			case D3D_PRIMITIVE_21_CONTROL_POINT_PATCH:	return L"21 Control point patch";
			case D3D_PRIMITIVE_22_CONTROL_POINT_PATCH:	return L"22 Control point patch";
			case D3D_PRIMITIVE_23_CONTROL_POINT_PATCH:	return L"23 Control point patch";
			case D3D_PRIMITIVE_24_CONTROL_POINT_PATCH:	return L"24 Control point patch";
			case D3D_PRIMITIVE_25_CONTROL_POINT_PATCH:	return L"25 Control point patch";
			case D3D_PRIMITIVE_26_CONTROL_POINT_PATCH:	return L"26 Control point patch";
			case D3D_PRIMITIVE_27_CONTROL_POINT_PATCH:	return L"27 Control point patch";
			case D3D_PRIMITIVE_28_CONTROL_POINT_PATCH:	return L"28 Control point patch";
			case D3D_PRIMITIVE_29_CONTROL_POINT_PATCH:	return L"29 Control point patch";
			case D3D_PRIMITIVE_30_CONTROL_POINT_PATCH:	return L"30 Control point patch";
			case D3D_PRIMITIVE_31_CONTROL_POINT_PATCH:	return L"31 Control point patch";
			case D3D_PRIMITIVE_32_CONTROL_POINT_PATCH:	return L"32 Control point patch";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY d3dPrimitivetopology) noexcept
	{
		switch (d3dPrimitivetopology)
		{
			case D3D_PRIMITIVE_TOPOLOGY_UNDEFINED:					return L"Undefined";
			case D3D_PRIMITIVE_TOPOLOGY_POINTLIST:					return L"Point list";
			case D3D_PRIMITIVE_TOPOLOGY_LINELIST:					return L"Line list";
			case D3D_PRIMITIVE_TOPOLOGY_LINESTRIP:					return L"Line strip";
			case D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST:				return L"Triangle list";
			case D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP:				return L"Triangle strip";
			case D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ:				return L"Line list adjacent primitives";
			case D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ:				return L"Line strip adjacent primitives";
			case D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ:			return L"Triangle list adjacent primitives";
			case D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ:			return L"Triangle strip adjacent primitives";
			case D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST:	return L"01 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST:	return L"02 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST:	return L"03 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST:	return L"04 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST:	return L"05 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST:	return L"06 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST:	return L"07 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST:	return L"08 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST:	return L"09 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST:	return L"10 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST:	return L"11 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST:	return L"12 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST:	return L"13 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST:	return L"14 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST:	return L"15 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST:	return L"16 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST:	return L"17 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST:	return L"18 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST:	return L"19 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST:	return L"20 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST:	return L"21 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST:	return L"22 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST:	return L"23 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST:	return L"24 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST:	return L"25 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST:	return L"26 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST:	return L"27 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST:	return L"28 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST:	return L"29 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST:	return L"30 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST:	return L"31 Control point patch list";
			case D3D_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST:	return L"32 Control point patch list";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXTessellatorOutputPrimitive(D3D_TESSELLATOR_OUTPUT_PRIMITIVE d3dTessellatorOutputPrimitive) noexcept
	{
		switch (d3dTessellatorOutputPrimitive)
		{
			case D3D_TESSELLATOR_OUTPUT_UNDEFINED:		return L"Undefined";
			case D3D_TESSELLATOR_OUTPUT_POINT:			return L"Point";
			case D3D_TESSELLATOR_OUTPUT_LINE:			return L"Line";
			case D3D_TESSELLATOR_OUTPUT_TRIANGLE_CW:	return L"Triangle CW";
			case D3D_TESSELLATOR_OUTPUT_TRIANGLE_CCW:	return L"Triangle CCW";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXTessellatorPartitioning(D3D_TESSELLATOR_PARTITIONING d3dTessellatorPartitioning) noexcept
	{
		switch (d3dTessellatorPartitioning)
		{
			case D3D_TESSELLATOR_PARTITIONING_UNDEFINED:		return L"Undefined";
			case D3D_TESSELLATOR_PARTITIONING_INTEGER:			return L"Integer";
			case D3D_TESSELLATOR_PARTITIONING_POW2:				return L"Pow2";
			case D3D_TESSELLATOR_PARTITIONING_FRACTIONAL_ODD:	return L"Fractional odd";
			case D3D_TESSELLATOR_PARTITIONING_FRACTIONAL_EVEN:	return L"Fractional even";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXTessellatorDomain(D3D_TESSELLATOR_DOMAIN d3dTessellatorDomain) noexcept
	{
		switch (d3dTessellatorDomain)
		{
			case D3D_TESSELLATOR_DOMAIN_UNDEFINED:	return L"Undefined";
			case D3D_TESSELLATOR_DOMAIN_ISOLINE:	return L"Isoline";
			case D3D_TESSELLATOR_DOMAIN_TRI:		return L"Tri";
			case D3D_TESSELLATOR_DOMAIN_QUAD:		return L"Quad";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXConstantBufferType(D3D_CBUFFER_TYPE d3dCBufferType) noexcept
	{
		switch (d3dCBufferType)
		{
			case D3D_CT_CBUFFER:			return L"Constant buffer";
			case D3D_CT_TBUFFER:			return L"Texture buffer";
			case D3D_CT_INTERFACE_POINTERS: return L"Interface pointers";
			case D3D_CT_RESOURCE_BIND_INFO: return L"Resource bind info";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXShaderVariableClass(D3D_SHADER_VARIABLE_CLASS d3dShaderVariableClass) noexcept
	{
		switch (d3dShaderVariableClass)
		{
			case D3D_SVC_SCALAR:			return L"Scalar";
			case D3D_SVC_VECTOR:			return L"Vector";
			case D3D_SVC_MATRIX_ROWS:		return L"Matrix rows";
			case D3D_SVC_MATRIX_COLUMNS:	return L"Matrix columns";
			case D3D_SVC_OBJECT:			return L"Object";
			case D3D_SVC_STRUCT:			return L"Structure";
			case D3D_SVC_INTERFACE_CLASS:	return L"Interface class";
			case D3D_SVC_INTERFACE_POINTER:	return L"Interface pointer";
			case D3D_SVC_FORCE_DWORD:		return L"Force dword";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXShaderVariableType(D3D_SHADER_VARIABLE_TYPE d3dShaderVariableType) noexcept
	{
		switch (d3dShaderVariableType)
		{
			case D3D_SVT_VOID:						return L"Void";
			case D3D_SVT_BOOL:						return L"Boolean";
			case D3D_SVT_INT:						return L"Integer";
			case D3D_SVT_FLOAT:						return L"Float";
			case D3D_SVT_STRING:					return L"String";
			case D3D_SVT_TEXTURE:					return L"Texture";
			case D3D_SVT_TEXTURE1D:					return L"Texture-1D";
			case D3D_SVT_TEXTURE2D:					return L"Texture-2D";
			case D3D_SVT_TEXTURE3D:					return L"Texture-3D";
			case D3D_SVT_TEXTURECUBE:				return L"Texture-cube";
			case D3D_SVT_SAMPLER:					return L"Sampler";
			case D3D_SVT_SAMPLER1D:					return L"Sampler-1D";
			case D3D_SVT_SAMPLER2D:					return L"Sampler-2D";
			case D3D_SVT_SAMPLER3D:					return L"Sampler-3D";
			case D3D_SVT_SAMPLERCUBE:				return L"Sampler-cube";
			case D3D_SVT_PIXELSHADER:				return L"Pixel shader";
			case D3D_SVT_VERTEXSHADER:				return L"Vertex shader";
			case D3D_SVT_PIXELFRAGMENT:				return L"Pixel fragment";
			case D3D_SVT_VERTEXFRAGMENT:			return L"Vertex fragment";
			case D3D_SVT_UINT:						return L"Unsigned integer";
			case D3D_SVT_UINT8:						return L"Unsigned integer (8-bit)";
			case D3D_SVT_GEOMETRYSHADER:			return L"Geometry shader";
			case D3D_SVT_RASTERIZER:				return L"Rasterizer";
			case D3D_SVT_DEPTHSTENCIL:				return L"Depth stencil";
			case D3D_SVT_BLEND:						return L"Blend";
			case D3D_SVT_BUFFER:					return L"Buffer";
			case D3D_SVT_CBUFFER:					return L"Constant buffer";
			case D3D_SVT_TBUFFER:					return L"Texture buffer";
			case D3D_SVT_TEXTURE1DARRAY:			return L"Texture-1D array";
			case D3D_SVT_TEXTURE2DARRAY:			return L"Texture-2D array";
			case D3D_SVT_RENDERTARGETVIEW:			return L"Render target view";
			case D3D_SVT_DEPTHSTENCILVIEW:			return L"Depth stencil view";
			case D3D_SVT_TEXTURE2DMS:				return L"Texture-2D (multi-sampling)";
			case D3D_SVT_TEXTURE2DMSARRAY:			return L"Texture-2D (multi-sampling) array";
			case D3D_SVT_TEXTURECUBEARRAY:			return L"Texture-cube array";
			case D3D_SVT_HULLSHADER:				return L"Hull shader";
			case D3D_SVT_DOMAINSHADER:				return L"Domain shader";
			case D3D_SVT_INTERFACE_POINTER:			return L"Interface pointer";
			case D3D_SVT_COMPUTESHADER:				return L"Compute shader";
			case D3D_SVT_DOUBLE:					return L"Double";
			case D3D_SVT_RWTEXTURE1D:				return L"Read-and-write texture 1D";
			case D3D_SVT_RWTEXTURE1DARRAY:			return L"Read-and-write texture 1D array";
			case D3D_SVT_RWTEXTURE2D:				return L"Read-and-write texture 2D";
			case D3D_SVT_RWTEXTURE2DARRAY:			return L"Read-and-write texture 2D array";
			case D3D_SVT_RWTEXTURE3D:				return L"Read-and-write texture 3D";
			case D3D_SVT_RWBUFFER:					return L"Read-and-write buffer";
			case D3D_SVT_BYTEADDRESS_BUFFER:		return L"Byte-address buffer";
			case D3D_SVT_RWBYTEADDRESS_BUFFER:		return L"Read-and-write byte-address buffer";
			case D3D_SVT_STRUCTURED_BUFFER:			return L"Structured buffer";
			case D3D_SVT_RWSTRUCTURED_BUFFER:		return L"Read-and-write structured buffer";
			case D3D_SVT_APPEND_STRUCTURED_BUFFER:	return L"Append-structured buffer";
			case D3D_SVT_CONSUME_STRUCTURED_BUFFER:	return L"Consume-structured buffer";
			case D3D_SVT_MIN8FLOAT:					return L"Minimum-8-bit float";
			case D3D_SVT_MIN10FLOAT:				return L"Minimum-10-bit float";
			case D3D_SVT_MIN16FLOAT:				return L"Minimum-16-bit float";
			case D3D_SVT_MIN12INT:					return L"Minimum-12-bit integer";
			case D3D_SVT_MIN16INT:					return L"Minimum-16-bit integer";
			case D3D_SVT_MIN16UINT:					return L"Minimum-16-bit unsigned integer";
			case D3D_SVT_FORCE_DWORD:				return L"Force dword";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXShaderInputType(D3D_SHADER_INPUT_TYPE d3dShaderInputType) noexcept
	{
		switch (d3dShaderInputType)
		{
			case D3D_SIT_CBUFFER:						return L"Constant buffer";
			case D3D_SIT_TBUFFER:						return L"Texture buffer";
			case D3D_SIT_TEXTURE:						return L"Texture";
			case D3D_SIT_SAMPLER:						return L"Sampler";
			case D3D_SIT_UAV_RWTYPED:					return L"Read-and-write typed buffer";
			case D3D_SIT_STRUCTURED:					return L"Structured buffer";
			case D3D_SIT_UAV_RWSTRUCTURED:				return L"Read-and-write structured buffer";
			case D3D_SIT_BYTEADDRESS:					return L"Byte-address buffer";
			case D3D_SIT_UAV_RWBYTEADDRESS:				return L"Read-and-write byte-address buffer";
			case D3D_SIT_UAV_APPEND_STRUCTURED:			return L"Append-structured buffer";
			case D3D_SIT_UAV_CONSUME_STRUCTURED:		return L"Consume-structured buffer";
			case D3D_SIT_UAV_RWSTRUCTURED_WITH_COUNTER: return L"Read-and-write structured buffer with counter";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXResourceReturnType(D3D_RESOURCE_RETURN_TYPE d3dResourceReturnType) noexcept
	{
		switch (d3dResourceReturnType)
		{
			case D3D_RETURN_TYPE_UNORM:		return L"Unsigned norm";
			case D3D_RETURN_TYPE_SNORM:		return L"Signed norm";
			case D3D_RETURN_TYPE_SINT:		return L"Signed integer";
			case D3D_RETURN_TYPE_UINT:		return L"Unsigned integer";
			case D3D_RETURN_TYPE_FLOAT:		return L"Float";
			case D3D_RETURN_TYPE_MIXED:		return L"Mixed";
			case D3D_RETURN_TYPE_DOUBLE:	return L"Double";
			case D3D_RETURN_TYPE_CONTINUED: return L"Continued";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXShaderResourceViewDimension(D3D_SRV_DIMENSION d3dSRVDimension) noexcept
	{
		switch (d3dSRVDimension)
		{
			case D3D_SRV_DIMENSION_UNKNOWN:				return L"Unknown";
			case D3D_SRV_DIMENSION_BUFFER:				return L"Buffer";
			case D3D_SRV_DIMENSION_TEXTURE1D:			return L"Texture-1D";
			case D3D_SRV_DIMENSION_TEXTURE1DARRAY:		return L"Texture-1D array";
			case D3D_SRV_DIMENSION_TEXTURE2D:			return L"Texture-2D";
			case D3D_SRV_DIMENSION_TEXTURE2DARRAY:		return L"Texture-2D array";
			case D3D_SRV_DIMENSION_TEXTURE2DMS:			return L"Texture-2D (multi-sampling)";
			case D3D_SRV_DIMENSION_TEXTURE2DMSARRAY:	return L"Texture-2D (multi-sampling) array";
			case D3D_SRV_DIMENSION_TEXTURE3D:			return L"Texture-3D";
			case D3D_SRV_DIMENSION_TEXTURECUBE:			return L"Texture-cube";
			case D3D_SRV_DIMENSION_TEXTURECUBEARRAY:	return L"texture-cube array";
			case D3D_SRV_DIMENSION_BUFFEREX:			return L"Raw buffer";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXName(D3D_NAME d3dName) noexcept
	{
		switch (d3dName)
		{
			case D3D_NAME_UNDEFINED:						return L"Undefined";
			case D3D_NAME_POSITION:							return L"Position";
			case D3D_NAME_CLIP_DISTANCE:					return L"Clip distance";
			case D3D_NAME_CULL_DISTANCE:					return L"Cull distance";
			case D3D_NAME_RENDER_TARGET_ARRAY_INDEX:		return L"Render target array index";
			case D3D_NAME_VIEWPORT_ARRAY_INDEX:				return L"Viewport array index";
			case D3D_NAME_VERTEX_ID:						return L"Vertex ID";
			case D3D_NAME_PRIMITIVE_ID:						return L"Primitive ID";
			case D3D_NAME_INSTANCE_ID:						return L"Instance ID";
			case D3D_NAME_IS_FRONT_FACE:					return L"Is front face";
			case D3D_NAME_SAMPLE_INDEX:						return L"Sample index";
			case D3D_NAME_FINAL_QUAD_EDGE_TESSFACTOR:		return L"Final quad edge tessfactor";
			case D3D_NAME_FINAL_QUAD_INSIDE_TESSFACTOR:		return L"Final quad inside tessfactor";
			case D3D_NAME_FINAL_TRI_EDGE_TESSFACTOR:		return L"Final tri edge tessfactor";
			case D3D_NAME_FINAL_TRI_INSIDE_TESSFACTOR:		return L"Final tri inside tessfactor";
			case D3D_NAME_FINAL_LINE_DETAIL_TESSFACTOR:		return L"Final line detail tessfactor";
			case D3D_NAME_FINAL_LINE_DENSITY_TESSFACTOR:	return L"Final line density tessfactor";
			case D3D_NAME_BARYCENTRICS:						return L"Barycentrics";
			case D3D_NAME_TARGET:							return L"Target";
			case D3D_NAME_DEPTH:							return L"Depth";
			case D3D_NAME_COVERAGE:							return L"Coverage";
			case D3D_NAME_DEPTH_GREATER_EQUAL:				return L"Depth greater equal";
			case D3D_NAME_STENCIL_REF:						return L"Stencil reference";
			case D3D_NAME_INNER_COVERAGE:					return L"Inner coverage";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXRegisterComponentType(D3D_REGISTER_COMPONENT_TYPE d3dRegisterComponentType) noexcept
	{
		switch (d3dRegisterComponentType)
		{
			case D3D_REGISTER_COMPONENT_UNKNOWN:	return L"Unknown";
			case D3D_REGISTER_COMPONENT_UINT32:		return L"32-bit unsigned integer";
			case D3D_REGISTER_COMPONENT_SINT32:		return L"32-bit signed integer";
			case D3D_REGISTER_COMPONENT_FLOAT32:	return L"32-bit float";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXGIFormat(DXGI_FORMAT dxgiFormat) noexcept
	{
		switch (dxgiFormat)
		{
			case DXGI_FORMAT_UNKNOWN:						return L"Unspecified";
			case DXGI_FORMAT_R32G32B32A32_TYPELESS:			return L"R32G32B32A32 typeless";
			case DXGI_FORMAT_R32G32B32A32_FLOAT:			return L"R32G32B32A32 float";
			case DXGI_FORMAT_R32G32B32A32_UINT:				return L"R32G32B32A32 unsigned int";
			case DXGI_FORMAT_R32G32B32A32_SINT:				return L"R32G32B32A32 signed int";
			case DXGI_FORMAT_R32G32B32_TYPELESS:			return L"R32G32B32 typeless";
			case DXGI_FORMAT_R32G32B32_FLOAT:				return L"R32G32B32 float";
			case DXGI_FORMAT_R32G32B32_UINT:				return L"R32G32B32 unsigned int";
			case DXGI_FORMAT_R32G32B32_SINT:				return L"R32G32B32 signed int";
			case DXGI_FORMAT_R16G16B16A16_TYPELESS:			return L"R16G16B16A16 typeless";
			case DXGI_FORMAT_R16G16B16A16_FLOAT:			return L"R16G16B16A16 float";
			case DXGI_FORMAT_R16G16B16A16_UNORM:			return L"R16G16B16A16 unsigned norm";
			case DXGI_FORMAT_R16G16B16A16_UINT:				return L"R16G16B16A16 unsigned int";
			case DXGI_FORMAT_R16G16B16A16_SNORM:			return L"R16G16B16A16 signed norm";
			case DXGI_FORMAT_R16G16B16A16_SINT:				return L"R16G16B16A16 signed int";
			case DXGI_FORMAT_R32G32_TYPELESS:				return L"R32G32 typeless";
			case DXGI_FORMAT_R32G32_FLOAT:					return L"R32G32 float";
			case DXGI_FORMAT_R32G32_UINT:					return L"R32G32 unsigned int";
			case DXGI_FORMAT_R32G32_SINT:					return L"R32G32 signed int";
			case DXGI_FORMAT_R32G8X24_TYPELESS:				return L"R32G8X24 typeless";
			case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:			return L"D32 float S8X24 unsigned int";
			case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:		return L"R32 float X8X24 typeless";
			case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:		return L"X32 typeless G8X24 unsigned int";
			case DXGI_FORMAT_R10G10B10A2_TYPELESS:			return L"R10G10B10A2 typeless";
			case DXGI_FORMAT_R10G10B10A2_UNORM:				return L"R10G10B10A2 unsigned norm";
			case DXGI_FORMAT_R10G10B10A2_UINT:				return L"R10G10B10A2 unsigned int";
			case DXGI_FORMAT_R11G11B10_FLOAT:				return L"R11G11B10 float";
			case DXGI_FORMAT_R8G8B8A8_TYPELESS:				return L"R8G8B8A8 typeless";
			case DXGI_FORMAT_R8G8B8A8_UNORM:				return L"R8G8B8A8 unsigned norm";
			case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:			return L"R8G8B8A8 unsigned norm sRGB";
			case DXGI_FORMAT_R8G8B8A8_UINT:					return L"R8G8B8A8 unsigned int";
			case DXGI_FORMAT_R8G8B8A8_SNORM:				return L"R8G8B8A8 signed norm";
			case DXGI_FORMAT_R8G8B8A8_SINT:					return L"R8G8B8A8 signed int";
			case DXGI_FORMAT_R16G16_TYPELESS:				return L"R16G16 typeless";
			case DXGI_FORMAT_R16G16_FLOAT:					return L"R16G16 float";
			case DXGI_FORMAT_R16G16_UNORM:					return L"R16G16 unsigned norm";
			case DXGI_FORMAT_R16G16_UINT:					return L"R16G16 unsigned int";
			case DXGI_FORMAT_R16G16_SNORM:					return L"R16G16 signed norm";
			case DXGI_FORMAT_R16G16_SINT:					return L"R16G16 signed int";
			case DXGI_FORMAT_R32_TYPELESS:					return L"R32 typeless";
			case DXGI_FORMAT_D32_FLOAT:						return L"D32 float";
			case DXGI_FORMAT_R32_FLOAT:						return L"R32 float";
			case DXGI_FORMAT_R32_UINT:						return L"R32 unsigned int";
			case DXGI_FORMAT_R32_SINT:						return L"R32 signed int";
			case DXGI_FORMAT_R24G8_TYPELESS:				return L"R24G8 typeless";
			case DXGI_FORMAT_D24_UNORM_S8_UINT:				return L"D24 unsigned norm S8 unsigned int";
			case DXGI_FORMAT_R24_UNORM_X8_TYPELESS:			return L"R24 unsigned norm X8 typeless";
			case DXGI_FORMAT_X24_TYPELESS_G8_UINT:			return L"X24 typeless G8 unsigned int";
			case DXGI_FORMAT_R8G8_TYPELESS:					return L"R8G8 typeless";
			case DXGI_FORMAT_R8G8_UNORM:					return L"R8G8 unsigned norm";
			case DXGI_FORMAT_R8G8_UINT:						return L"R8G8 unsigned int";
			case DXGI_FORMAT_R8G8_SNORM:					return L"R8G8 signed norm";
			case DXGI_FORMAT_R8G8_SINT:						return L"R8G8 signed int";
			case DXGI_FORMAT_R16_TYPELESS:					return L"R16 typeless";
			case DXGI_FORMAT_R16_FLOAT:						return L"R16 float";
			case DXGI_FORMAT_D16_UNORM:						return L"D16 unsigned norm";
			case DXGI_FORMAT_R16_UNORM:						return L"R16 unsigned norm";
			case DXGI_FORMAT_R16_UINT:						return L"R16 unsigned int";
			case DXGI_FORMAT_R16_SNORM:						return L"R16 signed norm";
			case DXGI_FORMAT_R16_SINT:						return L"R16 signed int";
			case DXGI_FORMAT_R8_TYPELESS:					return L"R8 typeless";
			case DXGI_FORMAT_R8_UNORM:						return L"R8 unsigned norm";
			case DXGI_FORMAT_R8_UINT:						return L"R8 unsigned int";
			case DXGI_FORMAT_R8_SNORM:						return L"R8 signed norm";
			case DXGI_FORMAT_R8_SINT:						return L"R8 signed int";
			case DXGI_FORMAT_A8_UNORM:						return L"A8 unsigned norm";
			case DXGI_FORMAT_R1_UNORM:						return L"R1 unsigned norm";
			case DXGI_FORMAT_R9G9B9E5_SHAREDEXP:			return L"R9G9B9E5 shared exponent";
			case DXGI_FORMAT_R8G8_B8G8_UNORM:				return L"R8G8 B8G8 unsigned norm";
			case DXGI_FORMAT_G8R8_G8B8_UNORM:				return L"G8R8 G8B8 unsigned norm";
			case DXGI_FORMAT_BC1_TYPELESS:					return L"Block-compression 1 typeless";
			case DXGI_FORMAT_BC1_UNORM:						return L"Block-compression 1 unsigned norm";
			case DXGI_FORMAT_BC1_UNORM_SRGB:				return L"Block-compression 1 unsigned norm sRGB";
			case DXGI_FORMAT_BC2_TYPELESS:					return L"Block-compression 2 typeless";
			case DXGI_FORMAT_BC2_UNORM:						return L"Block-compression 2 unsigned norm";
			case DXGI_FORMAT_BC2_UNORM_SRGB:				return L"Block-compression 2 unsigned norm sRGB";
			case DXGI_FORMAT_BC3_TYPELESS:					return L"Block-compression 3 typeless";
			case DXGI_FORMAT_BC3_UNORM:						return L"Block-compression 3 unsigned norm";
			case DXGI_FORMAT_BC3_UNORM_SRGB:				return L"Block-compression 3 unsigned norm sRGB";
			case DXGI_FORMAT_BC4_TYPELESS:					return L"Block-compression 4 typeless";
			case DXGI_FORMAT_BC4_UNORM:						return L"Block-compression 4 unsigned norm";
			case DXGI_FORMAT_BC4_SNORM:						return L"Block-compression 4 signed norm";
			case DXGI_FORMAT_BC5_TYPELESS:					return L"Block-compression 5 typeless";
			case DXGI_FORMAT_BC5_UNORM:						return L"Block-compression 5 unsigned norm";
			case DXGI_FORMAT_BC5_SNORM:						return L"Block-compression 5 signed norm";
			case DXGI_FORMAT_B5G6R5_UNORM:					return L"B5G6R5 unsigned norm";
			case DXGI_FORMAT_B5G5R5A1_UNORM:				return L"B5G5R5A1 unsigned norm";
			case DXGI_FORMAT_B8G8R8A8_UNORM:				return L"B8G8R8A8 unsigned norm";
			case DXGI_FORMAT_B8G8R8X8_UNORM:				return L"B8G8R8X8 unsigned norm";
			case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:	return L"R10G10B10 2.8 biased fixed-point A2 unsigned norm";
			case DXGI_FORMAT_B8G8R8A8_TYPELESS:				return L"B8G8R8A8 typeless";
			case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:			return L"B8G8R8A8 unsigned norm sRGB";
			case DXGI_FORMAT_B8G8R8X8_TYPELESS:				return L"B8G8R8X8 typeless";
			case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:			return L"B8G8R8X8 unsigned norm sRGB";
			case DXGI_FORMAT_BC6H_TYPELESS:					return L"Block-compression 6 half typeless";
			case DXGI_FORMAT_BC6H_UF16:						return L"Block-compression 6 half 16-bit unsigned float";
			case DXGI_FORMAT_BC6H_SF16:						return L"Block-compression 6 half 16-bit signed float";
			case DXGI_FORMAT_BC7_TYPELESS:					return L"Block-compression 7 typeless";
			case DXGI_FORMAT_BC7_UNORM:						return L"Block-compression 7 unsigned norm";
			case DXGI_FORMAT_BC7_UNORM_SRGB:				return L"Block-compression 7 unsigned norm sRGB";
			case DXGI_FORMAT_AYUV:							return L"AYUV";
			case DXGI_FORMAT_Y410:							return L"Y410";
			case DXGI_FORMAT_Y416:							return L"Y416";
			case DXGI_FORMAT_NV12:							return L"NV12";
			case DXGI_FORMAT_P010:							return L"P010";
			case DXGI_FORMAT_P016:							return L"P016";
			case DXGI_FORMAT_420_OPAQUE:					return L"420 opaque";
			case DXGI_FORMAT_YUY2:							return L"YUY2";
			case DXGI_FORMAT_Y210:							return L"Y210";
			case DXGI_FORMAT_Y216:							return L"Y216";
			case DXGI_FORMAT_NV11:							return L"NV11";
			case DXGI_FORMAT_AI44:							return L"AI44";
			case DXGI_FORMAT_IA44:							return L"IA44";
			case DXGI_FORMAT_P8:							return L"P8";
			case DXGI_FORMAT_A8P8:							return L"A8P8";
			case DXGI_FORMAT_B4G4R4A4_UNORM:				return L"B4G4R4A4 unsigned norm";
			case DXGI_FORMAT_P208:							return L"P208";
			case DXGI_FORMAT_V208:							return L"V208";
			case DXGI_FORMAT_V408:							return L"V408";
			case DXGI_FORMAT_FORCE_UINT:					return L"Force unsigned int";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXGIModeScanlineOrdering(DXGI_MODE_SCANLINE_ORDER dxgiModeScanlineOrder) noexcept
	{
		switch (dxgiModeScanlineOrder)
		{
			case DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED:			return L"Unspecified";
			case DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE:			return L"Progressive";
			case DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST:	return L"Upper field first";
			case DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST:	return L"Lower field first";
			default: return L"Unknown";
		}
	}

	std::wstring SR_Converter::DXGIModeScaling(DXGI_MODE_SCALING dxgiModeScaling) noexcept
	{
		switch (dxgiModeScaling)
		{
			case DXGI_MODE_SCALING_UNSPECIFIED:	return L"Unspecified";
			case DXGI_MODE_SCALING_CENTERED:	return L"Centered";
			case DXGI_MODE_SCALING_STRETCHED:	return L"Stretched";
			default: return L"Unknown";
		}
	}

}