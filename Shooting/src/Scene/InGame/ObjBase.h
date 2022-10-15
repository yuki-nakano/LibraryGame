#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include "../../Library/DirectX/DirectXUtility.h"

namespace Game
{
	struct ObjState
	{
		int hp{};
		int damage{};
		float hitRadius{};
	};

	class ObjBase
	{
	public:
		ObjBase() = default;
		~ObjBase() = default;

	public:
		virtual void Update() = 0;

		virtual void Draw() = 0;

		virtual void Hit(ObjBase* obj_base_) = 0;

		engine::Vec3f GetPos() { return m_pos; }
		engine::Vec3f GetRote() { return m_rote; }
		engine::Vec3f GetScale() { return m_scale; }
		ObjState GetState() { return m_objState; }

		void SetPos(const engine::Vec3f& pos_) { m_pos = pos_; }
		void SetRote(const engine::Vec3f& rote_) { m_rote = rote_; }
		void SetScale(const engine::Vec3f& scale_) { m_scale = scale_; }
		void SetState(const ObjState& state_) { m_objState = state_; }

	protected:
		ObjState m_objState{};

		engine::Vec3f m_pos{};
		engine::Vec3f m_rote{};
		engine::Vec3f m_scale{ 1.0f, 1.0f, 1.0f };
	};
}

#endif // !OBJECT_BASE_H
