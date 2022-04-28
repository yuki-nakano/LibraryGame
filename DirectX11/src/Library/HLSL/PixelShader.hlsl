
struct PSInput
{
	float4 pos : SV_POSITION;
	float4 col : COLOR0;
};

float4 main(PSInput input) : SV_Target
{
	return input.col;
}