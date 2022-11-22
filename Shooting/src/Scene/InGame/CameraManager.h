#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include "Player.h"

namespace Game
{
	/**
	* @brief カメラ管理クラス
	*/
	class CameraManager
	{
	public:
		CameraManager(Player* player_);
		~CameraManager() = default;

	public:
		/**
		* @brief 更新
		*/
		void Update();

	private:
		/// プレイヤー情報
		Player* m_player{};
	};

}

#endif // !CAMERA_MANAGER_H
