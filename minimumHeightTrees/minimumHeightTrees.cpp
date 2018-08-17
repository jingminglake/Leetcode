#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        vector<unordered_set<int> > neighbors(n);
        for (auto& edge : edges) {
            neighbors[edge.first].insert(edge.second);
            neighbors[edge.second].insert(edge.first);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (neighbors[i].size() == 1)
                q.push(i);
        }
        int m = n;
        while (!q.empty()) {
            if (m <= 2)
                break;
            int size = q.size();
            m -= size;
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                for (int neighbor : neighbors[node]) {
                    neighbors[neighbor].erase(node);
                    if (neighbors[neighbor].size() == 1)
                        q.push(neighbor);
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int> > edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(1,3));
    edges.push_back(make_pair(2,3));
    edges.push_back(make_pair(4,3));
    edges.push_back(make_pair(5,4));
    vector<int> res = s.findMinHeightTrees(6, edges);
    for (int v : res)
        cout << v << " ";
    cout << endl;
    return 0;
}
