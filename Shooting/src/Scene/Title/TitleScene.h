#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "../SceneBase.h"

namespace Game
{
	/**
	* @brief タイトルクラス
	*/
	class TitleScene : public SceneBase
	{
	public:
		TitleScene();
		~TitleScene();

	public:
		/**
		* @brief 実行関数
		*/
		void Exec();

		/**
		* @brief 描画関数
		*/
		void Draw();
	};
}

#endif // !TITLE_SCENE_H
