#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include "../Library/DirectX/DirectXUtility.h"

namespace Game
{
	class ObjctBase
	{
	public:
		ObjctBase() {};
		~ObjctBase() {};

	public:
		virtual void Update() = 0;

		virtual void Draw() = 0;

	public:
		engine::Vec3f GetPos() { return m_pos; }
		engine::Vec3f GetRote() { return m_rote; }
		engine::Vec3f GetScale() { return m_scale; }

		void SetPos(engine::Vec3f pos_) { m_pos = pos_; }
		void SetRote(engine::Vec3f rote_) { m_rote = rote_; }
		void SetScale(engine::Vec3f scale_) { m_scale = scale_; }

	protected:
		engine::Vec3f m_pos{};
		engine::Vec3f m_rote{};
		engine::Vec3f m_scale{ 1.0f, 1.0f, 1.0f };
	};
}

#endif // !OBJECT_BASE_H
