#include "Stage.h"

#include "../../Library/Library.h"
#include "Player.h"

namespace Game
{
	enum class MapData
	{
		Street_Empty,	// 空白
		Street_Deadend,	// 行き止まり
		Street_Curve,	// カーブ
		Street_4Way,	// 四角
		Street_3Way,	// 三角
		Street_Straight,	// 直線
	};

	Stage::Stage()
	{
		m_mapName.at(0) = "Street_Empty";
		m_mapName.at(1) = "Street_Straight";
		m_mapName.at(2) = "Street_Deadend";

		std::string filePass{ "res/stage/" };

		for (auto mapName : m_mapName)
		{
			std::string fileName = filePass + mapName + ".obj";
			engine::Library::LoadObj(fileName, mapName);
		}

		engine::Library::LoadTexture(L"res/stage/sky.png", "sky");

		for (int z = 0; z <= m_stageSize.mapNumZ; z++)
		{
			m_stageData.emplace_back();

			for (int x = 0; x <= m_stageSize.mapNumX; x++)
			{
				m_stageData[z].push_back(z % 2);
			}
		}
	}

	Stage::~Stage()
	{
		for (int i = 0; i < 3; i++)
		{
			engine::Library::ReleseObj(m_mapName.at(i));
		}

		engine::Library::ReleseTexture("sky");
	}

	void Stage::Update(Player* player_)
	{
		if (engine::Library::IsHeldKey(KEY_A))
		{
			m_bgPos1.x -= 0.5f * player_->GetSpeed();
			m_bgPos2.x -= 0.5f * player_->GetSpeed();

			if (m_bgPos1.x < -3840 + 1080)
			{
				m_bgPos2.x = m_bgPos1.x + 1080;
			}
			else if (m_bgPos1.x < -3840)
			{
				m_bgPos1.x = 0;
			}
		}

		// 右移動
		if (engine::Library::IsHeldKey(KEY_D))
		{
			m_bgPos1.x += 0.5f * player_->GetSpeed();
			m_bgPos2.x += 0.5f * player_->GetSpeed();

			if (m_bgPos1.x > 0)
			{
				m_bgPos2.x = m_bgPos1.x - 3840;
			}
			else if (m_bgPos1.x > 1080)
			{
				m_bgPos1.x = 0;
			}
		}
	}

	void Stage::Draw()
	{
		engine::Library::DrawTexture("sky", m_bgPos2, 3840, 720);
		engine::Library::DrawTexture("sky", m_bgPos1, 3840, 720);

		for (int z = 0; z <= m_stageSize.mapNumZ; z++)
		{
			for (int x = 0; x <= m_stageSize.mapNumX; x++)
			{
				engine::Library::RenderObj(m_mapName.at(m_stageData[z][x]),
					engine::Vec3f(0 + 200 * x, -100, 0 + 200 * z), engine::Vec3f(0, 0, 0), engine::Vec3f(100, 100, 100));
			}
		}
	}
}