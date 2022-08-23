#include "TitleScene.h"

#include "../Library/Library.h"

namespace Game
{
	TitleScene::TitleScene()
	{
		nextScene = Scene::InGame;
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Exec()
	{
	}

	void TitleScene::Draw()
	{
	}

	bool TitleScene::IsEnd()
	{
		return false;
	}
}
