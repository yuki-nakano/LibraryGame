#include "ActionChase.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	ActionState ActionChase::Exec(EnemyBase* enemy_base_)
	{
		engine::Vec3f enemyPos{ enemy_base_->GetPos() };
		engine::Vec3f targetPos{ enemy_base_->GetTargetPos() };

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
