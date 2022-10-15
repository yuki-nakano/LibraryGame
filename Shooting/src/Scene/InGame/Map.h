#ifndef MAP_H
#define MAP_H

#include "../../Library/Library.h"

namespace Game
{
	class Map
	{
	public:
		struct mapData
		{
			engine::Vec3f pos{};

		};

	public:
		Map() = default;
		~Map() = default;

	public:
		void Update();
		void Draw();

		void RegisterPos();
	};
}

#endif // !MAP_H
