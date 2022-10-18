#include "Node.h"

#include "EnemyBase.h"

namespace Game
{
	Node::Node(const std::string& name_, const SelectRule& rule_, const unsigned int& priority_,
		ActionBase* action_, Node* parent_, ExecJudgmentBase* execute_)
		:m_name(name_)
		, m_parent(parent_)
		, m_execute(execute_)
		, m_rule(rule_)
		, m_action(action_)
		, m_priority(priority_)
	{
	}

	Node* Node::Search(std::string search_name_)
	{
		if (m_name == search_name_)
		{
			return this;
		}

		for (auto itr = m_children.begin(); itr != m_children.end(); itr++)
		{
			Node* result = ((Node*)(*itr))->Search(search_name_);
			if (result != nullptr)
			{
				return result;
			}
		}

		return nullptr;
	}

	void Node::AddChild(Node* child_)
	{
		if (child_ != nullptr)
		{
			child_->SetParent(this);
			m_children.push_back(child_);
		}
	}

	void Node::Delete()
	{
		for (auto itr = m_children.begin(); itr != m_children.end(); itr++)
		{
			((Node*)(*itr))->Delete();
		}

		delete this;
	}

	Node* Node::Inference(EnemyBase* enemy_)
	{
		std::vector<Node*> list;

		for (int i = 0; i < m_children.size(); i++)
		{
			bool canPushBuck = true;
			if (m_children[i]->m_execute != nullptr)
			{
				canPushBuck = m_children[i]->m_execute->Judgment(enemy_);
			}

			if (canPushBuck)
			{
				list.push_back(m_children[i]);
			}
		}

		Node* selectNode = nullptr;

		switch (m_rule)
		{
		case Node::SelectRule::None:
			break;
		case Node::SelectRule::Priority:
			selectNode = SelectPriorty(list, enemy_);
			break;
		case Node::SelectRule::Random:
			selectNode = SelectRandom(list);
			break;
		default:
			break;
		}

		if (selectNode != nullptr)
		{
			if (selectNode->m_children.size() > 0)
			{
				return selectNode->Inference(enemy_);
			}
		}

		return selectNode;
	}

	Node* Node::SelectRandom(std::vector<Node*>& list_)
	{
		if (list_.size() == 0) { return nullptr; }

		int num = rand() % list_.size();

		return list_[num];
	}

	Node* Node::SelectPriorty(std::vector<Node*>& list_, EnemyBase* enemy_)
	{
		Node* select_node = list_[0];
		unsigned int priority = list_[0]->m_priority;

		for (auto itr = list_.begin(); itr != list_.end(); itr++)
		{
			if ((*itr)->m_execute != nullptr)
			{
				if (!(*itr)->m_execute->Judgment(enemy_))
				{
					continue;
				}
			}

			if (priority > (*itr)->m_priority)
			{
				priority = (*itr)->m_priority;
				select_node = (*itr);
			}
		}

		return select_node;
	}

	ActionState Node::Update(EnemyBase* enemy_)
	{
		if (m_action != nullptr)
		{
			return m_action->Exec(enemy_);
		}

		return ActionState::Failed;
	}
}
