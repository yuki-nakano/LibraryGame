#include "Player.h"

#include "../Library/Library.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	Player::Player()
	{
		engine::Library::LoadObj("res/Obj/hikouki.obj", "Player");
		m_rote.y += 90.0f;
	}

	Player::~Player()
	{
		engine::Library::DeleteObj("Player");
	}

	void Player::Update()
	{
		Move();
	}

	void Player::Draw()
	{
		engine::Library::RenderObj("Player", m_pos, m_rote, m_scale);
	}

	void Player::Move()
	{

		// ¶ˆÚ“®
		if (engine::Library::IsHeldKey(KEY_A))
		{
			m_rote.y -= m_roteSpeed * m_moveSpeed / m_maxSpeed;

			//m_rote.z += m_roteSpeed;
			//if (m_rote.z > m_maxRote) { m_rote.z = m_maxRote; }
		}

		// ‰EˆÚ“®
		if (engine::Library::IsHeldKey(KEY_D))
		{
			m_rote.y += m_roteSpeed * m_moveSpeed / m_maxSpeed;

			//m_rote.z -= m_roteSpeed;
			//if (m_rote.z < m_maxRote * -1) { m_rote.z = m_maxRote * -1; }
		}

		// ã¸
		if (engine::Library::IsHeldKey(KEY_SPACE))
		{
			m_rote.x -= m_roteSpeed * m_moveSpeed / m_maxSpeed;
			if (m_rote.x < m_maxRote * -1) { m_rote.x = m_maxRote * -1; }
		}

		// ‰º~
		if (engine::Library::IsHeldKey(KEY_SHIFT))
		{
			m_rote.x += m_roteSpeed * m_moveSpeed / m_maxSpeed;
			if (m_rote.x > m_maxRote) { m_rote.x = m_maxRote; }
		}


		// ‘Oi
		if (engine::Library::IsHeldKey(KEY_W))
		{
			m_moveSpeed += m_acceleration;
			if (m_moveSpeed > m_maxSpeed) { m_moveSpeed = m_maxSpeed; }

			m_energy -= m_decreaseEnegy;
		}

		// Œã‘Þ
		if (engine::Library::IsHeldKey(KEY_S))
		{
			m_moveSpeed += m_deceleration;
			if (m_moveSpeed < 0) { m_moveSpeed = 0; }
		}


		float xzSpeed = cosf(m_rote.x / 180.0f * M_PI) * m_moveSpeed;
		m_moveVec.x = sinf(m_rote.y / 180.0f * M_PI) * xzSpeed;
		m_moveVec.y = sinf(m_rote.x / 180.0f * M_PI * -1) * m_moveSpeed;
		m_moveVec.z = cosf(m_rote.y / 180.0f * M_PI) * xzSpeed;

		m_pos.x += m_moveVec.x;
		m_pos.y += m_moveVec.y;
		m_pos.z += m_moveVec.z;

		m_moveVec = { 0, 0, 0 };
	}
	void Player::MoveReturn()
	{

	}
}