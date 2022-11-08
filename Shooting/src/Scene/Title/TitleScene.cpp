#include "TitleScene.h"

#include "../../Library/Library.h"

namespace Game
{
	TitleScene::TitleScene()
	{
		nextScene = Scene::InGame;
		std::vector<int> keyList = { KEY_ENTER };
		engine::Library::RegisterKey(keyList);

		engine::Library::LoadTexture(L"res/Title/BackGround.png", "TitleBG");
		engine::Library::LoadTexture(L"res/Title/Title.png", "Title");
		engine::Library::LoadTexture(L"res/Title/PleaseEnter.png", "TitleButton");
	}

	TitleScene::~TitleScene()
	{
		engine::Library::ReleseTexture("TitleBG");
		engine::Library::ReleseTexture("Title");
		engine::Library::ReleseTexture("TitleButton");
	}

	void TitleScene::Exec()
	{
		if (engine::Library::IsPushedKey(KEY_ENTER))
		{
			m_isNextScene = true;
		}
	}

	void TitleScene::Draw()
	{
		engine::Library::DrawTexture("TitleBG", engine::Vec2f(0.0f, 0.0f), 1080, 720);
		engine::Library::DrawTexture("Title", engine::Vec2f(191.0f, 100.0f), 698.0f, 84.0f);
		engine::Library::DrawTexture("TitleButton", engine::Vec2f(104.0f, 500.0f), 872.0f, 98.0f);
	}

	bool TitleScene::IsEnd()
	{
		return m_isNextScene;
	}
}
