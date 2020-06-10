#include "PathfindingStrategy.h"
#include <iostream>

namespace bungie {
PathfindingStrategy::PathfindingStrategy() {
}

int PathfindingStrategy::ExecuteStrategy()
{
	//Initialize new map vector and fill it with placeholder Nodes
	std::vector<Node*> map = std::vector<Node*>();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Node* n = new Node();
			n->pos = Vector3(i, j, 0);
			map.emplace_back(n);
		}
	}
	//Set the neighbors for all Nodes to the next and previous ones in the list
	for (int i = 1; i < map.size(); i++)
	{
		map[i]->neighbours.emplace_back(map[i - 1]);
		map[i - 1]->neighbours.emplace_back(map[i]);
	}
	//Execute AStar algorithm on map
	vector<Node*> path = AStar::aStar(map.front(), map.back(), &map);
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