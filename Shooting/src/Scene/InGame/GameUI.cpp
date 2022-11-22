#include "GameUI.h"

#include "../../Library/Library.h"

namespace Game
{
	GameUI::GameUI(ObjBase* player_)
		:m_player(player_)
	{
		engine::Library::LoadTexture(L"res/InGame/Target.png", "target");
	}

	GameUI::~GameUI()
	{
		engine::Library::ReleaseTexture("target");
	}

	void GameUI::Draw()
	{
		DrawPlayerUI();
	}

	void GameUI::DrawPlayerUI()
	{
		int playerHp = m_player->GetObjState().hp;

		engine::Library::DrawRect(engine::Vec2f(0.0f, 690.0f), 1080.0f * playerHp / 1000.0f, 30.0f, engine::Vec3f(1.0f, playerHp / 1000.0f, playerHp / 1000.0f));
		// 画面中央に描画 画像サイズ 50 * 50
		engine::Library::DrawTexture("target", engine::Vec2f(515, 335), 50, 50);
	}
}
