#ifndef NORMAL_ENEMY_H
#define NORMAL_ENEMY_H

#include "../Enemy/EnemyBase.h"
#include "Tree.h"
#include "../Library/Library.h"
#include "../Scene/InGame/BulletManager.h"

namespace Game
{
	/**
	* @brief 通常エネミー
	*/
	class NormalEnemy : public EnemyBase
	{
	public:
		NormalEnemy(BulletManager* bullet_manager_, Tree* ai_tree_);
		~NormalEnemy() = default;

		/**
		* @brief 更新関数
		*/
		void Update() override;

		/**
		* @brief 描画関数
		*/
		void Draw() override;

		/**
		* @brief 接触時に呼び出す関数
		*/
		void Hit(ObjBase* obj_base_);

	private:
		Node* m_activeNode{};	/// 実行ノード
	};
}

#endif // !NORMAL_ENEMY_H
