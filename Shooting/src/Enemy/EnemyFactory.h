#ifndef ENEMY_FACTORY_H
#define ENEMY_FACTORY_H

#include "../Scene/InGame/ObjBase.h"
#include "EnemyBase.h"

#include <vector>

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
	class EnemyFactory : public ObjBase
	{
	public:
		EnemyFactory(EnemyFactoryState enemy_factory_state_);
		~EnemyFactory() = default;

	public:
		void Update();

		void Draw();

		/**
		* @brief エネミー生成
		*/
		void CreateEnemy();

		/**
		* @brief 接触チェック
		* @param obj_base_ 接触したオブジェクト
		*/
		ObjBase* Collide(ObjBase* obj_base_);

		void Hit(ObjBase* obj_base_);

		// アクセサ

		EnemyFactoryState GetFactoryState() { return m_enemyFactoryState; }

	private:
		/// エネミーファクトリーのステータス
		EnemyFactoryState m_enemyFactoryState{};

		/// 生成したエネミー
		std::vector<EnemyBase*> m_enemyList{};

		int m_summonTimer{ 0 };		/// 生成タイマー
		int m_summmonTime{ 300 };	/// 生成時間
	};
}

#endif // !ENEMY_FACTORY_H
