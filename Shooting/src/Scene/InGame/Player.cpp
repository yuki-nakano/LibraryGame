#include "Player.h"

#include "../../Library/Library.h"
#include "Stage.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	Player::Player(Stage* stage_, BulletManager* bullet_manager_)
		:m_stage(stage_)
		, m_bulletManager(bullet_manager_)
		, ObjBase(engine::Vec3f(400.0f, m_height, 400.0f), engine::Vec3f(0.0f, 90.0f, 0.0f), engine::Vec3f(1.0f, 1.0f, 1.0f))
	{
		m_moveSpeed = m_nomalSpeed;
		ObjState objState{ 1000, 0, 50.0f };
		SetState(objState);
	}

	void Player::Update()
	{
		Move();

		MoveReturn();

		if (engine::Library::IsHeldKey(KEY_LMOUSE) && m_bulletCoolTimer <= 0)
		{
			engine::Vec3f pos = m_pos;

			ObjState objState{ 1, 5, 15.0f };
			m_bulletManager->CreateBullet(m_bulletState, objState, pos += engine::Vec3f(0.0f, m_height / 2, 0.0f), m_rote, engine::Vec3f(10.0f, 10.0f, 10.0f));

			m_bulletCoolTimer = m_bulletState.m_coolTime;
		}

		m_bulletCoolTimer--;
	}

	void Player::Draw()
	{
		engine::Library::RenderObj("star", m_pos, m_rote, engine::Vec3f(1.0f, 1.0f, 1.0f));
	}

	void Player::Hit(ObjBase* obj_base_)
	{
		m_objState.hp -= obj_base_->GetState().damage;
	}

	bool Player::IsDead()
	{
		return (m_objState.hp < 0);
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

		// 移動量
		engine::Vec3f moveVec{};

		// 左移動
		if (engine::Library::IsHeldKey(KEY_A))
		{
			moveVec.x += sinf((m_rote.y - 90.0f) / 180.0f * M_PI) * m_nomalSpeed / 2;
			moveVec.z += cosf((m_rote.y - 90.0f) / 180.0f * M_PI) * m_nomalSpeed / 2;
		}

		// 右移動
		if (engine::Library::IsHeldKey(KEY_D))
		{
			moveVec.x += sinf((m_rote.y + 90.0f) / 180.0f * M_PI) * m_nomalSpeed / 2;
			moveVec.z += cosf((m_rote.y + 90.0f) / 180.0f * M_PI) * m_nomalSpeed / 2;
		}

		// 前進
		if (engine::Library::IsHeldKey(KEY_W))
		{
			moveVec.x += sinf(m_rote.y / 180.0f * M_PI) * m_moveSpeed;
			moveVec.z += cosf(m_rote.y / 180.0f * M_PI) * m_moveSpeed;
		}

		// 後退
		if (engine::Library::IsHeldKey(KEY_S))
		{
			moveVec.x -= sinf(m_rote.y / 180.0f * M_PI) * m_nomalSpeed / 3;
			moveVec.z -= cosf(m_rote.y / 180.0f * M_PI) * m_nomalSpeed / 3;
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
			moveVec.y = m_jump;
		}

		m_pos += moveVec;
	}

	void Player::MoveReturn()
	{
		Stage::StageSize stageSize = m_stage->GetStageData();

		if (m_pos.z < stageSize.stageRight) { m_pos.z = stageSize.stageRight; }
		if (m_pos.z > stageSize.stageLeft) { m_pos.z = stageSize.stageLeft; }

		if (m_pos.x < stageSize.stageBack) { m_pos.x = stageSize.stageBack; }
		if (m_pos.x > stageSize.stageFront) { m_pos.x = stageSize.stageFront; }

		if (m_pos.y < stageSize.stageDown + m_height / 2) { m_pos.y = stageSize.stageDown + m_height / 2; m_canJump = true; }
		if (m_pos.y > stageSize.stageUp) { m_pos.y = stageSize.stageUp; }
	}
}