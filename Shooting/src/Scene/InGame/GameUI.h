#ifndef GAME_UI_H

#include "Player.h"

namespace Game
{
	class GameUI
	{
	public:
		GameUI(Player* player_);
		~GameUI() {};

	public:
		void Update();

		void Draw();

		/**
		* @brief プレイヤーのUIの描画
		*/
		void DrawPlayerUI();

	private:
		/// プレイヤー情報
		Player* m_player{};
	};
}

#endif // !GAME_UI_H
