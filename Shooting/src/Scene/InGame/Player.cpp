#include "Player.h"

#include "../../Library/Library.h"
#include "Stage.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>

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

		ReturnToStage();

		if (engine::Library::IsHeldKey(KEY_LMOUSE) && m_bulletCoolTimer <= 0)
		{
			engine::Vec3f pos = m_pos;

			ObjState objState{ 1, 5, 15.0f };
			BulletState bulletState{
				BulletType::Player,
				50.0f,
				300,
				10,
				"star"
			};
			m_bulletManager->CreateBullet(bulletState, objState, pos += engine::Vec3f(0.0f, m_height / 2, 0.0f), m_rote, engine::Vec3f(10.0f, 10.0f, 10.0f));

			m_bulletCoolTimer = bulletState.m_coolTime;
		}

		m_bulletCoolTimer--;
	}

	void Player::Hit(ObjBase* obj_base_)
	{
		m_objState.hp -= obj_base_->GetObjState().damage;
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
		m_rote.x = std::clamp(m_rote.x, -m_maxRote, m_maxRote);

		// 移動量
		engine::Vec3f moveVec{};

		// 加速
		if (engine::Library::IsHeldKey(KEY_SHIFT))
		{
			m_moveSpeed += m_acceleration;
		}
		else
		{
			m_moveSpeed += m_deceleration;
		}
		m_moveSpeed = std::clamp(m_moveSpeed, m_nomalSpeed, m_maxSpeed);

		// 左移動
		CalculateMoveVec(KEY_A, m_rote.y - 90.0f, m_nomalSpeed / 2, moveVec);

		// 右移動
		CalculateMoveVec(KEY_D, m_rote.y + 90.0f, m_nomalSpeed / 2, moveVec);

		// 前進
		CalculateMoveVec(KEY_W, m_rote.y, m_moveSpeed, moveVec);

		// 後退
		CalculateMoveVec(KEY_S, m_rote.y + 180.0f, m_nomalSpeed / 3, moveVec);

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

	void Player::CalculateMoveVec(const int& key_, const float& rote_, const float& scale_, engine::Vec3f& move_vec_)
	{
		if (!engine::Library::IsHeldKey(key_)) { return; }

		move_vec_.x += sinf(rote_ / 180.0f * M_PI) * scale_;
		move_vec_.z += cosf(rote_ / 180.0f * M_PI) * scale_;
	}

	void Player::ReturnToStage()
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