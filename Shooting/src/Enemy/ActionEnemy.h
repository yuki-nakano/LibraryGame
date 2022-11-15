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

	/**
	* @brief 死亡演出
	* @param enemy_ モーションを適応させるエネミー
	* @return モーションの状態
	*/
	ActionState ActionDead(EnemyBase* enemy_);

	/**
	* @brief 旋回
	* @param enemy_ モーションを適応させるエネミー
	* @return モーションの状態
	*/
	ActionState ActionLoop(EnemyBase* enemy_);

	/**
	* @brief 追跡
	* @param enemy_ モーションを適応させるエネミー
	* @return モーションの状態
	*/
	ActionState ActionChase(EnemyBase* enemy_);
}

#endif // !ACTION_ENEMY_H
