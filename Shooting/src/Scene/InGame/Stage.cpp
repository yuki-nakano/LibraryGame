#include "Stage.h"

#include "../../Library/Library.h"
#include "Player.h"

namespace Game
{
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

		engine::Library::ReleaseTexture("sky");
	}

	void Stage::Update()
	{
		m_bgPos1.x += (engine::Library::GetMousePosX() - GetSystemMetrics(SM_CXSCREEN) / 2) * 0.01f;
		m_bgPos2.x += (engine::Library::GetMousePosX() - GetSystemMetrics(SM_CXSCREEN) / 2) * 0.01f;
		// 背景画像サイズ　3840 * 1080
		if (m_bgPos1.x > 0)
		{
			m_bgPos2.x = m_bgPos1.x - 3840;
		}
		else if (m_bgPos1.x > 1080)
		{
			m_bgPos1.x = 0;
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
				// objサイズ 200 * 200
				engine::Library::RenderObj(m_mapName.at(m_stageData[z][x]),
					engine::Vec3f(0.0f + 200.0f * x, 0.0f, 0.0f + 200.0f * z), engine::Vec3f(0, 0, 0), engine::Vec3f(100, 100, 100));
			}
		}
	}
}