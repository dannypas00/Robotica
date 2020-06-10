#include "PathfindingStrategy.h"
#include <iostream>

namespace bungie {
PathfindingStrategy::PathfindingStrategy() {
}

int PathfindingStrategy::ExecuteStrategy()
{
	for(int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Node n = Node();
			n.pos = Vector3(i, j, 0);
			n.neighbours.emplace_back(*map.end());
			///*map.end()->neighbours.emplace_back(*n);
			map.emplace_back(&n);
		}
	}
	AStar::aStar(*map.begin(), *map.end(), &map);
	return 0;
}
}