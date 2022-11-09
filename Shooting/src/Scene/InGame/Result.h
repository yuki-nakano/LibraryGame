#ifndef RESULT_H
#define RESULT_H

#include "../../Enemy/EnemyManager.h"

namespace Game
{
	/**
	* @brief リザルト画面
	*/
	class Result
	{
	public:
		Result(EnemyManager* enmy_manager_);
		~Result();

	public:
		/**
		* @brief 実行関数
		* @return 実行中はtrue
		*/
		bool Exec();

		/**
		* @brief 描画関数
		*/
		void Draw();

		/**
		* @brief リザルト切り替え関数
		*/
		void ConvertIsAlive();

	private:
		/// エネミー
		EnemyManager* m_enmy{};

		/// リザルトを表示するか
		bool m_isAlive{ false };
	};
}

#endif // !RESULT_H
