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

		float GetEnergyPer() { return m_objState.hp / m_maxHp; }
		float GetSpeed() { return m_moveSpeed / m_maxSpeed; }
		float GetEyeRoteXZ() { return m_eyeRoteXZ; }
		float GetEyeRoteY() { return m_eyeRoteY; }


	private:
		void Move();

		void MoveReturn();

	private:
		Stage* m_stage{};
		BulletManager* m_bullet{};

		// 移動量
		engine::Vec3f m_moveVec{};


		float m_moveSpeed{ 0.0f }; // 速度
		float m_jump{};
		bool m_canJump{ true };

		BulletState m_bulletState{
			BulletType::Player,
			50.0f,
			300,
			10
		};

		float m_acceleration{ 0.1f };	// 加速力
		float m_deceleration{ -0.03f };	// 減速力
		float m_nomalSpeed{ 5.0f };		// 基礎速度
		float m_maxSpeed{ 10.0f };		// 最高速度
		float m_maxRote{ 20.0f };		// 上下の最大角度

		float m_jumpPower{ 10.0f };
		float m_gravity{ 0.5f };

		float m_eyeRoteXZ{ 0.0f };
		float m_eyeRoteY{ 0.0f };

		int m_bulletCoolTimer{ 0 };

		float m_maxHp{ 1000 };
	};
}

#endif // !PLAYER_H
