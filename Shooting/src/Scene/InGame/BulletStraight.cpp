#include "BulletStraight.h"

#include "../../Library/Library.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	BulletStraight::BulletStraight(const BulletState& bullet_state_, const engine::Vec3f& pos_, const engine::Vec3f& rote_, const engine::Vec3f& scale_)
		: BulletBase(bullet_state_, pos_, rote_, scale_)
	{
		float xzSpeed = cosf(m_rote.x / 180.0f * M_PI) * m_bulletState.m_speed;
		m_moveVec.x += sinf(m_rote.y / 180.0f * M_PI) * xzSpeed;
		m_moveVec.y += sinf(m_rote.x / 180.0f * M_PI * -1) * m_bulletState.m_speed;
		m_moveVec.z += cosf(m_rote.y / 180.0f * M_PI) * xzSpeed;
	}

	void BulletStraight::Update()
	{
		m_pos.x += m_moveVec.x;
		m_pos.y += m_moveVec.y;
		m_pos.z += m_moveVec.z;

		m_bulletState.m_deleteTime--;
	}

	void BulletStraight::Draw()
	{
		engine::Library::RenderObj(m_bulletState.m_objName, m_pos, m_rote, m_scale);
	}

	void BulletStraight::Hit(ObjBase* obj_base_)
	{
		m_objState.hp -= obj_base_->GetObjState().damage;

		if (m_objState.hp <= 0)
		{
			m_bulletState.m_deleteTime = 0;
		}
	}
}