#include "InGameScene.h"

#include "../../Library/Library.h"
#include "Collision.h"

#include <vector>

namespace Game
{
	InGameScene::InGameScene()
	{
		std::vector<int> keyList = { KEY_A, KEY_D, KEY_S, KEY_W, KEY_SPACE, KEY_SHIFT ,KEY_LMOUSE ,KEY_ESC };
		m_nextScene = Scene::Title;
		engine::Library::RegisterKey(keyList);
		engine::Library::SetDrawingDistance(0.1f, 5000.0f);

		m_stage = new Stage;
		m_bulletManager = new BulletManager;
		m_player = new Player(m_stage, m_bulletManager);
		m_gameUI = new GameUI(m_player);
		m_camera = new CameraManager(m_player);
		m_option = new Option;
		m_enemyManager = new EnemyManager(m_stage, m_bulletManager);
		m_result = new Result(m_enemyManager);
		m_collision = new Collision(m_player, m_bulletManager, m_enemyManager);

		ShowCursor(FALSE);
	}

	InGameScene::~InGameScene()
	{
		delete m_collision;
		delete m_enemyManager;
		delete m_result;
		delete m_option;
		delete m_bulletManager;
		delete m_gameUI;
		delete m_camera;
		delete m_stage;
		delete m_player;
	}

	void InGameScene::Exec()
	{
		switch (m_currentPhase)
		{
		case InGameScenePhase::Game:
			UpdateGame();
			break;
		case InGameScenePhase::Option:
			UpdateOption();
			break;
		case InGameScenePhase::Result:
			UpdateResult();
			break;
		default:
			break;
		}
	}

	void InGameScene::Draw()
	{
		m_stage->Draw();
		m_bulletManager->Draw();
		m_enemyManager->Draw();
		m_gameUI->DrawPlayerUI();
		m_option->Draw();
		m_result->Draw();
	}

	void InGameScene::UpdateGame()
	{
		m_player->Update();
		m_stage->Update();
		m_camera->Update();
		m_bulletManager->Update();
		m_enemyManager->Update();
		m_collision->Collide();

		SetCursorPos(GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2);

		// オプションへ移行
		if (engine::Library::IsPushedKey(KEY_ESC))
		{
			m_currentPhase = InGameScenePhase::Option;
			m_option->ConvertIsAlive();
			ShowCursor(TRUE);
		}

		// リザルト以降
		if (m_player->IsDead())
		{
			m_result->ConvertIsAlive();
			m_currentPhase = InGameScenePhase::Result;
			ShowCursor(TRUE);
		}
	}

	void InGameScene::UpdateResult()
	{
		if (engine::Library::IsHeldKey(KEY_ENTER))
		{
			m_isNextScene = true;
		}
	}

	void InGameScene::UpdateOption()
	{
		if (engine::Library::IsPushedKey(KEY_ESC))
		{
			m_currentPhase = InGameScenePhase::Game;
			m_option->ConvertIsAlive();
			ShowCursor(FALSE);
		}
	}
}
