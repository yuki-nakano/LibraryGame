#include "SceneManager.h"

#include "TitleScene.h"
#include "InGame/InGameScene.h"

namespace Game
{
	SceneManager::SceneManager()
	{
		m_currentScene = new InGameScene();
	}

	SceneManager::~SceneManager()
	{
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
		case Scene::Result:

			break;
		default:
			break;
		}

		delete m_currentScene;
		m_currentScene = nextScene;
	}
}