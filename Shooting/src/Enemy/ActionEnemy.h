#ifndef ACTION_ENEMY_H
#define ACTION_ENEMY_H

namespace Game
{
	class EnemyBase;

	//モーションの状態
	enum class ActionState
	{
		Run,		/// 実行中
		Success,	/// 行動成功
		Failed,		/// 行動失敗
	};

	// 死亡演出
	ActionState ActionDead(EnemyBase* enemy_);

	// 旋回
	ActionState ActionLoop(EnemyBase* enemy_);

	// 追跡
	extern ActionState ActionChase(EnemyBase* enemy_);
}

#endif // !ACTION_ENEMY_H
