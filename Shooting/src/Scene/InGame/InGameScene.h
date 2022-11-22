#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

#include "../SceneBase.h"
#include "Player.h"
#include "GameUI.h"
#include "CameraManager.h"
#include "Stage.h"
#include "BulletManager.h"
#include "Option.h"
#include "Result.h"
#include "Collision.h"
#include "../../Enemy/EnemyManager.h"

namespace Game
{
	/**
	* @brief ゲームシーン
	*/
	class InGameScene : public SceneBase
	{
	private:
		/// インゲーム内のフェーズ
		enum class InGameScenePhase
		{
			Game,
			Option,
			Result,
		};


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
		/**
		* @brief ゲーム情報の更新
		*/
		void UpdateGame();

		/**
		* @brief オプションの更新
		*/
		void UpdateResult();

		/**
		* @brief リザルトの更新
		*/
		void UpdateOption();

	private:
		Player* m_player{};					/// プレイヤー
		GameUI* m_gameUI{};					/// UI
		CameraManager* m_camera{};			/// カメラ
		Stage* m_stage{};					/// ステージ
		BulletManager* m_bulletManager{};	/// 弾
		EnemyManager* m_enemyManager{};		/// エネミー
		Option* m_option{};					/// オプション
		Result* m_result{};					/// リザルト
		Collision* m_collision{};			/// 当たり判定

		int m_timer{ 0 };	/// タイマー

		InGameScenePhase m_currentPhase{ InGameScenePhase::Game };	// 現在のフェーズ
	};
}

#endif // !INGAME_SCENE_H
