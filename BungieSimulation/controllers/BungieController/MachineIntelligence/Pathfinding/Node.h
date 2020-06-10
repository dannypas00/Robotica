#ifndef NODE
#define NODE

#include "../Vector3.h"
#include <vector>
#include <cmath>

namespace bungie {
    struct Node
    {
        Vector3 pos;
        Vector3 parentPos;
        std::vector<Node*> neighbours;
        //Distance between current node and start node
        float gCost;
        //Distance from current node to end node
        float hCost; 
        //Total cost of node
        float fCost;
        bool closed = false;
    };

    inline bool operator < (const Node& lhs, const Node& rhs)
    {//We need to overload "<" to put our struct into a set
        return lhs.fCost < rhs.fCost;
    }

    static bool isDestination(Vector3 pos, Node* targetNode) {
        if (pos == targetNode->pos) {
            return true;
        }
        return false;
    }

    static double calculateF(float hCost, float gCost) {
        return hCost + gCost;
    }

    static double calculateG(Node* neighbour, Node* target) {
        return abs(neighbour->pos.distancePoints(neighbour->pos, target->pos) + neighbour->gCost);
    }

    static double calculateH(Vector3 current, Node* targetNode) {
        return abs(current.distancePoints(current, targetNode->pos));
    }
}

#endif