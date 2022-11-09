#include "Option.h"

#include "../../Library/Library.h"

namespace Game
{
	Option::Option()
	{
		engine::Library::LoadTexture(L"res/InGame/pause.png", "pause");
	}

	Option::~Option()
	{
		engine::Library::ReleaseTexture("pause");
	}

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

		// 画面サイズ 1080 * 720
		engine::Library::DrawRect(engine::Vec2f(0.0f, 0.0f), 1080, 720, engine::Vec3f(1.0f, 1.0f, 1.0f), 0.5f);

		engine::Library::DrawTexture("pause", engine::Vec2f(270, 260), 500, 200);
	}
}