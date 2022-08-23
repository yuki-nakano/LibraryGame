#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include "../../Object/Player.h"

namespace Game
{
	class CameraManager
	{
	public:
		CameraManager(Player* player_);
		~CameraManager();

	public:
		void Update();

	private:
		Player* m_player{};
	};

}

#endif // !CAMERA_MANAGER_H
