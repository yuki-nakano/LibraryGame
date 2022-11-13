#ifndef ENEMY_FACTORY_H
#define ENEMY_FACTORY_H

#include "../Scene/InGame/ObjBase.h"
#include "EnemyBase.h"

#include <vector>

class BulletManager;

namespace Game
{
	/**
	* @brief エネミーファクトリーのステータス
	*/
	struct EnemyFactoryState
	{
		EnemyType enemyType{};	/// 生成するエネミーのタイプ
		int maxNum{};			/// 生成するエネミーの最大数
		int hp{};				/// エネミーファクトリーの体力
	};

	/**
	* @brief エネミー生成クラス
	*/
	class EnemyFactory
	{
	public:
		EnemyFactory(BulletManager* bullet_manager_, EnemyFactoryState enemy_factory_state_, const engine::Vec3f& pos_);
		~EnemyFactory();

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

		// アクセサ

		EnemyFactoryState GetFactoryState() { return m_enemyFactoryState; }
		engine::Vec3f GetPos() { return m_pos; }

		void SetPos(const engine::Vec3f& pos_) { m_pos = pos_; }

	private:
		/// 弾
		BulletManager* m_bulletManager{};

		/// エネミーファクトリーのステータス
		EnemyFactoryState m_enemyFactoryState{};

		/// 生成したエネミー
		std::vector<EnemyBase*> m_enemyList{};

		int m_summonTimer{ 0 };		/// 生成タイマー
		int m_summonTime{ 300 };	/// 生成時間

		engine::Vec3f m_pos{};	/// 座標
	};
}

#endif // !ENEMY_FACTORY_H
