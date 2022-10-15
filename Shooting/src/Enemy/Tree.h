#ifndef TREE_H
#define TREE_H

#include "Node.h"

namespace Game
{
	class EnemyBase;

	class Tree
	{
	public:
		Tree(Node* node_);
		~Tree() = default;

		// ノード追加
		bool AddNode(std::string search_name_, Node* add_node_);

		// 行動決定
		Node* Inference(EnemyBase* enemy_);

		// 行動更新
		Node* Update(EnemyBase* enemy_, Node* active_node_);

	private:
		// ノードの削除
		void Delete();

	private:
		// ルートの削除
		Node* root;

	};
}

#endif // !TREE_H
