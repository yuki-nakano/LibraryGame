#include "GameUI.h"

#include "../../Library/Library.h"

namespace Game
{
	GameUI::GameUI(Player* player_)
		:m_player(player_)
	{
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
		engine::Library::DrawRect(engine::Vec2f(0, 690), 1080 * m_player->GetEnergyPer(), 30, engine::Vec3f(1.0f, 0.0f, 0.0f));
	}
}
