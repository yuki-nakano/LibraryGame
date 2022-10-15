#ifndef OPTION_H
#define OPTION_H

namespace Game
{
	class Option
	{
	public:
		Option() = default;
		~Option() = default;

	public:
		bool Exec();
		void Draw();


	private:
		bool m_isAlive{ false };
	};
}

#endif // !OPTION_H
