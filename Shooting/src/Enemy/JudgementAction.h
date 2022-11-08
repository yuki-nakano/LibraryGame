#ifndef JUDGEMENT_ACTION_H
#define JUDGEMENT_ACTION_H

namespace Game
{
	class EnemyBase;

	/**
	* @brief ノードを実行するかの判定関数
	* @param enemy_ 行動するエネミー情報
	*/
	bool JudgeDead(EnemyBase* enemy_base_);
}

#endif // !JUDGEMENT_ACTION_H
