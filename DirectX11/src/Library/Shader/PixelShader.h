#ifndef PIXEL_SHADER_H
#define PIXEL_SHADER_H

#include "ShaderBase.h"

namespace engine
{
	class PixelShader : public ShaderBase
	{
		using ShaderBase::ShaderBase;
	public:

		/**
		* @brief シェーダーの作成
		* @return 作成成功時にtrue
		*/
		bool CreateShader();

		/**
		* @brief シェーダの削除
		*/
		void DeleteShader();

		// アクセサ

		ID3D11PixelShader* GetPixelInterface() { return m_interfaace; }

	private:
		/// 作成されたシェーダー保存
		ID3D11PixelShader* m_interfaace;
	};
}

#endif // !PIXEL_SHADER_H
