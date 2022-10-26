#include "EnemyFactory.h"

#include "../Library/Library.h"
#include "EnemyBase.h"
#include "NormalEnemy.h"
#include "../Scene/InGame/Collision.h"

namespace Game
{
	EnemyFactory::EnemyFactory(EnemyFactoryState enemy_factory_state_)
		:m_enemyFactoryState(enemy_factory_state_)
	{
		engine::Library::LoadObj("res/enemy/Star.obj", "star");
		m_rote.y += 90.0f;
		m_pos.z += 400.0f;
		m_scale = engine::Vec3f(10.0f, 10.0f, 10.0f);
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

				m_summonTimer = m_summmonTime;
			}
		}
	}

	void EnemyFactory::Draw()
	{
		engine::Library::RenderObj("star", m_pos, m_rote, m_scale);

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
			enemyBase = new NormalEnemy(m_pos);
			break;
		default:
			break;
		}

		engine::Vec3f pos(m_pos);
		enemyBase->SetPos(pos += engine::Vec3f(0.0f, 10.0f, 0.0f));
		enemyBase->SetFactoryPos(m_pos);
		ObjState objState{ 10, 10, 50.0f };
		enemyBase->SetState(objState);

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

	void EnemyFactory::Hit(ObjBase* obj_base_)
	{
	}
}