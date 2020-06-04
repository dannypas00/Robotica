#ifndef NODE
#define NODE

#include "Vector3.h"
#include <cmath>

namespace bungie {
    struct Node
    {
        Vector3 pos;
        Vector3 parentPos;
        vector<Node&> neighbors;
        //Distance between current node and start node
        float gCost;
        //Distance from current node to end node
        float hCost; 
        //Total cost of node
        float fCost;
    };

    inline bool operator < (const Node& lhs, const Node& rhs)
    {//We need to overload "<" to put our struct into a set
        return lhs.fCost < rhs.fCost;
    }

    static bool isDestination(double x, double y, Node dest) {
        if (x == dest.pos.x && y == dest.pos.y) {
            return true;
        }
        return false;
    }

    static double calculateF(float hCost, float gCost) {
        return hCost + gCost;
    }

    static double calculateG(Vector3 current, Node start) {
        return abs(current.distancePoints(current, start.pos));
    }

    static double calculateH(Vector3 current, Node dest) {
        return abs(current.distancePoints(current, dest.pos));
    }
}

#endif