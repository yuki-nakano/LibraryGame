#include "EnemyManager.h"

#include "../Random.h"

namespace Game
{
	EnemyManager::EnemyManager(Stage* stage_, BulletManager* bullet_manager_)
		:m_stage(stage_)
		, m_bullet(bullet_manager_)
	{
		engine::Library::LoadObj("res/enemy/Alien.obj", "alien");
		engine::Library::LoadObj("res/enemy/Star.obj", "star");

		EnemyFactoryState enemyFactoryState
		{
			EnemyType::normal,
			3,
			3
		};

		EnemyFactory* enemyFactory = new EnemyFactory(m_bullet, enemyFactoryState);

		enemyFactory->SetPos(engine::Vec3f(m_stage->GetStageData().stageFront / 2,
			10,
			m_stage->GetStageData().stageLeft / 2));

		m_enemyList.push_back(enemyFactory);
	}

	EnemyManager::~EnemyManager()
	{
		engine::Library::ReleseObj("alien");
		engine::Library::ReleseObj("star");

		for (auto itr = m_enemyList.begin(); itr != m_enemyList.end();)
		{
			delete* itr;
			itr = m_enemyList.erase(itr);
		}
	}

	void EnemyManager::Update()
	{
		for (auto itr = m_enemyList.begin(); itr != m_enemyList.end();)
		{
			EnemyFactory* enemyFactory = *itr;

			enemyFactory->Update();

			if (enemyFactory->GetFactoryState().hp <= 0)
			{
				m_deadEnemyNum += enemyFactory->GetFactoryState().maxNum;

				delete enemyFactory;
				itr = m_enemyList.erase(itr);
			}
			else
			{
				itr++;
			}
		}

		if (m_enemyList.size() <= m_maxEnemyNum)
		{
			m_summonTimer--;
			if (m_summonTimer < 0)
			{
				CreateEnemy();

				m_summonTimer = m_summmonTime;
			}
		}
	}

	void EnemyManager::Draw()
	{
		for (auto enemyFactory : m_enemyList)
		{
			enemyFactory->Draw();
		}
	}

	void EnemyManager::CreateEnemy()
	{
		EnemyFactoryState enemyFactoryState
		{
			EnemyType::normal,
			3,
			3
		};

		EnemyFactory* enemyFactory = new EnemyFactory(m_bullet, enemyFactoryState);

		enemyFactory->SetPos(engine::Vec3f(
			RandomNum(m_stage->GetStageData().stageBack, m_stage->GetStageData().stageFront),
			RandomNum(m_stage->GetStageData().stageDown, m_stage->GetStageData().stageUp),
			RandomNum(m_stage->GetStageData().stageRight, m_stage->GetStageData().stageLeft)
		));

		m_enemyList.push_back(enemyFactory);
	}

	ObjBase* EnemyManager::Collide(ObjBase* obj_base_)
	{
		ObjBase* result{ nullptr };

		for (auto factory : m_enemyList)
		{
			result = factory->Collide(obj_base_);
		}

		return result;
	}

	int EnemyManager::GetDeadEnemyNum()
	{
		int enemyNum{ m_deadEnemyNum };

		for (auto enemyList : m_enemyList)
		{
			enemyNum += enemyList->GetFactoryState().maxNum - enemyList->GetFactoryState().hp;
		}

		return enemyNum;
	}
}