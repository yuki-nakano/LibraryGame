#ifndef NORMAL_ENEMY_H
#define NORMAL_ENEMY_H

#include "../Enemy/EnemyBase.h"
#include "ActionBase.h"
#include "Tree.h"
#include "../Library/Library.h"

namespace Game
{
	/**
	* @brief 通常エネミー
	*/
	class NormalEnemy : public EnemyBase
	{
	public:
		NormalEnemy(const engine::Vec3f& factory_pos_);
		~NormalEnemy() = default;

		void Update();

		void Draw();

		void Hit(ObjBase* obj_base_);

	private:
		Tree* m_aiTree;		/// ビヘービアツリー
		Node* m_activeNode;	/// 実行ノード
	};
}

#endif // !NORMAL_ENEMY_H
