#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int count;
    unordered_map<int, int> parent;
    int find_op(int node) {
        if (!parent.count(node))
            return parent[node] = node;
        else if (parent[node] == node)
            return node;
        else
            return parent[node] = find_op(parent[node]);
    }
    void union_op(int node1, int node2) {
        int p1 = find_op(node1);
        int p2 = find_op(node2);
        if (p1 != p2) {
            parent[p1] = p2;
            count--;
        }
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m <= 0 || n <= 0)
            return res;
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (auto& p : positions) {
            int node = p.first * n + p.second;
            parent[node] = node;
            count++;
            for (auto& d : dirs) {
                int neighbor_x = p.first + d.first;
                int neighbor_y = p.second + d.second;
                if (neighbor_x < 0 || neighbor_x >= m || neighbor_y < 0 || neighbor_y >= n)
                    continue;
                int neighbor = neighbor_x * n + neighbor_y;
                if (!parent.count(neighbor))
                    continue;
                union_op(node, neighbor);
            }
            res.push_back(count);
        }
        return res;
    }
};

int main()
{
    Solution s;
    int m = 3, n = 3;
    vector<pair<int, int> > positions = {{0,0}, {0,1}, {1,2}, {2,1}};
    for (int i : s.numIslands2(m, n, positions))
        cout << i << " ";
    cout << endl;
    return 0;
}
