#ifndef STAGE_H
#define STAGE_H

#include "../../Library/Library.h"

#include <string>
#include <array>
#include <vector>

namespace Game
{
	class Player;

	class Stage
	{
	public:
		struct StageSize
		{
			float stageRight{ 0.0f };
			float stageLeft{ 1000.0f };
			float stageFront{ 4000.0f };
			float stageBack{ 0.0f };
			float stageUp{ 300.0f };
			float stageDown{ 10.0f };
			int mapNumZ{ 5 };
			int mapNumX{ 20 };
		};

		enum class MapData
		{
			Street_Empty,	// ãÛîí
			Street_Straight,	// íºê¸
		};

	public:
		Stage();
		~Stage() = default;

	public:
		void Update(Player* player_);

		void Draw();

		StageSize GetStageData() { return m_stageSize; }

	private:
		StageSize m_stageSize{};
		std::vector<std::vector<int>> m_stageData{};
		std::array<std::string, 6> m_mapName{};

		engine::Vec2f m_bgPos1{};
		engine::Vec2f m_bgPos2{};
	};
}

#endif // !STAGE_H
