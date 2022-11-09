#ifndef GAME_UI_H

#include "Player.h"

namespace Game
{
	/**
	* @brief ゲームシーン中のUI
	*/
	class GameUI
	{
	public:
		GameUI(Player* player_);
		~GameUI();

	public:
		/**
		* @brief 更新関数
		*/
		void Update();

		/**
		* @brief 描画関数
		*/
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
