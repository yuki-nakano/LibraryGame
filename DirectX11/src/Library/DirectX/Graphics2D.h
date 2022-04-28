#ifndef GRAPHICS_2D_H
#define GRAPHICS_2D_H

#include <DirectXMath.h>

#include "../Shader/ShaderManager.h"
#include "../DirectX/Matrix.h"
#include "../Utility/Singleton.h" 

namespace engine
{
	class Graphics2D : public Singleton<Graphics2D>
	{
	private:
		struct ConstantBuffer {
			DirectX::XMFLOAT4X4 world;
			DirectX::XMFLOAT4 viewport;
		};

		struct CustomVertex
		{
			float pos[4];
			float col[4];
		};

	private:
		friend class Singleton<Graphics2D>;

		Graphics2D();
		~Graphics2D();

	public:
		void DrawPorigon(float pos_x_, float pos_y_, float width_, float height_, float angle_ = 0.0f);
		void DrawRect(float pos_x_, float pos_y_, float width_, float height_, float angle_ = 0.0f);

		void Init();
		void Relese();

	private:
		void CreateRect();

	private:
		std::string m_vShaderName{ "Vertex2D" };
		std::string m_pShaderName{ "PixelBase" };

		ID3D11InputLayout* m_inputLayout{};
		ID3D11Buffer* m_indexBuffer{};
		ID3D11Buffer* m_vertexBuffer{};
		ID3D11Buffer* m_constantBuffer;

	};
}

#endif // !DIRECTX_GRAPHICS_2D_H
