#ifndef EXEC_JUDGMENT_BASE_H
#define EXEC_JUDGMENT_BASE_H

namespace Game
{
	class EnemyBase;

	class ExecJudgmentBase
	{
	public:
		virtual ~ExecJudgmentBase() {};

		virtual bool Judgment(EnemyBase* enemy) = 0;
	};
}

#endif // !EXEC_JUDGMENT_BASE_H
