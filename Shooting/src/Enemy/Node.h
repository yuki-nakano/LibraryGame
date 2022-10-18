#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

#include "ExecJudgmentBase.h"
#include "ActionBase.h"

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
			Priority,	// 優先
			Random		// ランダム
		};

	public:
		/**
		* @brief コンストラクタ
		* @param name_ 登録するノード名前
		* @param rule_ ノード選択時のルール
		* @param priority_ 優先度
		* @param action_ 実行するクラス
		* @param parent_ 親ノードの名前
		* @param execute_ 実行判定クラス
		*/
		Node(const std::string& name_, const SelectRule& rule_, const unsigned int& priority_,
			ActionBase* action_ = nullptr, Node* parent_ = nullptr, ExecJudgmentBase* execute_ = nullptr);
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
		* @brief 親の設定
		* @param parent_ 親ノード
		*/
		void SetParent(Node* parent_) { m_parent = parent_; }

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
		std::string m_name;	/// 名前
		Node* m_parent;		/// 親
		std::vector<Node*> m_children;	/// 子供ノードのリスト
		ExecJudgmentBase* m_execute;	/// 実行可能かの判定関数
		SelectRule m_rule;				/// ノード選択のルール
		unsigned int m_priority;		/// 優先度

		ActionBase* m_action;	/// 実行関数
	};
}

#endif // !NODE_H
