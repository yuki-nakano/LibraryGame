#ifndef MATRIX_H
#define MATRIX_H

#include <DirectXMath.h>

#include "DirectXUtility.h"
#include "../Utility/Singleton.h"

namespace engine
{
	class Matrix : public Singleton<Matrix>
	{
	private:
		friend class Singleton<Matrix>;

		Matrix();
		~Matrix();

	public:
		/**
		* @breif ワールド座標変換行列の生成
		* @param pos_ 移動量
		* @param rote_ 角度
		* @param scale_ 大きさ
		* @retun ワールド座標変換行列
		*/
		DirectX::XMMATRIX CreateWorldMatrix(Vec3f pos_, Vec3f rote_, Vec3f scale_);

		/**
		* @breif ビュー座標変換行列の生成
		* @retun ビュー座標変換行列
		*/
		DirectX::XMMATRIX CreateViewMatrix();

		/**
		* @breif プロジェクション座標変換行列の生成
		* @retun プロジェクション座標変換行列
		*/
		DirectX::XMMATRIX CreateProjMatrix();

		DirectX::XMFLOAT4 GetViewportMatrix();

		void SetViewport(Vec2f viewport_) { viewport = viewport_; }

	private:
		Vec2f viewport;
	};
}

#endif // !MATRIX_H
