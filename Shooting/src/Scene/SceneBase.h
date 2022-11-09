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
		SceneBase() = default;
		virtual ~SceneBase() = default;

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
		* @brief シーン終了判定関数
		*/
		bool IsEnd()
		{
			return m_isNextScene;
		}

		Scene GetNextScene() const { return nextScene; };

	protected:
		/// 次のシーン
		Scene nextScene{};

		/// シーンを終了するか
		bool m_isNextScene{ false };
	};
}

#endif // !SCENE_BASE_H
