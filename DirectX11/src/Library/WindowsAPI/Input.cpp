#include "Input.h"

#include <Windows.h>

namespace engine
{
	void InputManager::UpdateKeyState()
	{
		for (auto key : m_keyState)
		{
			int keyStateResult = GetAsyncKeyState(key.first);

			if (keyStateResult & 1)
			{
				m_keyState.at(key.first) = KeyState::Pushed;
			}
			else if (keyStateResult & 0x80000000)
			{
				m_keyState.at(key.first) = KeyState::Held;
			}
			else
			{
				if (m_keyState.at(key.first) == KeyState::Not)
				{
					continue;
				}
				else if (m_keyState.at(key.first) == KeyState::Relesed)
				{
					m_keyState.at(key.first) = KeyState::Not;
				}
				else
				{
					m_keyState.at(key.first) = KeyState::Relesed;
				}
			}
		}
	}

	void InputManager::RegisterKey(std::vector<int> key_list_)
	{
		for (auto key : key_list_)
		{
			m_keyState[key] = KeyState::Not;
		}
	}

	bool InputManager::IsHeldKey(int key_)
	{
		if (m_keyState.at(key_) == KeyState::Held) { return true; }

		return false;
	}

	bool InputManager::IsPushedKey(int key_)
	{
		if (m_keyState.at(key_) == KeyState::Pushed) { return true; }

		return false;
	}

	bool InputManager::IsRelesedKey(int key_)
	{
		if (m_keyState.at(key_) == KeyState::Relesed) { return true; }

		return false;
	}

	KeyState InputManager::GetKeyState(int key_)
	{
		return m_keyState.at(key_);
	}
}
