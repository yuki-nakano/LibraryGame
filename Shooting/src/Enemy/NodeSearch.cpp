#include "NodeSearch.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	bool NodeSearch::Exec(EnemyBase* enemy_base_)
	{
		float enemyFOV{ enemy_base_->GetFOV() };
		engine::Vec3f enemyRote{ enemy_base_->GetRote() };

		float distanceX{ enemy_base_->GetTargetPos().x - enemy_base_->GetPos().x };
		float distanceY{ enemy_base_->GetTargetPos().y - enemy_base_->GetPos().y };
		float distanceZ{ enemy_base_->GetTargetPos().z - enemy_base_->GetPos().z };

		double radianXZ{ atan2(distanceZ, distanceX) / M_PI * 180 };

		if (radianXZ >= enemyRote.y + enemyFOV / 2 && radianXZ >= enemyRote.y - enemyFOV / 2) { return false; }

		return true;
	}
}