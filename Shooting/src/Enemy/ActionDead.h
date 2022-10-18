#ifndef ACTION_DEAD_H
#define ACTION_DEAD_H

#include "ActionBase.h"
#include "EnemyBase.h"

namespace Game
{
	/**
	* @brief 敵モーション 死亡演出
	*/
	class ActionDead : public ActionBase
	{
	public:
		ActionDead() = default;
		~ActionDead() = default;

	public:
		ActionState Exec(EnemyBase* enemy_base_);
	};
}

#endif // !ACTION_DEAD_H
