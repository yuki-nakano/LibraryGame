#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "SceneBase.h"

namespace Game
{
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager() = default;

	public:
		void Update();

		void ChangeScene();

	private:
		SceneBase* m_currentScene{ nullptr };
	};
}

#endif // !SCENE_MANAGER_H
