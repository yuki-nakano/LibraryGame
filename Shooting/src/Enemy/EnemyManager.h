#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "EnemyFactory.h"
#include "../Scene/InGame/Stage.h"

#include <vector>

namespace Game
{
	/**
	* @brief エネミーファクトリー管理クラス
	*/
	class EnemyManager
	{
	public:
		EnemyManager(Stage* stage_, BulletManager* bullet_manager_);
		~EnemyManager();

	public:
		void Update();

		void Draw();

		/**
		* @brief エネミーファクトリーの生成
		*/
		void CreateEnemy();

		/**
		* @brief 接触チェック
		* @param obj_base_ 接触したオブジェクト
		*/
		ObjBase* Collide(ObjBase* obj_base_);

		/**
		* @brief 倒したエネミーの数の取得
		* @return 倒したエネミーの数
		*/
		int GetDeadEnemyNum();

	private:
		/// 弾
		BulletManager* m_bullet{};

		/// 生成したエネミーファクトリー
		std::vector<EnemyFactory*> m_enemyList{};
		Stage* m_stage{};

		int m_summonTimer{ 300 };	/// 生成タイマー 
		int m_summmonTime{ 300 };	/// 生成時間 

		int m_maxEnemyNum{ 1 };	/// 生成できるエネミーファクトリーの最大数

		int m_deadEnemyNum{ 0 };	/// 倒されたエネミーの数	
	};
}

#endif // !ENEMY_MANAGER_H
