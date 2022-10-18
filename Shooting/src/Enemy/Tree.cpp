#include "Tree.h"

#include "EnemyBase.h"

namespace Game
{
	Tree::Tree(Node* node_)
		:m_root(node_)
	{
	}

	bool Tree::AddNode(const std::string& search_name_, Node* add_node_)
	{
		Node* result = m_root->Search(search_name_);
		if (result != nullptr)
		{
			result->AddChild(add_node_);
			return true;
		}

		return false;
	}

	Node* Tree::Inference(EnemyBase* enemy_)
	{
		return m_root->Inference(enemy_);
	}

	Node* Tree::Update(EnemyBase* enemy_, Node* active_node_)
	{
		ActionState result = active_node_->Update(enemy_);

		if (result != ActionState::Run)
		{
			//行動終了
			return nullptr;
		}

		//行動中
		return active_node_;
	}

	void Tree::Delete()
	{
		m_root->Delete();
		m_root = nullptr;
	}
}
