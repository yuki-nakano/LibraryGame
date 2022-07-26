﻿#ifndef PLAYER_H
#define PLAYER_H

#include "ObjBase.h"
#include "../../Library/Library.h"
#include "Stage.h"
#include "BulletManager.h"

class Stage;

namespace Game
{
	/**
	* @brief プレイヤー
	*/
	class Player : public ObjBase
	{
	public:
		Player(Stage* stage_, BulletManager* bullet_manager_);
		~Player() = default;

	public:
		/**
		* @brief 更新関数
		*/
		void Update() override;

		/**
		* @brief 接触時に呼び出す関数
		*/
		void Hit(ObjBase* obj_base_) override;

		/**
		* @brief プレイヤーの死亡判定
		* @return プレイヤーの体力が0以下になるとtrue
		*/
		bool IsDead();

		// アクセサ

		float GetSpeed() { return m_moveSpeed / m_maxSpeed; }
		float GetEyeRoteXZ() { return m_eyeRoteXZ; }
		float GetEyeRoteY() { return m_eyeRoteY; }
		float GetHeight() { return m_height; }

	private:
		/**
		* @brief 移動処理
		*/
		void Move();

		/**
		* @brief 移動量の計算
		* @param [in] key_ 押されたキー
		* @param [in] rote_ 移動する向き
		* @param [in] scale_ 移動量
		* @param [out] move_vec_ 移動量の保存
		*/
		void CalculateMoveVec(const int& key_, const float& rote_, const float& scale_, engine::Vec3f& move_vec_);

		/**
		* @brief ステージに合わせて移動
		*/
		void ReturnToStage();

	private:
		Stage* m_stage{};			/// ステージ
		BulletManager* m_bulletManager{};	/// 弾

		float m_moveSpeed{ 0.0f };	/// 速度
		float m_jump{};				/// ジャンプの移動量
		bool m_canJump{ true };		/// ジャンプ可能か

		float m_acceleration{ 0.1f };	/// 加速力
		float m_deceleration{ -0.03f };	/// 減速力
		float m_nomalSpeed{ 5.0f };		/// 基礎速度
		float m_maxSpeed{ 10.0f };		/// 最高速度
		float m_maxRote{ 20.0f };		/// 上下の最大角度

		float m_jumpPower{ 10.0f };		/// ジャンプ力
		float m_gravity{ 0.5f };		/// 重力

		float m_eyeRoteXZ{ 0.0f };		/// XZ平面の回転角度
		float m_eyeRoteY{ 0.0f };		/// Yの回転角度

		int m_bulletCoolTimer{ 0 };		/// 弾のクールタイマー
		int m_bulletCoolTime{ 10 };		/// 弾のクールタイム

		float m_height{ 100 };			/// プレイヤーの身長
	};
}

#endif // !PLAYER_H
