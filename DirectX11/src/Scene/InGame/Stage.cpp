#include "Stage.h"

#include "../../Library/Library.h"

namespace Game
{
	enum class MapData
	{
		Street_Empty,	// ��
		Street_Deadend,	// �s���~�܂�
		Street_Curve,	// �J�[�u
		Street_4Way,	// �l�p
		Street_3Way,	// �O�p
		Street_Straight,	// ����
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

		m_stageSize.m_mapNumZ = 5;
		m_stageSize.m_mapNumX = 10;
	}

	void Stage::Draw()
	{
		for (int z = 0; z < m_stageSize.m_mapNumZ; z++)
		{
			for (int x = 0; x < m_stageSize.m_mapNumX; x++)
			{
				engine::Library::RenderObj(m_mapName.at((int)m_stageData[z][x]),
					engine::Vec3f(0 + 200 * x, -100, 0 + 200 * z), engine::Vec3f(0, 0, 0), engine::Vec3f(100, 100, 100));
			}
		}
	}
}