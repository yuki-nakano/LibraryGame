#include "EnemySpawner.h"

#include "../Library/Library.h"
#include "EnemyBase.h"
#include "NormalEnemy.h"
#include "../Scene/InGame/CollisionCalculation.h"

namespace Game
{
	EnemySpawner::EnemySpawner(BulletManager* bullet_manager_, EnemySpawnerState enemy_spawner_state_, const engine::Vec3f& pos_)
		: m_bulletManager(bullet_manager_)
		, m_enemySpawnerState(enemy_spawner_state_)
		, m_pos(pos_)
	{
	}

	EnemySpawner::~EnemySpawner()
	{
		for (auto itr = m_enemyList.begin(); itr != m_enemyList.end();)
		{
			delete* itr;
			itr = m_enemyList.erase(itr);
		}
	}

	void EnemySpawner::Update()
	{
		for (auto itr = m_enemyList.begin(); itr != m_enemyList.end();)
		{
			EnemyBase* enemyBase = *itr;

			if (!enemyBase->GetAlive())
			{
				delete enemyBase;
				itr = m_enemyList.erase(itr);

				m_enemySpawnerState.hp--;

				continue;
			}
			else
			{
				itr++;
			}

			enemyBase->Update();
		}

		if (m_enemyList.size() < m_enemySpawnerState.maxNum)
		{
			m_summonTimer--;
			if (m_summonTimer < 0)
			{
				CreateEnemy();

				m_summonTimer = m_summonTime;
			}
		}
	}

	void EnemySpawner::Draw()
	{
		for (auto enemy : m_enemyList)
		{
			enemy->Draw();
		}
	}

	void EnemySpawner::CreateEnemy()
	{
		EnemyBase* enemyBase{};
		switch (m_enemySpawnerState.enemyType)
		{
		case EnemyType::normal:
			enemyBase = new NormalEnemy(m_bulletManager);
			break;
		default:
			break;
		}

		engine::Vec3f pos(m_pos);
		enemyBase->SetPos(pos);
		enemyBase->SetSpawnerPos(m_pos);

		m_enemyList.push_back(enemyBase);
	}

	void EnemySpawner::Collide(ObjBase* obj_base_)
	{
		for (auto enemy : m_enemyList)
		{
			if (CollideSphereAndSphere(
				enemy->GetPos(), enemy->GetObjState().hitRadius,
				obj_base_->GetPos(), obj_base_->GetObjState().hitRadius))
			{
				obj_base_->Hit(enemy);
				enemy->Hit(obj_base_);
			}
		}
	}

	bool EnemySpawner::IsDead()
	{
		return (m_enemySpawnerState.hp <= 0);
	}
}