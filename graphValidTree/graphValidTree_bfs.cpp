#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int> > m;
        for (vector<int>& edge : edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        queue<pair<int, int> > q;
        q.push({-1, 0});
        unordered_set<int> visited;
        visited.insert(0);
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int neighbor : m[p.second]) {
                if (neighbor != p.first) {
                    if (visited.count(neighbor)) {
                        return false;
                    } else {
                        q.push({p.second, neighbor});
                        visited.insert(neighbor);
                    }
                }
            }
        }
        return n == visited.size();
    }
};

int main()
{
    Solution s;
    vector<vector<int> > edges = {{0,1},
                                     {0,2},
                                     {0,3},
                                     {1,4}};
    cout <<  s.validTree(5, edges) << endl;
    return 0;
}
