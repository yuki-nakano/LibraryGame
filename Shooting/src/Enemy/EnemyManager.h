#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "EnemyFactory.h"
#include "../Scene/InGame/Stage.h"

#include <vector>

namespace Game
{
	class EnemyManager
	{
	public:
		EnemyManager(Stage* stage_);
		~EnemyManager() = default;

	public:
		void Update();

		void Draw();

		void CreateEnemy();

		ObjBase* Collide(ObjBase* obj_base_);

	private:
		std::vector<EnemyFactory*> m_enemyList{};
		Stage* m_stage{};

		int m_summonTimer{ 300 };

		int m_summmonTime{ 300 };
		int m_maxEnemyNum{ 1 };
	};
}

#endif // !ENEMY_MANAGER_H
