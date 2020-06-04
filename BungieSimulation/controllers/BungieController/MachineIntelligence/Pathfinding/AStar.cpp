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
            vector<Node>::iterator itNode;
            for (vector<Node>::iterator it = openList.begin(); it != openList.end(); it = next(it)) {
                Node n = *it;
                if (n.fCost < temp) {
                    temp = n.fCost;
                    itNode = it;
                }
            }
            node = *itNode;
            openList.erase(itNode);

            x = node.pos.x;
            y = node.pos.y;
            closedList.emplace_back(node);

            for (Node& neighbor : node.neighbors) {
                //Calculate f, g, and h costs
            }
        }
    }
}