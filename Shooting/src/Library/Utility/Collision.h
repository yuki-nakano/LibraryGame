#ifndef COLLISION_H
#define COLLISION_H

#include <string>

#include <DirectXMath.h>

#include "Singleton.h"
#include "../DirectX/DirectXUtility.h"

namespace engine
{
	class Collision : public Singleton<Collision>
	{
	public:
		struct ObjData
		{
			std::string name;
			Vec3f pos;
			Vec3f rote;
			Vec3f scal;
		};
	private:
		friend class Singleton<Collision>;

		Collision() = default;
		~Collision();

	public:
		bool CollideObjAndObj(const ObjData& obj_a_, const ObjData& obj_b_);

	private:
		Vec3f ChangeWorldPos(std::array<float, 4> vertex_, const DirectX::XMMATRIX& world_);
	};
}

#endif // !COLLISION_H
