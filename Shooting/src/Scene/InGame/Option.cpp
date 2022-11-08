#include "Option.h"

#include "../../Library/Library.h"

namespace Game
{
	bool Option::Exec()
	{
		if (engine::Library::IsPushedKey(KEY_ESC))
		{
			if (m_isAlive)
			{
				m_isAlive = false;
				ShowCursor(FALSE);
			}
			else
			{
				m_isAlive = true;
				ShowCursor(TRUE);
			}
		}

		return m_isAlive;
	}

	void Option::Draw()
	{
		if (!m_isAlive) { return; }

		engine::Library::DrawRect(engine::Vec2f(0.0f, 0.0f), 1080, 920, engine::Vec3f(1.0f, 1.0f, 1.0f), 0.5f);
	}
}