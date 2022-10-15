#include "EnemyManager.h"

#include "../Random.h"

namespace Game
{
	EnemyManager::EnemyManager(Stage* stage_)
		:m_stage(stage_)
	{
		EnemyFactoryState enemyFactoryState
		{
			EnemyType::normal,
			3,
			3
		};

		EnemyFactory* enemyFactory = new EnemyFactory(enemyFactoryState);

		enemyFactory->SetPos(engine::Vec3f(m_stage->GetStageData().stageFront / 2,
			10,
			m_stage->GetStageData().stageLeft / 2));

		m_enemyList.push_back(enemyFactory);
	}

	void EnemyManager::Update()
	{
		for (auto itr = m_enemyList.begin(); itr != m_enemyList.end();)
		{
			EnemyFactory* enemyFactory = *itr;

			enemyFactory->Update();

			if (enemyFactory->GetFactoryState().hp <= 0)
			{
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

		EnemyFactory* enemyFactory = new EnemyFactory(enemyFactoryState);

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
}