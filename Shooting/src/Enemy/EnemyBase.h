#ifndef ENEMY_BASE_H
#define ENEMY_BASE_H

#include "../Scene/InGame/ObjBase.h"
#include "../Library/Library.h"
#include "../Scene/InGame/BulletManager.h"
#include "../Random.h"
#include "Tree.h"

namespace Game
{
	enum class EnemyType
	{
		normal,
	};

	/**
	* @brief エネミーの継承元
	*/
	class EnemyBase : public ObjBase
	{
	public:
		EnemyBase(const engine::Vec3f& pos_, const engine::Vec3f& rote_, const engine::Vec3f& scale_)
			: ObjBase(pos_, rote_, scale_)
		{
		}

		virtual ~EnemyBase() = default;

	public:
		/**
		* @brief 他オブジェクトとの接触時に呼び出す
		* @param obj_base_ 接触したオブジェクト
		*/
		void Hit(ObjBase* obj_base_) override
		{
			m_objState.hp -= obj_base_->GetState().damage;
		}

		/**
		* @brief 弾の発射関数
		*/
		void ShotBullet()
		{
			if (m_bulletCoolTimer <= 0)
			{
				ObjState objState{ 1, 100, 20.0f };
				m_bulletManager->CreateBullet(m_bulletState, objState, m_pos, m_rote, engine::Vec3f(10.0f, 10.0f, 10.0f));

				m_bulletCoolTimer = RandomNum(m_bulletState.m_coolTime / 2, m_bulletState.m_coolTime);
			}

			m_bulletCoolTimer--;
		}

		// タイマー減少関数
		void SubDeadTimer() { m_deadTimer--; }

		// タイマー減少関数
		void SubInvicibleTimer() { m_invincibleTime--; }

		// 切り替え関数
		void ChangeAlive() { m_isAlive ? m_isAlive = false : m_isAlive = true; }


		// アクセサ

		engine::Vec3f GetFactoryPos() { return m_factoryPos; }
		engine::Vec3f GetTargetPos() { return m_targetPos; }
		float GetDistance() { return m_distance; }
		float GetFOV() { return m_fov; }
		float GetFar() { return m_far; }
		float GetLoopTime() { return m_loopTime; }
		float GetDeadTimer() { return m_deadTimer; }
		float GetInvicibleTimer() { return m_invincibleTimer; }
		bool GetAlive() { return m_isAlive; }

		void SetFactoryPos(const engine::Vec3f& factory_pos_) { m_factoryPos = factory_pos_; }
		void SetTargetPos(const engine::Vec3f& target_pos_) { m_targetPos = target_pos_; }
		void SetBulletState(const BulletState& bullet_state_) { m_bulletState = bullet_state_; }

	protected:
		/// 弾
		BulletManager* m_bulletManager{};

		engine::Vec3f m_col{};								/// 通常時の色
		engine::Vec3f m_invincibleCol{ 1.0f, 0.0f, 0.0f };	/// 無敵時の色

		engine::Vec3f m_factoryPos{};	/// 生成元の座標
		engine::Vec3f m_targetPos{};	/// 追跡対象の座標

		float m_distance{ 300.0f };		///生成元との距離

		float m_fov{ 45.0f };		/// 視野角
		float m_far{ 300.0f };		/// 視野の半径
		int m_loopTime{ 180 };	/// 生成元を一周するまでの時間

		bool m_isAlive{ true };		/// 生存フラグ

		int m_deadTime{ 120 };		/// 死亡時間
		int m_deadTimer{ 120 };		/// 死亡時間までのカウント

		int m_invincibleTime{ 60 };	/// 無敵時間
		int m_invincibleTimer{ 0 };	/// 無敵時間のカウント

		/// 弾のステータス
		BulletState m_bulletState{
		BulletType::Enemy,
		50.0f,
		300,
		120,
		"bullet"
		};

		int m_bulletCoolTimer{ 0 };		/// 弾のクールタイマー
	};
}

#endif // !ENEMY_BASE_H
