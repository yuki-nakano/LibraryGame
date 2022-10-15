#ifndef ACTION_CHASE_H
#define ACTION_CHASE_H

#include "../Library/Library.h"
#include "NodeBase.h"
#include "EnemyBase.h"

namespace Game
{
	class ActionChase : public NodeBase
	{
	public:
		ActionChase() = default;
		~ActionChase() = default;

	public:
		ActionState Exec(EnemyBase* enemy_base_);
	};
}

#endif // !ACTION_CHASE_H
