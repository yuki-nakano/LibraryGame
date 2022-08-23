#ifndef SCENE_BASE_H
#define SCENE_BASE_H

namespace Game
{
	enum class Scene
	{
		Title,
		InGame,
		Result,
		none,
	};

	class SceneBase
	{
	public:
		SceneBase() {};
		virtual ~SceneBase() {};

	public:
		virtual void Exec() = 0;

		virtual void Draw() = 0;

		virtual bool IsEnd() = 0;

		Scene GetNextScene() const { return nextScene; };

	protected:
		Scene nextScene{};
	};
}

#endif // !SCENE_BASE_H
