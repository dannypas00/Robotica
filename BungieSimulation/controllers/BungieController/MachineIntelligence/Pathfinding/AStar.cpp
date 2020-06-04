#include "AStar.h"

#include <vector>
#include "Node.h"
using namespace std;

namespace bungie {
    static vector<Node> aStar(Node player, Node dest){
        vector<Node> empty;
        if (isDestination(player.pos.x, player.pos.y, dest)){
            cout << "Dest bereikt" << endl;
            return empty;
        }
        vector<Node> closedList;
        vector<Node> allMap;

        int x = player.pos.x;
        int y = player.pos.y;
        player.fCost = 0.0;
        player.hCost = 0.0;
        player.gCost = 0.0;
        player.parentPos = player.pos;

        vector<Node> openList;
        openList.emplace_back(player);
        bool destinationFound = false;

        while (!openList.empty() && openList.size() < allMap.size()){
            Node node;
            float temp = FLT_MAX;
            Node* itNode;
            for (Node it : openList) {
                Node *n = &it;
                if (n->fCost < temp) {
                    temp = n->fCost;
                    itNode = &it;
                }
            }
            node = *itNode;
            //openList.erase(*itNode);
        }
    }
}