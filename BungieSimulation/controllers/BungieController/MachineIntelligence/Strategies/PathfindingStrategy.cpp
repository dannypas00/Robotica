#include "PathfindingStrategy.h"
#include <iostream>

namespace bungie {
PathfindingStrategy::PathfindingStrategy() {
}

int PathfindingStrategy::ExecuteStrategy()
{
	std::vector<Node*> map = std::vector<Node*>();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Node* n = new Node();
			n->pos = Vector3(i, j, 0);
			map.emplace_back(n);
		}
	}
	for (int i = 1; i < map.size(); i++)
	{
		map[i]->neighbours.emplace_back(map[i - 1]);
		map[i - 1]->neighbours.emplace_back(map[i]);
	}
	Node* front = map.front();
	Node* back = map.back();
	vector<Node*> path = AStar::aStar(front, back, &map);
	std::cout << path.size() << std::endl;
	for (Node* n : path)
	{
		std::cout << ToString(n) << std::endl;
	}
	for (Node* n : map)
	{
		delete n;
	}
	return 0;
}
}