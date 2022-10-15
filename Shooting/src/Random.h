#ifndef Random
#define Random

#include <random>

namespace Game
{
	static std::default_random_engine gen;

	static int RandomNum(const int& low_, const int& high_)
	{
		std::uniform_int_distribution<> dist(low_, high_);
		return dist(gen);
	}
}

#endif // !Random
