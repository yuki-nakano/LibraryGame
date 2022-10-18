#ifndef JUDGMENT_DEAD_H
#define JUDGMENT_DEAD_H

#include "ExecJudgmentBase.h"

namespace Game
{
	class EnemyBase;

	class JudgmentDead : public ExecJudgmentBase
	{
	public:
		JudgmentDead() = default;
		~JudgmentDead() = default;

		bool Judgment(EnemyBase* enemy_);
	};
}

#endif // !JUDGMENT_DEAD_H
