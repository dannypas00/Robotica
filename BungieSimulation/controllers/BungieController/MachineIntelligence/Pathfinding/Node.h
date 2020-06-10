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

    /// @brief Return a printable string of the node's coordinates
    /// @param n Node of which to return coordinates
    /// @brief String of coordinates in format [x, y]
    /// @return string
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

    /// @brief Determine whether the given position is the destinatio
    /// @param current Node to check
    /// @param targetNode Destination node
    /// @brief Whether the given node is the target node
    /// @return bool
    static bool isDestination(Node* current, Node* targetNode) {
        return current == targetNode;
    }

    /// @brief Calculate the F cost of the current node
    /// @param hCost HCost of the node
    /// @param gCost GCost of the node
    /// @brief Returns the sum of hCost and gCost
    /// @return double
    static double calculateF(float hCost, float gCost) {
        return hCost + gCost;
    }

    /// @brief Calculate the G cost of the current node
    /// @param current Node of which to calculate the G cost
    /// @param targetNode Previous node in path
    /// @brief Positive distance over path between current and start
    /// @return double
    static double calculateG(Node* current, Node* targetNode) {
        return abs(current->pos.distancePoints(current->pos, targetNode->pos) + current->gCost);
    }

    /// @brief Calculate the H cost of the current node
    /// @param current Node of which to calculate the H cost
    /// @param targetNode Destination node of path
    /// @brief Positive distance between current and targetNode
    /// @return double
    static double calculateH(Node* current, Node* targetNode) {
        return abs(current->pos.distancePoints(current->pos, targetNode->pos));
    }
}

#endif