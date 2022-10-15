#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include "Player.h"

namespace Game
{
	class CameraManager
	{
	public:
		CameraManager(Player* player_);
		~CameraManager() = default;

	public:
		void Update();

	private:
		Player* m_player{};
	};

}

#endif // !CAMERA_MANAGER_H
