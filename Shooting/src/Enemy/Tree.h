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

		/**
		* @brief ノード追加
		* @param search_name_ 親ノードの名前
		* @param add_node_ 追加するノード情報
		*/
		bool AddNode(const std::string& search_name_, Node* add_node_);

		/**
		* @brief 行動決定
		* @param enemy_ エネミー情報
		*/
		Node* Inference(EnemyBase* enemy_);

		/**
		* @brief 行動更新
		* @param enemy_ エネミー情報
		* @param active_node_ 実行ノード
		*/
		Node* Update(EnemyBase* enemy_, Node* active_node_);

	private:
		/**
		* @brief ノードの削除
		*/
		void Delete();

	private:
		/// ルートノード
		Node* m_root;

	};
}

#endif // !TREE_H
