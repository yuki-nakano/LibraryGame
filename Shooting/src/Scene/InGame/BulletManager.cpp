#include "BulletManager.h"

namespace Game
{
	BulletManager::BulletManager()
	{
		engine::Library::LoadObj("res/enemy/kyu.obj", "bullet");
	}

	BulletManager::~BulletManager()
	{
		for (auto itr = m_bulletList.begin(); itr != m_bulletList.end();)
		{
			delete* itr;
			itr = m_bulletList.erase(itr);
		}

		engine::Library::ReleseObj("bullet");
	}

	void BulletManager::CreateBullet(const BulletState& bullet_state_, const ObjState& obj_state_, const engine::Vec3f& pos_, const engine::Vec3f& rote_, const engine::Vec3f& scale_)
	{
		Bullet* bullet = new Bullet(bullet_state_, pos_, rote_, scale_);
		bullet->SetState(obj_state_);

		m_bulletList.push_back(bullet);
	}

	void BulletManager::Update()
	{
		for (auto itr = m_bulletList.begin(); itr != m_bulletList.end();)
		{
			Bullet* bullet = *itr;

			bullet->Update();

			if (bullet->GetDeleteTime() <= 0)
			{
				delete bullet;
				itr = m_bulletList.erase(itr);
			}
			else
			{
				itr++;
			}
		}
	}

	void BulletManager::Draw()
	{
		for (auto bullet : m_bulletList)
		{
			bullet->Draw();
		}
	}
}
