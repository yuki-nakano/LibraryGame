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

		/**
		* @brief 終了判定関数
		* @return 終了時にtrue
		*/
		bool IsEnd();

	private:
		// 接触判定

		void Collide();
		void CollidePlayer(ObjBase* obj_base_);
		void CollideEnemy(ObjBase* obj_base_);

	private:
		Player* m_player{};			/// プレイヤー
		GameUI* m_gameUI{};			/// UI
		CameraManager* m_camera{};	/// カメラ
		Stage* m_stage{};			/// ステージ
		BulletManager* m_bullet{};	/// 弾
		EnemyManager* m_enemy{};	/// エネミー
		Option* m_option{};			/// オプション

		int m_timer{ 0 };	/// タイマー
	};
}

#endif // !INGAME_SCENE_H
