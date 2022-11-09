#ifndef NODE_BASE_H
#define NODE_BASE_H

namespace Game
{
	// ビヘービア
	class NodeBase
	{
	public:
		NodeBase() = default;
		virtual ~NodeBase() = default;

	public:
		/**
		* @brief 実行関数
		*/
		virtual bool Exec() = 0;
	};
}

#endif // !NODE_BASE_H
