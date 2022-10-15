#ifndef COLLISION_H
#define COLLISION_H

#include "../../Library/Library.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace Game
{
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

#endif // !COLLISION_H
