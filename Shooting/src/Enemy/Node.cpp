#include "Node.h"

#include "EnemyBase.h"

namespace Game
{
	Node::Node(std::string name_, SelectRule rule_, unsigned int priority_, ActionBase* action_, Node* parent_, ExecJudgmentBase* execute_)
		:name(name_)
		, parent(parent_)
		, Execute(execute_)
		, Rule(rule_)
		, Action(action_)
		, Priority(priority_)
	{
	}

	Node* Node::Search(std::string search_name_)
	{
		if (name == search_name_)
		{
			return this;
		}

		for (auto itr = children.begin(); itr != children.end(); itr++)
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
			children.push_back(child_);
		}
	}

	void Node::Delete()
	{
		for (auto itr = children.begin(); itr != children.end(); itr++)
		{
			((Node*)(*itr))->Delete();
		}

		delete this;
	}

	Node* Node::Inference(EnemyBase* enemy_)
	{
		std::vector<Node*> list;

		for (int i = 0; i < children.size(); i++)
		{
			bool canPushBuck = true;
			if (children[i]->Execute != nullptr)
			{
				canPushBuck = children[i]->Execute->Judgment(enemy_);
			}

			if (canPushBuck)
			{
				list.push_back(children[i]);
			}
		}

		Node* selectNode = nullptr;

		switch (Rule)
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
			if (selectNode->children.size() > 0)
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
		unsigned int priority = list_[0]->Priority;

		for (auto itr = list_.begin(); itr != list_.end(); itr++)
		{
			if ((*itr)->Execute != nullptr)
			{
				if (!(*itr)->Execute->Judgment(enemy_))
				{
					continue;
				}
			}

			if (priority > (*itr)->Priority)
			{
				priority = (*itr)->Priority;
				select_node = (*itr);
			}
		}

		return select_node;
	}

	ActionState Node::Update(EnemyBase* enemy_)
	{
		if (Action != nullptr)
		{
			return Action->Exec(enemy_);
		}

		return ActionState::Failed;
	}
}
