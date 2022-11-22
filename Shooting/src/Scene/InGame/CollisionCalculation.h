#ifndef COLLISION_CALCULATION_H
#define COLLISION_CALCULATION_H

#include "../../Library/Library.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
	/**
	* @brief 球の接触判定関数
	* @param pos_a_ １つ目の座標
	* @param radius_a_ １つ目の半径
	* @param pos_b_ ２つ目の座標
	* @param radius_b_ ２つ目の半径
	* @return 接触していたらtrue
	*/
	static bool CollideSphereAndSphere(const engine::Vec3f& pos_a_, const float& radius_a_, const engine::Vec3f& pos_b_, const float& radius_b_)
	{
		float distance = powf((pos_a_.x - pos_b_.x), 2.0f) + powf((pos_a_.y - pos_b_.y), 2.0f) + powf((pos_a_.z - pos_b_.z), 2.0f);

		if (powf((radius_a_ + radius_b_), 2.0f) > distance)
		{
			return true;
		}

		return false;
	}
}

#endif // !COLLISION_CALCULATION_H
