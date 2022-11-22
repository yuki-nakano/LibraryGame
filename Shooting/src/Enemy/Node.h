#ifndef NODE_H
#define NODE_H

#include "ActionEnemy.h"
#include "JudgementAction.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <functional>

namespace Game
{
	class EnemyBase;

	/**
	* @brief ノード
	*/
	class Node
	{
	public:
		enum class SelectRule
		{
			None,		// 最後尾ノードのみ選択
			PrioritySelect,	// 優先
			RandomSelect		// ランダム
		};

	public:
		/**
		* @brief コンストラクタ
		* @param name_ 登録するノード名前
		* @param rule_ ノード選択時のルール
		* @param priority_ 優先度
		* @param action_ 実行する関数
		* @param judge_ 実行判定関数
		*/
		Node(const std::string& name_, const SelectRule& rule_, const unsigned int& priority_,
			std::function<ActionState(EnemyBase*)> action_ = nullptr,
			std::function<bool(EnemyBase*)> judge_ = nullptr);
		~Node() = default;

	public:
		/**
		* @brief ノードの検索
		* @param search_name_ 検索するノードの名前
		*/
		Node* Search(std::string search_name_);

		/**
		* @brief 子の追加
		* @parma child_ 子ノードの情報
		*/
		void AddChild(Node* child_);

		/**
		* @brief ノードの全削除
		*/
		void Delete();

		/**
		* @brief 行動決定
		* @param enemy_ エネミー情報
		*/
		Node* Inference(EnemyBase* enemy_);

		/**
		* @brief ランダムにノードを選択
		* @param list_ ノードリスト
		* @return 選択されたノード情報
		*/
		Node* SelectRandom(std::vector<Node*>& list_);

		/**
		* @brief 優先でノードを選択
		* @param list_ ノードリスト
		* @return 選択されたノード情報
		*/
		Node* SelectPriorty(std::vector<Node*>& list_, EnemyBase* enemy_);

		/**
		* @brief 更新
		* @param enemy_ エネミー情報
		*/
		ActionState Update(EnemyBase* enemy_);

	private:
		std::string m_name{};				/// 名前
		std::vector<Node*> m_children{};	/// 子供ノードのリスト
		SelectRule m_rule{};				/// ノード選択のルール
		unsigned int m_priority{};			/// 優先度

		std::function<ActionState(EnemyBase*)> m_Action;	/// 実行関数
		std::function<bool(EnemyBase*)> m_Judge;			/// 実行判定関数

	};
}

#endif // !NODE_H
