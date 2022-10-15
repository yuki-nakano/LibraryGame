#include "GameUI.h"

#include "../../Library/Library.h"

namespace Game
{
	GameUI::GameUI(Player* player_)
		:m_player(player_)
	{
		engine::Library::LoadTexture(L"res/InGame/Target.png", "target");
	}

	void GameUI::Update()
	{

	}

	void GameUI::Draw()
	{
		DrawPlayerUI();
	}

	void GameUI::DrawPlayerUI()
	{
		float playerHp = m_player->GetEnergyPer();

		engine::Library::DrawRect(engine::Vec2f(0, 690), 1080 * m_player->GetEnergyPer(), 30, engine::Vec3f(1.0f, playerHp, playerHp));
		engine::Library::DrawRect(engine::Vec2f(0, 690), 1080, 30, engine::Vec3f(1.0f, 1.0f, 1.0f));
		engine::Library::DrawTexture("target", engine::Vec2f(515, 335), 50, 50);
	}
}
