#ifndef ENEMY_SPAWNER_H
#define ENEMY_SPAWNER_H

#include "../Scene/InGame/ObjBase.h"
#include "EnemyBase.h"

#include <vector>

class BulletManager;

namespace Game
{
	/**
	* @brief エネミースポナーのステータス
	*/
	struct EnemySpawnerState
	{
		EnemyType enemyType{};	/// 生成するエネミーのタイプ
		int maxNum{};			/// 生成するエネミーの最大数
		int hp{};				/// エネミーファクトリーの体力
	};

	/**
	* @brief エネミー生成クラス
	*/
	class EnemySpawner
	{
	public:
		EnemySpawner(BulletManager* bullet_manager_, EnemySpawnerState enemy_spawner_state_, const engine::Vec3f& pos_);
		~EnemySpawner();

	public:
		/**
		* @brief 更新関数
		*/
		void Update();

		/**
		* @brief 描画関数
		*/
		void Draw();

		/**
		* @brief エネミー生成
		*/
		void CreateEnemy();

		/**
		* @brief 接触チェック
		*/
		void Collide(ObjBase* obj_base_);

		/**
		* @brief エネミースポナーの死亡判定
		* @return エネミースポナーの体力が0以下になるとtrue
		*/
		bool IsDead();

		// アクセサ

		EnemySpawnerState GetSpawnerState() { return m_enemySpawnerState; }
		engine::Vec3f GetPos() { return m_pos; }

		void SetPos(const engine::Vec3f& pos_) { m_pos = pos_; }

	private:
		/// 弾
		BulletManager* m_bulletManager{};

		/// エネミースポナーのステータス
		EnemySpawnerState m_enemySpawnerState{};

		/// 生成したエネミー
		std::vector<EnemyBase*> m_enemyList{};

		int m_summonTimer{ 0 };		/// 生成タイマー
		int m_summonTime{ 300 };	/// 生成時間

		engine::Vec3f m_pos{};	/// 座標
	};
}

#endif // !ENEMY_SPAWNER_H
