#ifndef ENEMY_BASE_H
#define ENEMY_BASE_H

#include "../Scene/InGame/ObjBase.h"
#include "../Library/Library.h"
#include "Tree.h"

namespace Game
{
	enum class EnemyType
	{
		normal,
	};

	// エネミーの継承元
	class EnemyBase : public ObjBase
	{
	public:
		EnemyBase() = default;
		~EnemyBase() = default;

	public:
		// 更新
		virtual void Update() = 0;

		// 描画
		virtual void Draw() = 0;

		// 接触時に呼び出す
		void Hit(ObjBase* obj_base_)
		{
			m_objState.hp -= obj_base_->GetState().damage;
		}

		void SubDeadTimer() { m_deadTimer--; }
		void SubInvicibleTimer() { m_invincibleTime--; }

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

	protected:
		// ビヘービア用ツリー
		Tree* m_tree{};

		engine::Vec3f m_col{ 0.0f, 0.0f, 0.0f };			// 通常時の色
		engine::Vec3f m_invincibleCol{ 1.0f, 0.0f, 0.0f };	// 無敵時の色

		engine::Vec3f m_factoryPos{};	// 生成元の座標
		engine::Vec3f m_targetPos{};	// 追跡対象の座標

		float m_distance{ 300.0f };		//生成元との距離

		float m_fov{ 45.0f };		// 視野角
		float m_far{ 300.0f };		// 視野の半径
		float m_loopTime{ 180 };	// 生成元を一周するまでの時間

		bool m_isAlive{ true };		// 生存フラグ

		int m_deadTime{ 120 };		// 死亡時間
		int m_deadTimer{ 120 };		// 死亡時間までのカウント

		int m_invincibleTime{ 60 };	// 無敵時間
		int m_invincibleTimer{ 0 };	// 無敵時間のカウント
	};
}

#endif // !ENEMY_BASE_H
