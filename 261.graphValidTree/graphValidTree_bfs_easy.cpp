#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1)
            return false;
        vector<vector<int> > m(n, vector<int>());
        for (auto& p : edges) {
            m[p.first].push_back(p.second);
            m[p.second].push_back(p.first);
        }
        unordered_set<int> s;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            s.insert(node);
            for (int neighbor : m[node]) {
                if (!s.count(neighbor)) {
                    q.push(neighbor);
                    s.insert(neighbor);
                }
            }
        }
        return s.size() == n;
    }
};

int main()
{
  Solution s;
  vector<pair<int, int> > edges = {{0,1},
				   {0,2},
				   {0,3},
				   {1,4}};
  cout <<  s.validTree(5, edges) << endl;
  return 0;
}
