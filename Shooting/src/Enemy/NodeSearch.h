#ifndef NODE_SEARCH_H
#define NODE_SEARCH_H

#include "../Library/Library.h"
#include "NodeBase.h"
#include "EnemyBase.h"

namespace Game
{
	class NodeSearch : public NodeBase
	{
	public:
		NodeSearch() = default;
		~NodeSearch() = default;

	public:
		bool Exec(EnemyBase* enemy_base_);
	};
}

#endif // !NODE_SEARCH_H
