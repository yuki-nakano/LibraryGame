#include "JudgementAction.h"

#include "EnemyBase.h"

namespace Game
{
	bool JudgeDead(EnemyBase* enemy_base_)
	{
		if (enemy_base_->m_objState.hp <= 0)
		{
			return true;
		}

		return false;
	}
}