#ifndef ENEMY_BASE_H
#define ENEMY_BASE_H

#include "../Scene/InGame/ObjBase.h"
#include "../Library/Library.h"
#include "Tree.h"

namespace Game
{
	enum class EnemyType
	{
		normal,
	};

	// �G�l�~�[�̌p����
	class EnemyBase : public ObjBase
	{
	public:
		EnemyBase() = default;
		~EnemyBase() = default;

	public:
		// �X�V
		virtual void Update() = 0;

		// �`��
		virtual void Draw() = 0;

		// �ڐG���ɌĂяo��
		void Hit(ObjBase* obj_base_)
		{
			m_objState.hp -= obj_base_->GetState().damage;
		}

		void SubDeadTimer() { m_deadTimer--; }
		void SubInvicibleTimer() { m_invincibleTime--; }

		void ChangeAlive() { m_isAlive ? m_isAlive = false : m_isAlive = true; }

		// �A�N�Z�T

		engine::Vec3f GetFactoryPos() { return m_factoryPos; }
		engine::Vec3f GetTargetPos() { return m_targetPos; }
		float GetDistance() { return m_distance; }
		float GetFOV() { return m_fov; }
		float GetFar() { return m_far; }
		float GetLoopTime() { return m_loopTime; }
		float GetDeadTimer() { return m_deadTimer; }
		float GetInvicibleTimer() { return m_invincibleTimer; }
		bool GetAlive() { return m_isAlive; }

		void SetFactoryPos(const engine::Vec3f& factory_pos_) { m_factoryPos = factory_pos_; }
		void SetTargetPos(const engine::Vec3f& target_pos_) { m_targetPos = target_pos_; }

	protected:
		// �r�w�[�r�A�p�c���[
		Tree* m_tree{};

		engine::Vec3f m_col{ 0.0f, 0.0f, 0.0f };			// �ʏ펞�̐F
		engine::Vec3f m_invincibleCol{ 1.0f, 0.0f, 0.0f };	// ���G���̐F

		engine::Vec3f m_factoryPos{};	// �������̍��W
		engine::Vec3f m_targetPos{};	// �ǐՑΏۂ̍��W

		float m_distance{ 300.0f };		//�������Ƃ̋���

		float m_fov{ 45.0f };		// ����p
		float m_far{ 300.0f };		// ����̔��a
		float m_loopTime{ 180 };	// ���������������܂ł̎���

		bool m_isAlive{ true };		// �����t���O

		int m_deadTime{ 120 };		// ���S����
		int m_deadTimer{ 120 };		// ���S���Ԃ܂ł̃J�E���g

		int m_invincibleTime{ 60 };	// ���G����
		int m_invincibleTimer{ 0 };	// ���G���Ԃ̃J�E���g
	};
}

#endif // !ENEMY_BASE_H
