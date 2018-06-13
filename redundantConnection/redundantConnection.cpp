#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (auto& edge : edges) {
            int parent_1 = find_op (edge[0]);
            int parent_2 = find_op (edge[1]);
            if (parent_1 == parent_2)
                return edge;
            else
                union_op(parent_1, parent_2);
        }
        return vector<int>(2,0);
    }
    int find_op(int n) {
        if (!parent.count(n))
            return parent[n] = n;
        else if (parent[n] == n)
            return n;
        else
            return parent[n] = find_op(parent[n]);
    }
    void union_op(int node_1, int node_2) {
        int parent_1 = find_op(node_1);
        int parent_2 = find_op(node_2);
        if (parent_1 != parent_2)
            parent[parent_2] = parent_1;
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
