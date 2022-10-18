#ifndef OPTION_H
#define OPTION_H

namespace Game
{
	/**
	* @brief ゲーム中の一時停止
	*/
	class Option
	{
	public:
		Option() = default;
		~Option() = default;

	public:
		bool Exec();
		void Draw();

	private:
		/// オプションを表示するか
		bool m_isAlive{ false };
	};
}

#endif // !OPTION_H
