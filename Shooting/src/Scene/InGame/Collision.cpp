#include "Collision.h"

#include "CollisionCalculation.h"

namespace Game
{
	Collision::Collision(Player* player_, BulletManager* bullet_manager_, EnemyManager* enemy_manager_)
		: m_player(player_)
		, m_bulletManager(bullet_manager_)
		, m_enemyManager(enemy_manager_)
	{
	}

	void Collision::Collide()
	{
		CollidePlayerAndBullet();
		CollidePlayerAndEnemy();
		CollideBulletAndEnemy();
	}

	void Collision::CollidePlayerAndBullet()
	{
		for (auto bullet : m_bulletManager->GetBulletList())
		{
			BulletState bulletState = bullet->GetBulletState();

			if (bulletState.m_bulletType == BulletType::Player) { continue; }

			if (CollideSphereAndSphere(
				m_player->GetPos(), m_player->GetObjState().hitRadius,
				bullet->GetPos(), bullet->GetObjState().hitRadius))
			{
				m_player->Hit(bullet);
				bullet->Hit(m_player);
			}
		}
	}

	void Collision::CollidePlayerAndEnemy()
	{
		m_enemyManager->Collide(m_player);
	}

	void Collision::CollideBulletAndEnemy()
	{
		for (auto bullet : m_bulletManager->GetBulletList())
		{
			BulletState bulletState = bullet->GetBulletState();

			if (bulletState.m_bulletType == BulletType::Enemy) { continue; }

			m_enemyManager->Collide(bullet);
		}
	}
}