#ifndef Random
#define Random

#include <random>

namespace Game
{
	static std::default_random_engine gen;

	/**
	* @brief 乱数取得関数
	* @param low_ 最低値
	* @param high_ 最高値
	*/
	static int RandomNum(const int& low_, const int& high_)
	{
		std::uniform_int_distribution<> dist(low_, high_);
		return dist(gen);
	}
}

#endif // !Random
