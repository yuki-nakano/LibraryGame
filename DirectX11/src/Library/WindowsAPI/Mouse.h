#ifndef MOUSUE_H

#include <Windows.h>

#include "../Utility/Singleton.h"

namespace engine
{
	class Mouse : public Singleton<Mouse>
	{
	private:
		friend class Singleton<Mouse>;

		Mouse() {};
		~Mouse() {};

	public:
		/**
		* @brief マウス情報の更新
		*/
		void Update();

		long GetPosX() { return screenPos.x; }
		long GetPosY() { return screenPos.y; }

	private:
		POINT screenPos{};
		POINT clientPos{};


	};
}
#endif // !MOUSUE_H
