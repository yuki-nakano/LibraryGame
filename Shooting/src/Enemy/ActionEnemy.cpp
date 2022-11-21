#include "ActionEnemy.h"

#include "EnemyBase.h"
#include "../Library/Library.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	ActionState ActionDead(EnemyBase* enemy_)
	{
		enemy_->m_deadTimer--;

		if (enemy_->m_deadTimer <= 0)
		{
			enemy_->m_isAlive = false;
		}

		enemy_->m_scale *= engine::Vec3f(0.95f, 0.95f, 0.95f);
		enemy_->m_rote += engine::Vec3f(0.0f, 6.0f, 0.0f);

		return ActionState::Run;
	}

	ActionState ActionLoop(EnemyBase* enemy_)
	{
		if (enemy_->m_objState.hp <= 0)
		{
			return ActionState::Success;
		}

		enemy_->m_rote += engine::Vec3f(0.0f, 360.0f / enemy_->m_loopTime, 0.0f);

		enemy_->m_pos.x = enemy_->m_spawnerPos.x + sinf(enemy_->m_rote.y / 180.0f * M_PI) * enemy_->m_distance;
		enemy_->m_pos.z = enemy_->m_spawnerPos.z + cosf(enemy_->m_rote.y / 180.0f * M_PI) * enemy_->m_distance;

		enemy_->ShotBullet();

		return ActionState::Run;
	}

	ActionState ActionChase(EnemyBase* enemy_)
	{
		float distanceX{ enemy_->m_targetPos.x - enemy_->m_pos.x };
		float distanceY{ enemy_->m_targetPos.y - enemy_->m_pos.y };
		float distanceZ{ enemy_->m_targetPos.z - enemy_->m_pos.z };
		float distanceXZ{ hypotf(distanceX, distanceZ) };

		float radianXZ = atan2f(distanceX, distanceZ) / M_PI * 180;
		if (radianXZ < -5 || radianXZ > 5)
		{
			return ActionState::Success;
		}

		float radianY = atan2f(distanceY, distanceXZ) / M_PI * 180;
		if (radianY < -5 || radianY > 5)
		{
			return ActionState::Success;
		}

		return ActionState::Run;
	}
}