#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

#include "../SceneBase.h"
#include "../../Object/Player.h"
#include "GameUI.h"
#include "CameraManager.h"
#include "Stage.h"

namespace Game
{
	class InGameScene : public SceneBase
	{
	public:
		InGameScene();
		~InGameScene();

	public:
		void Exec();

		void Draw();

		bool IsEnd();

	private:
		Player* m_player{};
		GameUI* m_gameUI{};
		CameraManager* m_camera{};
		Stage* m_stage{};

		int m_timer{ 0 };
	};
}

#endif // !INGAME_SCENE_H
