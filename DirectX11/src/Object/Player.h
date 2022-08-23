#ifndef PLAYER_H
#define PLAYER_H

#include "ObjBase.h"
#include "../Library/Library.h"
#include "../Scene/InGame/Stage.h"

namespace Game
{
	class Player : public ObjctBase
	{
	public:
		Player();
		~Player();

	public:
		void Update();

		void Draw();

		float GetEnergyPer() { return m_energy / m_maxEnegy; }

	private:
		void Move();

		void MoveReturn();

	private:
		/// ˆÚ“®—Ê
		engine::Vec3f m_moveVec{};

		float m_moveSpeed{ 0.0f };
		float m_acceleration{ 0.1f };
		float m_deceleration{ -0.03f };
		float m_maxSpeed{ 5.0f };
		float m_roteSpeed{ 1.0f };
		float m_maxRote{ 20.0f };

		float m_energy{ 1000 };
		float m_decreaseEnegy{ 1 };
		float m_maxEnegy{ 1000 };
	};
}

#endif // !PLAYER_H
