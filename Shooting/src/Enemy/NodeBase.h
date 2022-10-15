#ifndef NODE_BASE_H
#define NODE_BASE_H

namespace Game
{
	class NodeBase
	{
	public:
		NodeBase() = default;
		~NodeBase() = default;

	public:
		virtual bool Exec() = 0;
	};
}

#endif // !NODE_BASE_H
