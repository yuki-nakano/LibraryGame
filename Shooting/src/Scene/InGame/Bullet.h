#ifndef BULLET_H
#define BULLET_H

#include "ObjBase.h"

#include <string>

namespace Game
{
	// �e�̎��
	enum class BulletType
	{
		Player,
		Enemy,
	};

	// �e�̃p�����[�^�[
	struct BulletState
	{
		BulletType m_bulletType{};
		float m_speed{ 10.0f };		// ���x
		int m_deleteTime{ 300 };	// ��������
		int m_coolTime{ 60 };		// �N�[���^�C��
	};

	class Bullet : public ObjBase
	{
	public:
		Bullet(const BulletState& bullet_state);
		~Bullet() = default;

	public:
		void Update();

		void Draw();

		void Hit(ObjBase* obj_base_);

		BulletState GetState() { return m_bulletState; }
		int GetDeleteTime() { return m_bulletState.m_deleteTime; }

	private:
		BulletState m_bulletState{};
		std::string m_objName{ "none" };
	};
}

#endif // !BULLET_H
