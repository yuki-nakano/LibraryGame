#ifndef SCENE_BASE_H
#define SCENE_BASE_H

namespace Game
{
	/// シーンの種類
	enum class Scene
	{
		Title,
		InGame,
		None,
	};

	/**
	* @brief シーン継承元
	*/
	class SceneBase
	{
	public:
		SceneBase() {};
		virtual ~SceneBase() {};

	public:
		/**
		* @brief 実行関数
		*/
		virtual void Exec() = 0;

		/**
		* @brief 描画関数
		*/
		virtual void Draw() = 0;

		/**
		* @brief シーン終了
		*/
		virtual bool IsEnd() = 0;

		Scene GetNextScene() const { return nextScene; };

	protected:
		Scene nextScene{};
	};
}

#endif // !SCENE_BASE_H
