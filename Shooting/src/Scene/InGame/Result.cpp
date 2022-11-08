#include "Result.h"

#include "../../Library/Library.h"

#include <sstream>
#include <iomanip>
#include <fstream>

namespace Game
{
	Result::Result(EnemyManager* enmy_manager_)
		:m_enmy(enmy_manager_)
	{
		std::wstring filePass{ L"res/InGame/number/" };

		for (int i = 0; i <= 9; i++)
		{
			std::wstring num = filePass + std::to_wstring(i) + L".png";

			engine::Library::LoadTexture(num, std::to_string(i));
		}

		engine::Library::LoadTexture(L"res/InGame/Result.png", "Result");
		engine::Library::LoadTexture(L"res/InGame/Enemy.png", "EnemyTex");
	}

	Result::~Result()
	{
		for (int i = 0; i <= 9; i++)
		{
			engine::Library::ReleseTexture(std::to_string(i));
		}

		engine::Library::ReleseTexture("Result");
		engine::Library::ReleseTexture("EnemyTex");
	}

	bool Result::Exec()
	{
		return m_isAlive;
	}

	void Result::Draw()
	{
		if (!m_isAlive) { return; }

		engine::Library::DrawRect(engine::Vec2f(0.0f, 0.0f), 1080, 920, engine::Vec3f(1.0f, 1.0f, 1.0f), 0.5f);
		engine::Library::DrawTexture("Result", engine::Vec2f(126.5f, 100.0f), 827.0f, 146.0f);
		engine::Library::DrawTexture("EnemyTex", engine::Vec2f(320.0f, 300.0f), 200.0f, 200.0f);
		engine::Library::DrawTextData(L"~", engine::Vec2f(540.0f, 400.0f));

		int enemyNum = m_enmy->GetDeadEnemyNum();

		engine::Library::DrawTexture(std::to_string(enemyNum / 100), engine::Vec2f(600.0f, 375.0f), 100.0f, 100.0f);
		engine::Library::DrawTexture(std::to_string(enemyNum / 10 % 10), engine::Vec2f(700.0f, 375.0f), 100.0f, 100.0f);
		engine::Library::DrawTexture(std::to_string(enemyNum % 10), engine::Vec2f(800.0f, 375.0f), 100.0f, 100.0f);
	}

	void Result::ConvertIsAlive()
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
}