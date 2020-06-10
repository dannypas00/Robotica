#ifndef PATHFINDING_STRATEGY
#define PATHFINDING_STRATEGY
#include <vector>
#include "..\MIStrategy.h"
#include "..\Pathfinding\Node.h"
#include "..\Pathfinding\AStar.h"

namespace bungie {
class PathfindingStrategy : public MIStrategy {
public:
	PathfindingStrategy();

	int ExecuteStrategy() override;
private:
	std::vector<Node*> map = std::vector<Node*>();
};
}

#endif