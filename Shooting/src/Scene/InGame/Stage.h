#ifndef STAGE_H
#define STAGE_H

#include "../../Library/Library.h"

#include <string>
#include <array>
#include <vector>

namespace Game
{
	class Player;

	/**
	* @brief ステージ情報
	*/
	class Stage
	{
	public:
		/**
		* @brief ステージサイズ
		*/
		struct StageSize
		{
			float stageRight{ 0.0f };
			float stageLeft{ 1000.0f };
			float stageFront{ 4000.0f };
			float stageBack{ 0.0f };
			float stageUp{ 300.0f };
			float stageDown{ 20.0f };
			int mapNumZ{ 5 };
			int mapNumX{ 20 };
		};

		/// マップチップ
		enum class MapData
		{
			Street_Empty,		// 空白
			Street_Straight,	// 直線
		};

	public:
		Stage();
		~Stage();

	public:
		/**
		* @brief 更新関数
		*/
		void Update();

		/**
		* @brief 描画関数
		*/
		void Draw();

		// アクセサ

		StageSize GetStageData() { return m_stageSize; }

	private:
		StageSize m_stageSize{};
		std::vector<std::vector<int>> m_stageData{};	/// ステージデータ
		std::array<std::string, 6> m_mapName{};			/// マップチップデータ


		engine::Vec2f m_bgPos1{};	/// 背景用座標1
		engine::Vec2f m_bgPos2{};	/// 背景用座標2
	};
}

#endif // !STAGE_H
