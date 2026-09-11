#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n == 1) return {0};
        vector<unordered_set<int> > neighbors(n);
        for (auto& edge : edges) {
            neighbors[edge[0]].insert(edge[1]);
            neighbors[edge[1]].insert(edge[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (neighbors[i].size() == 1) q.push(i);
        }
        int remain = n;
        while (!q.empty()) {
            if (remain <= 2) break;
            int q_size = q.size();
            remain -= q_size;
            for (int i = 0; i < q_size; i++) {
                int leave = q.front(); q.pop();
                int neighbor = *(neighbors[leave].begin());
                neighbors[neighbor].erase(leave);
                if (neighbors[neighbor].size() == 1) q.push(neighbor);
            }
        }
        while (!q.empty()) {
            res.push_back(q.front()); q.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > edges;
    edges.push_back({0,3});
    edges.push_back({1,3});
    edges.push_back({2,3});
    edges.push_back({4,3});
    edges.push_back({5,4});
    vector<int> res = s.findMinHeightTrees(6, edges);
    for (int v : res)
        cout << v << " ";
    cout << endl;
    return 0;
}
