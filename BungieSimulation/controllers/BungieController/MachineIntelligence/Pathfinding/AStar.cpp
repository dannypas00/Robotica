#include "AStar.h"

#include <vector>
#include <stack>
#include "Node.h"
using namespace std;

namespace bungie {
    vector<Node*> AStar::aStar(Node* player, Node* dest, vector<Node*>* allMap){
        vector<Node*> empty;
        if (isDestination(player->pos, dest)){
            cout << "Bereikt" << endl;
            return empty;
        }
        vector<Node*> closedList;

        float x = player->pos.x;
        float y = player->pos.y;
        player->fCost = 0.0;
        player->hCost = 0.0;
        player->gCost = 0.0;
        player->parentPos = player->pos;

        vector<Node*> openList;
        openList.emplace_back(player);
        bool destinationFound = false;

        while (!openList.empty() && openList.size() < allMap->size()){
            Node* node;
            float temp = INFINITY;
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
            closedList.emplace_back(node);
            node->closed = true;

            for (Node* neighbour : node->neighbours) {
                //Calculate f, g, and h costs
                
                if (isDestination(neighbour->pos, dest)) {
                    destinationFound = true;
                    return AStar::makePath(allMap, dest);
                }
                else if (neighbour->closed) {
                    double gNew = calculateG(neighbour, node);
                    double hNew = calculateH(neighbour->pos, player);
                    double fNew = calculateF(neighbour->hCost, neighbour->gCost);
                    if (neighbour->fCost == INFINITY || neighbour->fCost > fNew) {
                        neighbour->fCost = fNew;
                        neighbour->gCost = gNew;
                        neighbour->hCost = hNew;
                        neighbour->parentPos = node->pos;
                        openList.emplace_back(neighbour);
                    }
                }
            }
        }
        cout << "Destination not found!" << endl;
        return empty;
    }

    vector<Node*> AStar::makePath(vector<Node*>* map, Node* dest) {
        try {
            cout << "Found a path" << endl;
            Vector3& pos = dest->pos;
            stack<Node*> path;
            vector<Node*> usablePath;

            for(Node* temp : *map) {
                if (temp->pos == temp->parentPos) break;
                path.push(temp);
            }
            
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
        return vector<Node*>();
    }
}