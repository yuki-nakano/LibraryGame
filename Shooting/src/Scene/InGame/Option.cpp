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
	}
}