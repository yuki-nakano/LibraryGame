#include "Player.h"

#include "../../Library/Library.h"
#include "Stage.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	Player::Player(Stage* stage_, BulletManager* bullet_manager_)
		:m_stage(stage_)
		, m_bullet(bullet_manager_)
	{
		engine::Library::LoadObj("res/Obj/hikouki.obj", "Player");
		m_rote.y += 90.0f;
		m_pos.x =
			m_pos.z = 400.0f;
		m_moveSpeed = m_nomalSpeed;
		ObjState objState{ 1000, 0, 5.0f };
		SetState(objState);
	}

	Player::~Player()
	{
		engine::Library::DeleteObj("Player");
	}

	void Player::Update()
	{
		Move();

		MoveReturn();

		if (engine::Library::IsHeldKey(KEY_LMOUSE) && m_bulletCoolTimer <= 0)
		{
			ObjState objState{ 1, 5, 5.0f };
			m_bullet->CreateBullet(m_bulletState, objState, m_pos, m_rote, engine::Vec3f(10.0f, 10.0f, 10.0f));

			m_bulletCoolTimer = m_bulletState.m_coolTime;
		}

		m_bulletCoolTimer--;
	}

	void Player::Draw()
	{
		//engine::Library::RenderObj("Player", m_pos, m_rote, m_scale);

		//engine::Vec3f pos = m_pos;
		//engine::Library::RenderObj("Player", pos += engine::Vec3f(0.0f, 0.0f, 100.0f), m_rote, engine::Vec3f(1.0f, 1.0f, 1.0f));

	}

	void Player::Hit(ObjBase* obj_base_)
	{
		m_objState.hp -= obj_base_->GetState().damage;
	}

	void Player::Move()
	{
		// 視点移動
		m_rote.y += (engine::Library::GetMousePosX() - GetSystemMetrics(SM_CXSCREEN) / 2) * 0.1f;
		m_rote.x += (engine::Library::GetMousePosY() - GetSystemMetrics(SM_CYSCREEN) / 2) * 0.1f;
		if (m_rote.x > m_maxRote)
		{
			m_rote.x = m_maxRote;
		}
		else if (m_rote.x < -m_maxRote)
		{
			m_rote.x = -m_maxRote;
		}

		// 左移動
		if (engine::Library::IsHeldKey(KEY_A))
		{
			m_moveVec.x += sinf((m_rote.y - 90.0f) / 180.0f * M_PI) * m_nomalSpeed / 2;
			m_moveVec.z += cosf((m_rote.y - 90.0f) / 180.0f * M_PI) * m_nomalSpeed / 2;
		}

		// 右移動
		if (engine::Library::IsHeldKey(KEY_D))
		{
			m_moveVec.x += sinf((m_rote.y + 90.0f) / 180.0f * M_PI) * m_nomalSpeed / 2;
			m_moveVec.z += cosf((m_rote.y + 90.0f) / 180.0f * M_PI) * m_nomalSpeed / 2;
		}

		// 前進
		if (engine::Library::IsHeldKey(KEY_W))
		{
			m_moveVec.x += sinf(m_rote.y / 180.0f * M_PI) * m_moveSpeed;
			m_moveVec.z += cosf(m_rote.y / 180.0f * M_PI) * m_moveSpeed;
		}

		// 後退
		if (engine::Library::IsHeldKey(KEY_S))
		{
			m_moveVec.x -= sinf(m_rote.y / 180.0f * M_PI) * m_nomalSpeed / 3;
			m_moveVec.z -= cosf(m_rote.y / 180.0f * M_PI) * m_nomalSpeed / 3;
		}

		// 加速
		if (engine::Library::IsHeldKey(KEY_SHIFT))
		{
			m_moveSpeed += m_acceleration;
			if (m_moveSpeed > m_maxSpeed) { m_moveSpeed = m_maxSpeed; }
		}
		else
		{
			m_moveSpeed += m_deceleration;
			if (m_moveSpeed < m_nomalSpeed) { m_moveSpeed = m_nomalSpeed; }
		}

		// ジャンプ
		if (engine::Library::IsHeldKey(KEY_SPACE) && m_canJump)
		{
			m_jump = m_jumpPower;
			m_canJump = false;
		}

		if (!m_canJump)
		{
			m_jump -= m_gravity;
			m_moveVec.y = m_jump;
		}


		m_pos.x += m_moveVec.x;
		m_pos.y += m_moveVec.y;
		m_pos.z += m_moveVec.z;

		if (m_pos.y < 0)
		{
			m_pos.y = 0.0f;
			m_canJump = true;
		}

		m_moveVec = { 0, 0, 0 };
	}

	void Player::MoveReturn()
	{
		Stage::StageSize stageSize = m_stage->GetStageData();

		if (m_pos.z < stageSize.stageRight) { m_pos.z = stageSize.stageRight; }
		if (m_pos.z > stageSize.stageLeft) { m_pos.z = stageSize.stageLeft; }

		if (m_pos.x < stageSize.stageBack) { m_pos.x = stageSize.stageBack; }
		if (m_pos.x > stageSize.stageFront) { m_pos.x = stageSize.stageFront; }

		if (m_pos.y < stageSize.stageDown) { m_pos.y = stageSize.stageDown; }
		if (m_pos.y > stageSize.stageUp) { m_pos.y = stageSize.stageUp; }

	}
}