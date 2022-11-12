﻿#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

#include "../SceneBase.h"
#include "Player.h"
#include "GameUI.h"
#include "CameraManager.h"
#include "Stage.h"
#include "BulletManager.h"
#include "Option.h"
#include "Result.h"
#include "../../Enemy/EnemyManager.h"

namespace Game
{
	/**
	* @brief ゲームシーン
	*/
	class InGameScene : public SceneBase
	{
	public:
		InGameScene();
		~InGameScene();

	public:
		/**
		* @brief 実行関数
		*/
		void Exec();

		/**
		* @brief 描画関数
		*/
		void Draw();

	private:
		// 接触判定

		void Collide();
		void CollidePlayer(ObjBase* obj_base_);
		void CollideEnemy(ObjBase* obj_base_);

	private:
		Player* m_player{};					/// プレイヤー
		GameUI* m_gameUI{};					/// UI
		CameraManager* m_camera{};			/// カメラ
		Stage* m_stage{};					/// ステージ
		BulletManager* m_bulletManager{};	/// 弾
		EnemyManager* m_enemyManager{};		/// エネミー
		Option* m_option{};					/// オプション
		Result* m_result{};					/// リザルト

		int m_timer{ 0 };	/// タイマー
	};
}

#endif // !INGAME_SCENE_H