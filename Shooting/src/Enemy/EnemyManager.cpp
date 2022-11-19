#include "EnemyManager.h"

#include "../Random.h"

#include <functional>

namespace Game
{
	EnemyManager::EnemyManager(Stage* stage_, BulletManager* bullet_manager_)
		:m_stage(stage_)
		, m_bulletManager(bullet_manager_)
	{
		// エネミーAI作成
		// NomalEnemy用
		Tree* AITree = new Tree(new Node("Root", Node::SelectRule::PrioritySelect, 0));
		AITree->AddNode("Root", new Node("Loop", Node::SelectRule::None, 1, std::bind(ActionLoop, std::placeholders::_1)));
		AITree->AddNode("Root", new Node("Dead", Node::SelectRule::None, 0, std::bind(ActionDead, std::placeholders::_1), std::bind(JudgeDead, std::placeholders::_1)));
		m_aiTree.emplace("nomal", AITree);

		engine::Library::LoadObj("res/enemy/Alien.obj", "alien");
		engine::Library::LoadObj("res/enemy/Star.obj", "star");

		EnemySpawnerState enemySpawnerState
		{
			EnemyType::normal,
			3,
			3
		};

		// ゲーム開始時に画面中央に一体生成
		EnemySpawner* enemySpawner = new EnemySpawner(m_bulletManager, m_aiTree.at("nomal"), enemySpawnerState,
			engine::Vec3f(m_stage->GetStageData().stageFront / 2, 100, m_stage->GetStageData().stageLeft / 2));

		m_enemyList.push_back(enemySpawner);
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

		for (auto itr = m_aiTree.begin(); itr != m_aiTree.end();)
		{
			delete itr->second;
			itr = m_aiTree.erase(itr);
		}
	}

	void EnemyManager::Update()
	{
		for (auto itr = m_enemyList.begin(); itr != m_enemyList.end();)
		{
			EnemySpawner* enemySpawner = *itr;

			if (enemySpawner->IsDead())
			{
				m_deadEnemyNum += enemySpawner->GetSpawnerState().maxNum;

				delete enemySpawner;
				itr = m_enemyList.erase(itr);
			}
			else
			{
				enemySpawner->Update();
				itr++;
			}
		}

		if (m_enemyList.size() <= m_maxEnemyNum)
		{
			m_summonTimer--;
			if (m_summonTimer < 0)
			{
				CreateEnemy();

				m_summonTimer = m_summonTime;
			}
		}
	}

	void EnemyManager::Draw()
	{
		for (auto enemySpawner : m_enemyList)
		{
			enemySpawner->Draw();
		}
	}

	void EnemyManager::CreateEnemy()
	{
		EnemySpawnerState enemySpawnerState
		{
			EnemyType::normal,
			3,
			3
		};

		// エネミーの種類が増えた場合分岐処理が必要
		Tree* aiTree = m_aiTree.at("nomal");

		// 画面内のランダムな位置に生成
		EnemySpawner* enemySpawner = new EnemySpawner(m_bulletManager, aiTree, enemySpawnerState
			, engine::Vec3f(
				RandomNum(m_stage->GetStageData().stageBack, m_stage->GetStageData().stageFront),
				RandomNum(m_stage->GetStageData().stageDown, m_stage->GetStageData().stageUp),
				RandomNum(m_stage->GetStageData().stageRight, m_stage->GetStageData().stageLeft)));

		m_enemyList.push_back(enemySpawner);
	}

	void EnemyManager::Collide(ObjBase* obj_base_)
	{
		for (auto Spawner : m_enemyList)
		{
			Spawner->Collide(obj_base_);
		}
	}

	int EnemyManager::GetDeadEnemyNum()
	{
		int enemyNum{ m_deadEnemyNum };

		for (auto enemyList : m_enemyList)
		{
			enemyNum += enemyList->GetSpawnerState().maxNum - enemyList->GetSpawnerState().hp;
		}

		return enemyNum;
	}
}