#ifndef EXEC_JUDGMENT_BASE_H
#define EXEC_JUDGMENT_BASE_H

namespace Game
{
	class EnemyBase;

	/**
	* @brief ノードを実行するかの判定クラス
	*/
	class ExecJudgmentBase
	{
	public:
		ExecJudgmentBase() = default;
		virtual ~ExecJudgmentBase() = default;

		/**
		* @brief ノードを実行するかの判定関数
		* @param enemy_ 行動するエネミー情報
		*/
		virtual bool Judgment(EnemyBase* enemy_) = 0;
	};
}

#endif // !EXEC_JUDGMENT_BASE_H
