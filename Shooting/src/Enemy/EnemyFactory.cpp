﻿#include "EnemyFactory.h"

#include "../Library/Library.h"
#include "EnemyBase.h"
#include "NormalEnemy.h"
#include "../Scene/InGame/Collision.h"

namespace Game
{
	EnemyFactory::EnemyFactory(BulletManager* bullet_manager_, EnemyFactoryState enemy_factory_state_, const engine::Vec3f& pos_)
		: m_bulletManager(bullet_manager_)
		, m_enemyFactoryState(enemy_factory_state_)
		, m_pos(pos_)
	{
	}

	EnemyFactory::~EnemyFactory()
	{
		for (auto itr = m_enemyList.begin(); itr != m_enemyList.end();)
		{
			delete* itr;
			itr = m_enemyList.erase(itr);
		}
	}

	void EnemyFactory::Update()
	{
		for (auto itr = m_enemyList.begin(); itr != m_enemyList.end();)
		{
			EnemyBase* enemyBase = *itr;

			enemyBase->Update();

			if (!enemyBase->GetAlive())
			{
				delete enemyBase;
				itr = m_enemyList.erase(itr);

				m_enemyFactoryState.hp--;
			}
			else
			{
				itr++;
			}
		}

		if (m_enemyList.size() < m_enemyFactoryState.maxNum)
		{
			m_summonTimer--;
			if (m_summonTimer < 0)
			{
				CreateEnemy();

				m_summonTimer = m_summonTime;
			}
		}
	}

	void EnemyFactory::Draw()
	{
		for (auto enemy : m_enemyList)
		{
			enemy->Draw();
		}
	}

	void EnemyFactory::CreateEnemy()
	{
		EnemyBase* enemyBase{};
		switch (m_enemyFactoryState.enemyType)
		{
		case EnemyType::normal:
			enemyBase = new NormalEnemy(m_bulletManager);
			break;
		default:
			break;
		}

		engine::Vec3f pos(m_pos);
		enemyBase->SetPos(pos);
		enemyBase->SetFactoryPos(m_pos);

		m_enemyList.push_back(enemyBase);
	}

	ObjBase* EnemyFactory::Collide(ObjBase* obj_base_)
	{
		ObjBase* result{ nullptr };

		for (auto enemy : m_enemyList)
		{
			if (CollideSphereAndSphere(
				enemy->GetPos(), enemy->GetState().hitRadius,
				obj_base_->GetPos(), obj_base_->GetState().hitRadius))
			{
				obj_base_->Hit(enemy);
				enemy->Hit(obj_base_);
				result = enemy;
			}
		}

		return result;
	}
}