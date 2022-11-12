#include "NormalEnemy.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include "ActionEnemy.h"
#include "JudgementAction.h"

namespace Game
{
	NormalEnemy::NormalEnemy(BulletManager* bullet_manager_)
		: EnemyBase(engine::Vec3f(0.0f, 0.0f, 0.0f), engine::Vec3f(0.0f, 0.0f, 0.0f), engine::Vec3f(100.0f, 100.0f, 100.0f))
	{
		m_aiTree = new Tree(new Node("Root", Node::SelectRule::PrioritySelect, 0));
		m_aiTree->AddNode("Root", new Node("Loop", Node::SelectRule::None, 1, ActionLoop));
		m_aiTree->AddNode("Root", new Node("Dead", Node::SelectRule::None, 0, ActionDead, JudgeDead));

		ObjState objState{ 10, 5, 50.0f };
		SetState(objState);

		m_bulletManager = bullet_manager_;
	}

	NormalEnemy::~NormalEnemy()
	{
		delete m_aiTree;
	}

	void NormalEnemy::Update()
	{
		if (m_activeNode == nullptr)
		{
			m_activeNode = m_aiTree->Inference(this);
		}

		if (m_activeNode != nullptr)
		{
			m_activeNode = m_aiTree->Update(this, m_activeNode);
		}

		if (m_invincibleTimer > 0)
		{
			m_invincibleTimer--;
		}
	}

	void NormalEnemy::Draw()
	{
		engine::Vec3f pos = m_pos;

		if (m_invincibleTimer > 0)
		{
			engine::Library::RenderObjSetColor("alien", pos += engine::Vec3f(0.0f, -50.0f, 0.0f), m_rote, m_scale, m_invincibleCol);
		}
		else
		{
			engine::Library::RenderObjSetColor("alien", pos += engine::Vec3f(0.0f, -50.0f, 0.0f), m_rote, m_scale, m_col);
		}
	}

	void NormalEnemy::Hit(ObjBase* obj_base_)
	{
		if (m_invincibleTimer > 0) { return; }

		m_objState.hp -= obj_base_->GetState().damage;

		if (m_invincibleTimer <= 0)
		{
			m_invincibleTimer = m_invincibleTime;
		}

		if (m_objState.hp <= 0)
		{
			m_deadTimer = m_deadTime;
		}
	}
}