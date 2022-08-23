#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "SceneBase.h"

namespace Game
{
	class TitleScene : public SceneBase
	{
	public:
		TitleScene();
		~TitleScene();

	public:
		void Exec();

		void Draw();

		bool IsEnd();
	};
}

#endif // !TITLE_SCENE_H