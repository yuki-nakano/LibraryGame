#ifndef ENEMY_FACTORY_H
#define ENEMY_FACTORY_H

#include "../Scene/InGame/ObjBase.h"
#include "EnemyBase.h"

#include <vector>

namespace Game
{
	struct EnemyFactoryState
	{
		EnemyType enemyType{};
		int maxNum{};
		int hp{};
	};

	class EnemyFactory : public ObjBase
	{
	public:
		EnemyFactory(EnemyFactoryState enemy_factory_state_);
		~EnemyFactory() = default;

	public:
		void Update();

		void Draw();

		void CreateEnemy();

		ObjBase* Collide(ObjBase* obj_base_);

		void Hit(ObjBase* obj_base_);

		EnemyFactoryState GetFactoryState() { return m_enemyFactoryState; }

	private:
		EnemyFactoryState m_enemyFactoryState{};

		std::vector<EnemyBase*> m_enemyList{};

		int m_summonTimer{ 0 };

		int m_summmonTime{ 300 };
	};
}

#endif // !ENEMY_FACTORY_H
