#ifndef PLAYER_H
#define PLAYER_H

#include "ObjBase.h"
#include "../../Library/Library.h"
#include "Stage.h"
#include "BulletManager.h"

class Stage;

namespace Game
{
	class Player : public ObjBase
	{
	public:
		Player(Stage* stage_, BulletManager* bullet_manager_);
		~Player();

	public:
		void Update();

		void Draw();

		void Hit(ObjBase* obj_base_);

		// アクセサ

		float GetEnergyPer() { return (m_objState.hp / 1000); }
		float GetSpeed() { return m_moveSpeed / m_maxSpeed; }
		float GetEyeRoteXZ() { return m_eyeRoteXZ; }
		float GetEyeRoteY() { return m_eyeRoteY; }

	private:
		/**
		* @brief 移動処理
		*/
		void Move();

		/**
		* @brief ステージに合わせて移動
		*/
		void MoveReturn();

	private:
		/// ステージ
		Stage* m_stage{};
		/// 弾
		BulletManager* m_bullet{};

		/// 移動量
		engine::Vec3f m_moveVec{};


		float m_moveSpeed{ 0.0f };	/// 速度
		float m_jump{};				/// ジャンプの移動量
		bool m_canJump{ true };		/// ジャンプ可能か

		BulletState m_bulletState{
			BulletType::Player,
			50.0f,
			300,
			10
		};

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
	};
}

#endif // !PLAYER_H
