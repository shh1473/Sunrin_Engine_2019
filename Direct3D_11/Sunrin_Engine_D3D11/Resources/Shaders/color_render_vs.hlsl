cbuffer MatrixBuffer : register(b0)
{
	matrix C_WVPMatrix : packoffset(c0);
};

struct VS_INPUT
{
	float4 m_position : POSITION;
};

struct VS_OUTPUT
{
	float4 m_position : SV_Position;
};

VS_OUTPUT vs_main(VS_INPUT Input)
{
	VS_OUTPUT Output;

	Input.m_position.w = 1.0f;

	Output.m_position = mul(Input.m_position, C_WVPMatrix);

	return Output;
}