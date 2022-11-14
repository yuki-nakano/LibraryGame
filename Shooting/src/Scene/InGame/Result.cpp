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
		engine::Library::LoadTexture(L"res/InGame/enemy.png", "EnemyTex");
		engine::Library::LoadTexture(L"res/InGame/button.png", "ResultButton");
	}

	Result::~Result()
	{
		for (int i = 0; i <= 9; i++)
		{
			engine::Library::ReleaseTexture(std::to_string(i));
		}

		engine::Library::ReleaseTexture("Result");
		engine::Library::ReleaseTexture("EnemyTex");
		engine::Library::ReleaseTexture("ResultButton");

	}

	void Result::Draw()
	{
		if (!m_isAlive) { return; }

		// 画面サイズ 1080 * 720
		engine::Library::DrawRect(engine::Vec2f(0.0f, 0.0f), 1080, 720, engine::Vec3f(1.0f, 1.0f, 1.0f), 0.5f);

		// 画像サイズ 827 * 146
		engine::Library::DrawTexture("Result", engine::Vec2f(126.5f, 100.0f), 827.0f, 146.0f);

		// 画像サイズ 200 * 200
		// 画面左側に表示
		engine::Library::DrawTexture("EnemyTex", engine::Vec2f(320.0f, 300.0f), 200.0f, 200.0f);

		// 画面中央に表示
		engine::Library::DrawTextData(L"×", engine::Vec2f(540.0f, 400.0f));

		int enemyNum = m_enmy->GetDeadEnemyNum();

		// 画像サイズ 100 * 100
		// 百の位 
		engine::Library::DrawTexture(std::to_string(enemyNum / 100), engine::Vec2f(600.0f, 375.0f), 100.0f, 100.0f);

		// 画像サイズ 100 * 100
		// 十の位
		engine::Library::DrawTexture(std::to_string(enemyNum / 10 % 10), engine::Vec2f(700.0f, 375.0f), 100.0f, 100.0f);

		// 画像サイズ 100 * 100
		// 一の位
		engine::Library::DrawTexture(std::to_string(enemyNum % 10), engine::Vec2f(800.0f, 375.0f), 100.0f, 100.0f);

		// 画像サイズ 802 * 98
		// 画面下側に表示
		engine::Library::DrawTexture("ResultButton", engine::Vec2f(139.0f, 600.0f), 802.0f, 98.0f);

	}

	void Result::ConvertIsAlive()
	{
		m_isAlive ? m_isAlive = false : m_isAlive = true;
	}
}