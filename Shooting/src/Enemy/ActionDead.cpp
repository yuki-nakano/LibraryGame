#include "ActionDead.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	ActionState ActionDead::Exec(EnemyBase* enemy_base_)
	{
		enemy_base_->SubDeadTimer();

		if (enemy_base_->GetDeadTimer() <= 0)
		{
			enemy_base_->ChangeAlive();
		}

		engine::Vec3f rote = enemy_base_->GetRote();
		engine::Vec3f scale = enemy_base_->GetScale();
		scale *= engine::Vec3f(0.95f, 0.95f, 0.95f);
		rote += engine::Vec3f(0.0f, 6.0f, 0.0f);

		enemy_base_->SetScale(scale);
		enemy_base_->SetRote(rote);

		return ActionState::Run;
	}
}