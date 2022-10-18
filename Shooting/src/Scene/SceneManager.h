#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "SceneBase.h"

namespace Game
{
	/**
	* @brief シーン管理クラス
	*/
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager() = default;

	public:
		/**
		* @brief シーン更新
		*/
		void Update();

		/**
		* @brief シーン遷移
		*/
		void ChangeScene();

	private:
		/// 現在のシーン
		SceneBase* m_currentScene{ nullptr };
	};
}

#endif // !SCENE_MANAGER_H
