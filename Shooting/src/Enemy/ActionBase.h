#ifndef ACTION_BASE_H
#define ACTION_BASE_H

namespace Game
{
	class EnemyBase;

	enum class ActionState
	{
		Run,		// 実行中
		Success,	// 行動成功
		Failed,		// 行動失敗
	};

	class ActionBase
	{
	public:
		ActionBase() = default;
		~ActionBase() = default;

	public:
		// 行動実行関数
		virtual ActionState Exec(EnemyBase*) = 0;
	};
}

#endif // !ACTION_BASE_H
