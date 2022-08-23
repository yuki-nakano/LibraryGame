
cbuffer ConstantBuffer
{
	float4x4 world;
	float4x4 view;
	float4x4 proj;
	float4	LightVector;
	float4	LightColor;
};

struct VSInput
{
	float4 pos : POSITION0;
	float2 tex : TEXTURE;
	float4 nor : NORMAL;
};

struct VSOutput
{
	float4 pos : SV_POSITION;
	float4 col : COLOR0;
};

VSOutput main(VSInput input)
{
	VSOutput output;

	output.pos = input.pos;

	output.pos = mul(output.pos, world);
	output.pos = mul(output.pos, view);
	output.pos = mul(output.pos, proj);

	float4 normal;
	input.nor.w = 0.0;
	// ���_�̖@���Ƀ��[���h�s����|�����킹�ă��[���h���W��ł̖@���̌����ɕϊ�����
	normal = mul(input.nor, world).xyzw;
	normal = normalize(normal);
	// saturate:�����Ŏw�肵���l��0�`1�Ԃł͈̔͂Ɏ��߂�
	float rad = saturate(dot(normal, LightVector));

	// ���C�g�̃J���[ * ���̂��������
	output.col = LightColor * rad;
	output.col[3] = 1.0f;

	return output;
}