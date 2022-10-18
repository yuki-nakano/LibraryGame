#ifndef ACTION_BASE_H
#define ACTION_BASE_H

namespace Game
{
	class EnemyBase;

	/// モーションの状態
	enum class ActionState
	{
		Run,		/// 実行中
		Success,	/// 行動成功
		Failed,		/// 行動失敗
	};

	/**
	* @brief モーションクラスの継承元
	*/
	class ActionBase
	{
	public:
		ActionBase() = default;
		virtual ~ActionBase() = default;

	public:
		/**
		* @brief 行動実行関数
		* @param EnemyBase
		*/
		virtual ActionState Exec(EnemyBase*) = 0;
	};
}

#endif // !ACTION_BASE_H
