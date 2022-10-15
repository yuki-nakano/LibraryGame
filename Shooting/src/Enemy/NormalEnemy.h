#ifndef NORMAL_ENEMY_H
#define NORMAL_ENEMY_H

#include "../Enemy/EnemyBase.h"
#include "ActionBase.h"
#include "Tree.h"
#include "../Library/Library.h"

namespace Game
{
	class NormalEnemy : public EnemyBase
	{
	public:
		NormalEnemy(const engine::Vec3f& factory_pos_);
		~NormalEnemy() = default;

		void Update();

		void Draw();

		void Hit(ObjBase* obj_base_);

	private:
		Tree* aiTree;
		Node* activeNode;
	};
}

#endif // !NORMAL_ENEMY_H
