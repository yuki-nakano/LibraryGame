#include "NormalEnemy.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include "ActionEnemy.h"
#include "JudgementAction.h"

namespace Game
{
	NormalEnemy::NormalEnemy(BulletManager* bullet_manager_, Tree* ai_tree_)
		: EnemyBase(ai_tree_, engine::Vec3f(0.0f, 0.0f, 0.0f), engine::Vec3f(0.0f, 0.0f, 0.0f), engine::Vec3f(100.0f, 100.0f, 100.0f))
	{
		ObjState objState{ 10, 5, 50.0f };
		SetState(objState);

		m_bulletManager = bullet_manager_;
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

		engine::Vec3f col = (m_invincibleTimer > 0 ? m_invincibleCol : m_col);
		engine::Library::RenderObjSetColor("alien", pos += engine::Vec3f(0.0f, -50.0f, 0.0f), m_rote, m_scale, col);
	}

	void NormalEnemy::Hit(ObjBase* obj_base_)
	{
		if (m_invincibleTimer > 0) { return; }

		m_objState.hp -= obj_base_->GetObjState().damage;

		if (m_objState.hp <= 0)
		{
			m_deadTimer = m_deadTime;
		}

		if (m_invincibleTimer <= 0)
		{
			m_invincibleTimer = m_invincibleTime;
		}
	}
}