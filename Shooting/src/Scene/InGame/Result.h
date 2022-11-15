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
		* @brief 描画関数
		*/
		void Draw();

		/**
		* @brief リザルト切り替え関数
		*/
		void ConvertIsAlive();

	private:
		/// エネミー
		EnemyManager* m_enmyManager{};

		/// リザルトを表示するか
		bool m_isAlive{ false };
	};
}

#endif // !RESULT_H
