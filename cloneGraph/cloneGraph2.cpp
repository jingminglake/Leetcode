#include <iostream>
#include <vector>
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
      return node;
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
    cloneGraphHelper(node, m);
    for (auto& p : m) {
      for (UndirectedGraphNode* n : p.first->neighbors) {
	p.second->neighbors.push_back(m[n]);
      }
    }
    return m[node];
  }
  void cloneGraphHelper(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& m) {
    UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
    m[node] = newNode;
    for (UndirectedGraphNode* neighor_node : node->neighbors) {
      if (m.count(neighor_node))
	continue;
      cloneGraphHelper(neighor_node, m);
    }
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
