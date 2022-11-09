#include "InGameScene.h"

#include "../../Library/Library.h"
#include "Collision.h"

#include <vector>

namespace Game
{
	InGameScene::InGameScene()
	{
		std::vector<int> keyList = { KEY_A, KEY_D, KEY_S, KEY_W, KEY_SPACE, KEY_SHIFT ,KEY_LMOUSE ,KEY_ESC };
		nextScene = Scene::Title;
		engine::Library::RegisterKey(keyList);
		engine::Library::SetZ(0.1f, 5000.0f);

		m_stage = new Stage;
		m_bullet = new BulletManager;
		m_player = new Player(m_stage, m_bullet);
		m_gameUI = new GameUI(m_player);
		m_camera = new CameraManager(m_player);
		m_option = new Option;
		m_enemy = new EnemyManager(m_stage, m_bullet);
		m_result = new Result(m_enemy);

		ShowCursor(FALSE);
	}

	InGameScene::~InGameScene()
	{
		delete m_enemy;
		delete m_result;
		delete m_option;
		delete m_bullet;
		delete m_gameUI;
		delete m_camera;
		delete m_stage;
		delete m_player;

		ShowCursor(TRUE);
	}

	void InGameScene::Exec()
	{
		if (m_result->Exec())
		{
			if (engine::Library::IsHeldKey(KEY_ENTER))
			{
				m_isNextScene = true;
			}

			return;
		}

		if (m_option->Exec())
		{
			return;
		}

		m_player->Update();
		m_stage->Update(m_player);
		m_camera->Update();
		m_bullet->Update();
		m_enemy->Update();

		Collide();

		SetCursorPos(GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2);
		m_timer++;

		if (m_player->GetState().hp < 0)
		{
			m_result->ConvertIsAlive();
		}
	}

	void InGameScene::Draw()
	{
		m_stage->Draw();

		m_player->Draw();
		m_bullet->Draw();
		m_enemy->Draw();

		m_gameUI->DrawPlayerUI();

		m_option->Draw();

		m_result->Draw();
	}

	void InGameScene::Collide()
	{
		for (auto bullet : m_bullet->GetBulletList())
		{
			BulletState bulletState = bullet->GetState();

			switch (bulletState.m_bulletType)
			{
			case BulletType::Enemy:
				CollidePlayer(bullet);
				break;
			case BulletType::Player:
				CollideEnemy(bullet);
				break;
			default:
				break;
			}
		}

		CollideEnemy(m_player);
	}

	void InGameScene::CollidePlayer(ObjBase* obj_base_)
	{
		if (CollideSphereAndSphere(
			m_player->GetPos(), m_player->GetState().hitRadius,
			obj_base_->GetPos(), obj_base_->GetState().hitRadius))
		{
			m_player->Hit(obj_base_);
			obj_base_->Hit(m_player);
		}
	}

	void InGameScene::CollideEnemy(ObjBase* obj_base_)
	{
		ObjBase* result = m_enemy->Collide(obj_base_);
		if (result != nullptr)
		{
			obj_base_->Hit(result);
		}
	}
}
