#ifndef ASTAR
#define ASTAR
#include <vector>
#include <stack>
#include "Node.h"
using namespace std;

namespace bungie {
class AStar {
    public:
        static vector<Node*> aStar(Node* player, Node* dest, vector<Node*>* allMap);
        static vector<Node*> makePath(vector<Node*>* map, Node* dest);
};
}

#endif