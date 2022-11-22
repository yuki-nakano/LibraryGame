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

	void CameraManager::Update()
	{
		engine::Vec3f playerPos = m_player->GetPos();
		engine::Vec3f playerRote = m_player->GetRote();
		engine::Vec3f focusPos{};
		focusPos.x = playerPos.x - sinf(playerRote.y / 180.0f * M_PI) * -1;
		focusPos.z = playerPos.z - cosf(playerRote.y / 180.0f * M_PI) * -1;
		focusPos.y = playerPos.y - sinf(playerRote.x / 180.0f * M_PI);
		engine::Library::SetCameraPos(engine::Vec4f(playerPos.x, playerPos.y + m_player->GetHeight() / 2, playerPos.z, 0.0f));
		engine::Library::SetFocusPos(engine::Vec4f(focusPos.x, focusPos.y + m_player->GetHeight() / 2, focusPos.z, 0.0f));
	}
}
