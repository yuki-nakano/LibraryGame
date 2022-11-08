#ifndef BULLET_MANAGER_H
#define BULLET_MANAGER_H

#include "Bullet.h"
#include "../../Library/Library.h"

#include <vector>

namespace Game
{
	/**
	* @brief 弾管理クラス
	*/
	class BulletManager
	{
	public:
		BulletManager();
		~BulletManager();

	public:
		/**
		* @brief 弾の生成
		* @param bullet_state_ 弾のステータス
		* @param obj_state_ オブジェクトのステータス
		* @param pos_ 座標
		* @param rote_ 回転
		* @param scale_ 拡縮
		*/
		void CreateBullet(const BulletState& bullet_state_, const ObjState& obj_state_, const engine::Vec3f& pos_, const engine::Vec3f& rote_, const engine::Vec3f& scale_);

		void Update();

		void Draw();

		// アクセサ

		std::vector<Bullet*> GetBulletList() { return m_bulletList; }

	private:
		/// 弾リスト
		std::vector<Bullet*> m_bulletList{};
	};
}

#endif // !BULLET_MANAGER_H
