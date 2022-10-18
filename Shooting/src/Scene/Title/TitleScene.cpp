#include "TitleScene.h"

#include "../../Library/Library.h"

namespace Game
{
	TitleScene::TitleScene()
	{
		nextScene = Scene::InGame;
		std::vector<int> keyList = { KEY_ENTER };
		engine::Library::RegisterKey(keyList);

		engine::Library::LoadTexture(L"res/Title/BackGround.png", "back");
		engine::Library::LoadTexture(L"res/Title/title.png", "title");
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Exec()
	{
		if (engine::Library::IsHeldKey(KEY_ENTER))
		{
			m_isNextScene = true;
		}
	}

	void TitleScene::Draw()
	{
		engine::Library::DrawTexture("back", engine::Vec2f(0.0f, 0.0f), 1080, 720);
		engine::Library::DrawTexture("title", engine::Vec2f(240.0f, 100.0f), 600.0f, 98.0f);
	}

	bool TitleScene::IsEnd()
	{
		return m_isNextScene;
	}
}
