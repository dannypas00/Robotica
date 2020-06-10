#ifndef NODE
#define NODE

#include "..\Vector3.h"
#include <vector>
#include <cmath>
#include <sstream>

namespace bungie {
    struct Node
    {
        Vector3 pos;
        Vector3 parentPos;
        Node* parent;
        std::vector<Node*> neighbours;
        //Distance between current node and start node
        float gCost;
        //Distance from current node to end node
        float hCost; 
        //Total cost of node
        float fCost = INFINITY;
        bool closed = false;
    };

    //Return displayable string of coordinates
    static std::string ToString(Node* n)
    {
        std::ostringstream strs;
        strs << n->pos.x;
        std::string x = strs.str();
        std::ostringstream strs2;
        strs2 << n->pos.y;
        std::string y = strs2.str();
        return "[" + x + ", " + y + "]";
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