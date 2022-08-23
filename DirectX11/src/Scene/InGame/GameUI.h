#ifndef GAME_UI_H

#include "../../Object/Player.h"

namespace Game
{
	class GameUI
	{
	public:
		GameUI(Player* player_);
		~GameUI();

	public:
		void Update();

		void Draw();

		void DrawPlayerUI();

	private:
		Player* m_player{};
	};

}

#endif // !GAME_UI_H
