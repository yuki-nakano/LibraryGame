#ifndef BULLET_STRAIGHT_H
#define BULLET_STRAIGHT_H

#include "ObjBase.h"
#include "BulletBase.h"

#include <string>

namespace Game
{
	/**
	* @brief 弾クラス
	*/
	class BulletStraight : public BulletBase
	{
	public:
		BulletStraight(const BulletState& bullet_state_, const engine::Vec3f& pos_, const engine::Vec3f& rote_, const engine::Vec3f& scale_);
		~BulletStraight() = default;

	public:
		/**
		* @brief 更新関数
		*/
		void Update() override;

		/**
		* @brief 描画関数
		*/
		void Draw() override;

		/**
		* @brief 接触時に呼び出す関数
		*/
		void Hit(ObjBase* obj_base_) override;

	private:
		engine::Vec3f m_moveVec{};
	};
}

#endif // !BULLET_STRAIGHT_H
