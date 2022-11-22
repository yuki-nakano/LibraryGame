#ifndef GAME_UI_H

#include "ObjBase.h"

namespace Game
{
	/**
	* @brief ゲームシーン中のUI
	*/
	class GameUI
	{
	public:
		GameUI(ObjBase* player_);
		~GameUI();

	public:
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
		ObjBase* m_player{};
	};
}

#endif // !GAME_UI_H
