#include "SceneManager.h"

#include "Title/TitleScene.h"
#include "InGame/InGameScene.h"

namespace Game
{
	SceneManager::SceneManager()
	{
		m_currentScene = new TitleScene();
	}

	void SceneManager::Update()
	{
		if (m_currentScene == nullptr) { return; }

		m_currentScene->Exec();

		m_currentScene->Draw();

		if (m_currentScene->IsEnd())
		{
			ChangeScene();
		}
	}

	void SceneManager::ChangeScene()
	{
		if (m_currentScene == nullptr) { return; }

		SceneBase* nextScene{ nullptr };

		switch (m_currentScene->GetNextScene())
		{
		case Scene::Title:
			nextScene = new TitleScene();
			break;
		case Scene::InGame:
			nextScene = new InGameScene();
			break;
		default:
			break;
		}

		delete m_currentScene;
		m_currentScene = nextScene;
	}
}