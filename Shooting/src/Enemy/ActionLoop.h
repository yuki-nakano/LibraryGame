#ifndef ACTION_LOOP_H
#define ACTION_LOOP_H

#include "ActionBase.h"
#include "EnemyBase.h"

namespace Game
{
	class ActionLoop : public ActionBase
	{
	public:
		ActionLoop() = default;
		~ActionLoop() = default;

	public:
		ActionState Exec(EnemyBase* enemy_base_);
	};
}

#endif // !ACTION_LOOP_H
