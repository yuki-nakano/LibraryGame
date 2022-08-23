#ifndef STAGE_H
#define STAGE_H

#include <string>
#include <array>

namespace Game
{
	class Stage
	{
	public:
		struct StageSize
		{
			float m_stage;
			float m_stageRad;
			float m_mapNumX;
			float m_mapNumZ;
		};

		enum class MapData
		{
			Street_Empty,	// ‹ó”’
			Street_Straight,	// ’¼ü
			Street_Deadend,	// s‚«~‚Ü‚è
		};

	public:
		Stage();
		~Stage() = default;

	public:
		void Draw();

		//StageSize GetStageData() { return m_stageDate; }

	private:
		StageSize m_stageSize{};
		int m_stageData[5][10] =
		{
			{0,0,0,0,0,0,0,0,0,0},
			{1,1,1,1,1,1,1,1,1,1},
			{0,0,0,0,0,0,0,0,0,0},
			{1,1,1,1,1,1,1,1,1,1},
			{0,0,0,0,0,0,0,0,0,0},
		};
		std::array<std::string, 6> m_mapName{};
	};
}

#endif // !STAGE_H
