#ifndef DIRECTX_TEXTURE_H
#define DIRECTX_TEXTURE_H

#include <string>
#include <map>
#include <d3d11.h>
#include <DirectXMath.h>

#include "../DirectX/DirectXUtility.h"
#include "../Utility/Singleton.h"

namespace engine
{
	class DirectXTexture : public Singleton<DirectXTexture>
	{
	private:
		struct ConstantBuffer
		{
			DirectX::XMFLOAT4X4 world;
			DirectX::XMFLOAT4 viewport;
		};

		struct CustomVertex
		{
			float pos[3];
			float uv[2];
		};

	private:
		friend class Singleton<DirectXTexture>;

		DirectXTexture();
		~DirectXTexture();

	public:
		/**
		* @brief 初期化
		*/
		bool Init();

		/**
		* @brief 解放
		*/
		void Relese();

		/**
		* @brief テクスチャの読み込み
		* @param file_name_ 読み込むテクスチャファイルパス
		* @param name_　テクスチャ呼び出し時の名前
		* @return 読み込み成功時true
		*/
		bool LoadTexture(const std::wstring& file_name_, const std::string& name_);

		/**
		* @brief
		* @param name_ LoadTexture関数で登録した名前
		* @param pos_x_ x座標
		* @param pos_y_ y座標
		* @param widht_ 幅
		* @param height_ 高さ
		* @param angle_ 角度
		*/
		void DrawTexture(const std::string& name_, float pos_x_, float pos_y_, float width_, float height_, float angle_ = 0.0f);

		/**
		* @brief テクスチャの解放
		*/
		void ReleseTexture(const std::string& name_);

	private:
		/**
		* @brief VertexBufferの作成
		* @return 作成成功時true
		*/
		bool CreateVertexBuffer();

		/**
		* @brief IndexBufferの作成
		* @return 作成成功時true
		*/
		bool CreateIndexBuffer();

		/**
		* @brief InputLayoutの作成
		* @return 作成成功時true
		*/
		bool CreateInputLayout();

		/**
		* @brief ConstantBufferの作成
		* @return 作成成功時true
		*/
		bool CreateConstantBuffer();

		/**
		* @brief Samplerの作成
		* @return 作成成功時true
		*/
		bool CreateSampler();

	private:
		std::map<std::string, ID3D11ShaderResourceView*> texList{};

		std::string m_vShaderName{ "VertexTex" };
		std::string m_pShaderName{ "PixelTex" };

		ID3D11Buffer* m_vertexBuffer;
		ID3D11Buffer* m_indexBuffer;
		ID3D11InputLayout* m_inputLayout;
		ID3D11Buffer* m_constantBuffer;
		ID3D11SamplerState* m_sampler;
	};
}

#endif // !DIRECTX_TEXTURE_H
