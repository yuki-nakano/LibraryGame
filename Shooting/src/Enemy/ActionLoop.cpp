#include "ActionLoop.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	ActionState ActionLoop::Exec(EnemyBase* enemy_base_)
	{
		if (enemy_base_->GetState().hp <= 0)
		{
			return ActionState::Success;
		}

		engine::Vec3f rote{ enemy_base_->GetRote() };
		engine::Vec3f pos{ enemy_base_->GetFactoryPos() };

		rote += engine::Vec3f(0.0f, 360.0f / enemy_base_->GetLoopTime(), 0.0f);

		float posx = sinf(rote.y / 180.0f * M_PI) * enemy_base_->GetDistance();
		float posz = cosf(rote.y / 180.0f * M_PI) * enemy_base_->GetDistance();

		enemy_base_->SetRote(rote);
		enemy_base_->SetPos(pos += engine::Vec3f(posx, 0, posz));

		return ActionState::Run;
	}
}