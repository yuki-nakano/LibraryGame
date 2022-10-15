#include "Collision.h"

#include <math.h>
#include <numeric>
#include <vector>

#include "../Model/ObjManager.h"
#include "../Model/Obj.h"
#include "../DirectX/Matrix.h"

namespace engine
{
	bool Collision::CollideObjAndObj(const ObjData& obj_a_, const ObjData& obj_b_)
	{
		Obj* objA = ObjManager::GetInstance()->GetObj(obj_a_.name);
		Obj* objB = ObjManager::GetInstance()->GetObj(obj_b_.name);

		DirectX::XMMATRIX world = Matrix::GetInstance()->CreateWorldMatrix(obj_a_.pos, obj_b_.rote, obj_a_.scal);

		return false;
	}

	Vec3f Collision::ChangeWorldPos(std::array<float, 4> vertex_, const DirectX::XMMATRIX& world_)
	{
		DirectX::XMVECTOR pos = DirectX::XMVectorSet(vertex_[0], vertex_[1], vertex_[2], vertex_[3]);

		Vec3f result{};
		DirectX::XMStoreFloat(&result.x, DirectX::XMVector4Dot(pos, world_.r[0]));
		DirectX::XMStoreFloat(&result.y, DirectX::XMVector4Dot(pos, world_.r[1]));
		DirectX::XMStoreFloat(&result.z, DirectX::XMVector4Dot(pos, world_.r[2]));

		return result;
	}


}
