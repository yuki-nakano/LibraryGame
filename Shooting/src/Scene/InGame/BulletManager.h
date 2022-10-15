#ifndef BULLET_MANAGER_H
#define BULLET_MANAGER_H

#include "Bullet.h"
#include "../../Library/Library.h"

#include <vector>

namespace Game
{
	class BulletManager
	{
	public:
		BulletManager() = default;
		~BulletManager() = default;

	public:
		void CreateBullet(const BulletState& bullet_state_, const ObjState& obj_state_, const engine::Vec3f& pos_, const engine::Vec3f& rote_, const engine::Vec3f& scale_);

		void Update();

		void Draw();

		std::vector<Bullet*> GetBulletList() { return m_bulletList; }

	private:
		std::vector<Bullet*> m_bulletList{};
	};
}

#endif // !BULLET_MANAGER_H
