struct PS_INPUT
{
	float4 m_position : SV_Position;
};

struct PS_OUTPUT
{
	float4 m_target0 : SV_Target0;
};

PS_OUTPUT ps_main(PS_INPUT Input)
{
	PS_OUTPUT Output;

	Output.m_target0 = float4(1.0f, 0.0f, 0.0f, 1.0f);

	return Output;
}