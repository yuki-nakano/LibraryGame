#include "JudgmentDead.h"

#include "EnemyBase.h"

namespace Game
{
	bool JudgmentDead::Judgment(EnemyBase* enemy_)
	{
		if (enemy_->GetState().hp <= 0)
		{
			return true;
		}

		return false;
	}
}