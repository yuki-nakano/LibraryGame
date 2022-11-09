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
		Option();
		~Option();

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

	private:
		/// オプションを表示するか
		bool m_isAlive{ false };
	};
}

#endif // !OPTION_H
