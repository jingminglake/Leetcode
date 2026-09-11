#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        for (auto& edge : edges) {
            int p1 = find_op(edge[0]);
            int p2 = find_op(edge[1]);
            if (p1 != p2)
                parent[p1] = p2;
            else
                return edge;
        }
        return res;
    }
    int find_op(int node) {
        if (!parent.count(node))
            return parent[node] = node;
        if (parent[node] == node)
            return node;
        return parent[node] = find_op(parent[node]);
    }
    unordered_map<int, int> parent;
};

int main() {
    Solution s;
    vector<vector<int> > edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    for(int& v : s.findRedundantConnection(edges))
        cout << v << " ";
    cout << endl;
    return 0;
}
