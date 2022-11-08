#include "Bullet.h"

#include "../../Library/Library.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	Bullet::Bullet(const BulletState& bullet_state)
		: m_bulletState(bullet_state)
	{
	}

	void Bullet::Update()
	{
		float xzSpeed = cosf(m_rote.x / 180.0f * M_PI) * m_bulletState.m_speed;
		m_pos.x += sinf(m_rote.y / 180.0f * M_PI) * xzSpeed;
		m_pos.y += sinf(m_rote.x / 180.0f * M_PI * -1) * m_bulletState.m_speed;
		m_pos.z += cosf(m_rote.y / 180.0f * M_PI) * xzSpeed;

		m_bulletState.m_deleteTime--;
	}

	void Bullet::Draw()
	{
		engine::Library::RenderObj(m_bulletState.m_objName, m_pos, m_rote, m_scale);
	}

	void Bullet::Hit(ObjBase* obj_base_)
	{
		m_objState.hp -= obj_base_->GetState().damage;

		if (m_objState.hp <= 0)
		{
			m_bulletState.m_deleteTime = 0;
		}
	}
}