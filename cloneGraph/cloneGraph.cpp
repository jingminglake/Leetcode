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
      return NULL;
    UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
    unordered_map<int, struct UndirectedGraphNode *> m;
    m.insert(make_pair(newNode->label, newNode));
    queue<UndirectedGraphNode*> q;
    q.push(node);
    while (!q.empty()) {
      UndirectedGraphNode *n = q.front();
      q.pop();
      for (UndirectedGraphNode *neighbor : n->neighbors) {
	if (m.find(neighbor->label) == m.end()) {
	  m.insert(make_pair(neighbor->label, new UndirectedGraphNode(neighbor->label)));
	  q.push(neighbor);
	}
	m[n->label]->neighbors.push_back(m[neighbor->label]);
      }
    }//while
    return newNode;
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
