#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

#include "../SceneBase.h"
#include "Player.h"
#include "GameUI.h"
#include "CameraManager.h"
#include "Stage.h"
#include "BulletManager.h"
#include "Option.h"
#include "../../Enemy/EnemyManager.h"

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
		void Collide();
		void CollidePlayer(ObjBase* obj_base_);
		void CollideEnemy(ObjBase* obj_base_);

	private:
		Player* m_player{};
		GameUI* m_gameUI{};
		CameraManager* m_camera{};
		Stage* m_stage{};
		BulletManager* m_bullet{};
		EnemyManager* m_enemy{};
		Option* m_option{};

		int m_timer{ 0 };
	};
}

#endif // !INGAME_SCENE_H
