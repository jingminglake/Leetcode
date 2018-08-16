#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution{
public:
    UndirectedGraphNode *cloneGraph(struct UndirectedGraphNode *node) {
        if (!node)
            return nullptr;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        // clone nodes
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode *temp = q.front();
            UndirectedGraphNode *cloneNode = new UndirectedGraphNode(temp->label);
            m.insert(make_pair(temp, cloneNode));
            q.pop();
            for (UndirectedGraphNode* neighborNode : temp->neighbors) {
                if (m.find(neighborNode) == m.end())
                    q.push(neighborNode);
            }
        }
        // clone edges
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator it = m.begin();
        while (it != m.end()) {
            for (UndirectedGraphNode* n: it->first->neighbors) {
                it->second->neighbors.push_back(m[n]);
            }
            ++it;
        }
        return m[node];
    }
};

int main()
{
    Solution s;
    struct UndirectedGraphNode n0(0), n1(1), n2(2);
    n0.neighbors.push_back(&n1);
    n0.neighbors.push_back(&n2);
    n1.neighbors.push_back(&n0);
    n1.neighbors.push_back(&n2);
    n2.neighbors.push_back(&n1);
    n2.neighbors.push_back(&n0);
    n2.neighbors.push_back(&n2);
    UndirectedGraphNode *res = s.cloneGraph(&n0);
    return 0;
}
