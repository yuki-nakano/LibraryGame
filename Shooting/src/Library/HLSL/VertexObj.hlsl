
cbuffer ConstantBuffer
{
	float4x4 world;
	float4x4 view;
	float4x4 proj;
	float4 LightVector;
	float4 LightColor;
	float4 ambient;
	float4 diffuse;
	float4 col;
};

struct VSInput
{
	float4 pos : POSITION0;
	float4 nor : NORMAL;
	float4 tex : TEXTURE;
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

	output.col = col;

	// ���C�g�̃J���[* ���̂��������
	output.col += LightColor * rad;
	output.col[3] = col[3];

	return output;
}