#ifndef COLLISION_H
#define COLLISION_H

#include "../../Library/Library.h"

#include "BulletManager.h"
#include "Player.h"
#include "../../Enemy/EnemyManager.h"

namespace Game
{
	class Collision
	{
	public:
		Collision(Player* player_, BulletManager* bullet_manager_, EnemyManager* enemy_manager_);
		~Collision() = default;

	public:
		/**
		* @brief 当たり判定計算関数
		*/
		void Collide();

	private:
		/**
		* @brief プレイヤーと弾の当たり判定
		*/
		void CollidePlayerAndBullet();

		/**
		* @brief プレイヤーとエネミーの当たり判定
		*/
		void CollidePlayerAndEnemy();

		/**
		* @brief 弾とエネミーの当たり判定
		*/
		void CollideBulletAndEnemy();

	private:
		Player* m_player{};					/// プレイヤー
		BulletManager* m_bulletManager{};	/// 弾
		EnemyManager* m_enemyManager{};		/// エネミー

	};
}

#endif // !COLLISION_H
