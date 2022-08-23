#include "InGameScene.h"

#include "../../Library/Library.h"

#include <vector>

namespace Game
{
	InGameScene::InGameScene()
	{
		std::vector<int> keyList = { KEY_A, KEY_D, KEY_S, KEY_W, KEY_SPACE, KEY_SHIFT };
		engine::Library::RegisterKey(keyList);

		m_player = new Player;
		m_gameUI = new GameUI(m_player);
		m_camera = new CameraManager(m_player);
		m_stage = new Stage;

		nextScene = Scene::Result;
	}

	InGameScene::~InGameScene()
	{
		delete m_player;
		m_player = nullptr;
	}

	void InGameScene::Exec()
	{
		m_player->Update();
		m_camera->Update();

		m_timer++;
	}

	void InGameScene::Draw()
	{
		m_player->Draw();
		m_gameUI->DrawPlayerUI();
		m_stage->Draw();
	}

	bool InGameScene::IsEnd()
	{
		return false;
	}
}
