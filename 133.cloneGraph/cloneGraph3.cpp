#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        dfs(node, m);
        for (auto& n : m) {
            Node *new_n = m[n.first];
            for (int i = 0; i < new_n->neighbors.size(); i++) {
                new_n->neighbors[i] = m[new_n->neighbors[i]];
            }
        }
        return m[node];
    }
    void dfs(Node* node, unordered_map<Node*, Node*> &m) {
        if (!node) return;
        Node *n = new Node(node->val, node->neighbors);
        m[node] = n;
        for (Node* neighbor : node->neighbors) {
            if (!m.count(neighbor)) dfs(neighbor, m);
        }
    }
};
