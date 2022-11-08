#ifndef RESULT_H
#define RESULT_H

#include "../../Enemy/EnemyManager.h"

namespace Game
{
	class Result
	{
	public:
		Result(EnemyManager* enmy_manager_);
		~Result();

	public:
		bool Exec();
		void Draw();

		void ConvertIsAlive();

	private:
		EnemyManager* m_enmy{};

		/// リザルトを表示するか
		bool m_isAlive{ false };
	};
}

#endif // !RESULT_H
