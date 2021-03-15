#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        unordered_map<Node*, Node*> m;
        queue<Node*> q;
        q.push(node);
        m[node] = new Node(node->val);
        
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            for (Node* n : cur->neighbors) {
                if (m.count(n)) continue;
                q.push(n);
                m[n] = new Node(n->val);
            }
        }
        
        for (auto& p : m) {
            Node* n = p.first;
            Node* nn = p.second;
            for (Node* neighbor : n->neighbors) {
                nn->neighbors.push_back(m[neighbor]);
            }
        }
        return m[node];
    }
};

int main()
{
    Solution s;
    Node n0(0), n1(1), n2(2);
    n0.neighbors.push_back(&n1);
    n0.neighbors.push_back(&n2);
    n1.neighbors.push_back(&n0);
    n1.neighbors.push_back(&n2);
    n2.neighbors.push_back(&n1);
    n2.neighbors.push_back(&n0);
    n2.neighbors.push_back(&n2);
    Node *res = s.cloneGraph(&n0);
    return 0;
}
