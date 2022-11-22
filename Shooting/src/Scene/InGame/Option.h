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
		* @brief 描画関数
		*/
		void Draw();

		/**
		* @brief リザルト切り替え関数
		*/
		void ConvertIsAlive();

	private:
		/// オプションを表示するか
		bool m_isAlive{ false };
	};
}

#endif // !OPTION_H
