#include "CameraManager.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include "../../Library/Library.h"

namespace Game
{
	CameraManager::CameraManager(Player* player_)
		:m_player(player_)
	{
	}

	CameraManager::~CameraManager()
	{
	}

	void CameraManager::Update()
	{
		engine::Vec3f playerPos = m_player->GetPos();
		engine::Vec3f playerRote = m_player->GetRote();
		engine::Vec3f cameraPos{};
		cameraPos.x = playerPos.x - sinf(playerRote.y / 180.0f * M_PI) * 100;
		cameraPos.z = playerPos.z - cosf(playerRote.y / 180.0f * M_PI) * 100;
		cameraPos.y = playerPos.y + 30;
		engine::Library::SetCameraPos(engine::Vec4f(cameraPos.x, cameraPos.y, cameraPos.z, 0.0f));
		engine::Library::SetFocusPos(engine::Vec4f(playerPos.x, playerPos.y, playerPos.z, 0.0f));
	}
}

