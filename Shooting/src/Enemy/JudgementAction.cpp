#include "JudgementAction.h"

#include "EnemyBase.h"

namespace Game
{
	bool JudgeDead(EnemyBase* enemy_base_)
	{
		if (enemy_base_->GetObjState().hp <= 0)
		{
			return true;
		}

		return false;
	}
}