#include "AStar.h"
#include <iostream>
#include <vector>
#include <stack>
#include "Node.h"
using namespace std;

namespace bungie {
    /// @brief Calculate the shortest path between player and dest by using the A* algorithm
    /// @param player The player's current node (or any starting node)
    /// @param dest The destination node to path to
    /// @param allMap A vector containing all traversible nodes
    /// @brief The shortest path from player to dest as calculated with A*
    /// @return vector<Node*>
    vector<Node*> AStar::aStar(Node* player, Node* dest, vector<Node*>* allMap){
        vector<Node*> empty;
        if (isDestination(player, dest)){
            cout << "Bereikt" << endl;
            return empty;
        }

        float x = player->pos.x;
        float y = player->pos.y;
        player->fCost = 0.0;
        player->hCost = 0.0;
        player->gCost = 0.0;
        player->parentPos = player->pos;
        player->parent = player;

        vector<Node*> openList;
        openList.emplace_back(player);
        bool destinationFound = false;

        while (!openList.empty() && openList.size() < allMap->size()){
            Node* node;
            float temp = INFINITY;
            //Iterator for-loop is because vector::erase() only works with an iterator, not with values
            vector<Node*>::iterator itNode;
            for (vector<Node*>::iterator it = openList.begin(); it != openList.end(); it = next(it)) {
                Node* n = *it;
                if (n->fCost < temp) {
                    temp = n->fCost;
                    itNode = it;
                }
            }
            node = *itNode;
            openList.erase(itNode);

            x = node->pos.x;
            y = node->pos.y;
            node->closed = true;

            for (Node* neighbour : node->neighbours) {
                //Calculate f, g, and h costs
                if (isDestination(neighbour, dest)) {
                    destinationFound = true;
                    dest->parent = node;
                    dest->parentPos = node->pos;
                    return AStar::makePath(allMap, dest);
                }
                else if (!neighbour->closed) {
                    double gNew = calculateG(neighbour, node);
                    double hNew = calculateH(neighbour, player);
                    double fNew = calculateF(hNew, gNew);
                    if (neighbour->fCost == INFINITY || neighbour->fCost > fNew) {
                        neighbour->fCost = fNew;
                        neighbour->gCost = gNew;
                        neighbour->hCost = hNew;
                        neighbour->parentPos = node->pos;
                        neighbour->parent = node;
                        openList.emplace_back(neighbour);
                    }
                }
            }
        }
        cout << "Destination not found!" << endl;
        return empty;
    }

    /// @brief Generate the quickest path to destination
    /// @param map Vector of all traversible nodes
    /// @param dest Destination node
    /// @brief Shortest path to destination as calculated by A*
    /// @return vector<Node*>
    vector<Node*> AStar::makePath(vector<Node*>* map, Node* dest) {
        try {
            cout << "Found a path" << endl;
            stack<Node*> path;
            vector<Node*> usablePath;
            Node* temp = dest;
            //Loop through the entire map from the end until the start is reached
            while (temp != temp->parent && temp->parent != nullptr) {
                path.push(temp);
                temp = temp->parent;
            }
            
            //Move from stack to vector and invert path
            while (!path.empty()) {
                Node* top = path.top();
                path.pop();
                usablePath.emplace_back(top);
            }
            return usablePath;
        }
        catch (const exception& e) {    
            cout << e.what() << endl;
        }
    }
}