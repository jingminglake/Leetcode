#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(2001);
        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;
        for (auto& edge : edges) {
            if (find_op(parent, edge[0]) == find_op(parent, edge[1]))
                return edge;
            else
                union_op(parent, edge);
        }
        return vector<int>(2,0);
    }
    int find_op(vector<int>& parent, int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = find_op(parent, parent[n]);
    }
    void union_op(vector<int>& parent, vector<int>& edge) {
        int p1 = find_op(parent, edge[0]);
        int p2 = find_op(parent, edge[1]);
        if (p1 != p2)
            parent[p2] = p1;
    }
};

int main() {
    Solution s;
    vector<vector<int> > edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    for(int& v : s.findRedundantConnection(edges))
        cout << v << " ";
    cout << endl;
    return 0;
}
