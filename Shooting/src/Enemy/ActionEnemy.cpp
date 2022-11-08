#include "ActionEnemy.h"

#include "EnemyBase.h"
#include "../Library/Library.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	ActionState ActionDead(EnemyBase* enemy_)
	{
		enemy_->SubDeadTimer();

		if (enemy_->GetDeadTimer() <= 0)
		{
			enemy_->ChangeAlive();
		}

		engine::Vec3f rote = enemy_->GetRote();
		engine::Vec3f scale = enemy_->GetScale();
		scale *= engine::Vec3f(0.95f, 0.95f, 0.95f);
		rote += engine::Vec3f(0.0f, 6.0f, 0.0f);

		enemy_->SetScale(scale);
		enemy_->SetRote(rote);

		return ActionState::Run;
	}

	ActionState ActionLoop(EnemyBase* enemy_)
	{
		if (enemy_->GetState().hp <= 0)
		{
			return ActionState::Success;
		}

		engine::Vec3f rote{ enemy_->GetRote() };
		engine::Vec3f pos{ enemy_->GetFactoryPos() };

		rote += engine::Vec3f(0.0f, 360.0f / enemy_->GetLoopTime(), 0.0f);

		float posx = sinf(rote.y / 180.0f * M_PI) * enemy_->GetDistance();
		float posz = cosf(rote.y / 180.0f * M_PI) * enemy_->GetDistance();

		enemy_->SetRote(rote);
		enemy_->SetPos(pos += engine::Vec3f(posx, 0, posz));

		enemy_->ShotBullet();

		return ActionState::Run;
	}

	ActionState ActionChase(EnemyBase* enemy_)
	{
		engine::Vec3f enemyPos{ enemy_->GetPos() };
		engine::Vec3f targetPos{ enemy_->GetTargetPos() };

		float distanceX{ targetPos.x - enemyPos.x };
		float distanceY{ targetPos.y - enemyPos.y };
		float distanceZ{ targetPos.z - enemyPos.z };
		float distanceXZ{ hypotf(distanceX, distanceZ) };

		float radianXZ = atan2f(distanceX, distanceZ) / M_PI * 180;
		if (radianXZ < 5 && radianXZ > -5)
		{

		}

		float radianY = atan2f(distanceY, distanceXZ) / M_PI * 180;

		return ActionState::Run;
	}
}