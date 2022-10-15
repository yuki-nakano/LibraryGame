#include "NormalEnemy.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include "ActionLoop.h"
#include "ActionDead.h"
#include "JudgmentDead.h"

namespace Game
{
	NormalEnemy::NormalEnemy(const engine::Vec3f& factory_pos_)
	{
		aiTree = new Tree(new Node("Root", Node::SelectRule::Priority, 0));
		aiTree->AddNode("Root", new Node("Loop", Node::SelectRule::None, 1, new ActionLoop));
		aiTree->AddNode("Root", new Node("Dead", Node::SelectRule::None, 0, new ActionDead, nullptr, new JudgmentDead));

		engine::Library::LoadObj("res/Obj/enemy/Alien.obj", "alien");

		m_scale = engine::Vec3f(100.0f, 100.0f, 100.0f);

		//m_objState = { 1, 5, 50.0f };
	}

	void NormalEnemy::Update()
	{
		if (activeNode == nullptr)
		{
			activeNode = aiTree->Inference(this);
		}

		if (activeNode != nullptr)
		{
			activeNode = aiTree->Update(this, activeNode);
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