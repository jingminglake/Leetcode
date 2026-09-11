#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T)
            return 0;
        unordered_map<int, vector<int> > routes2bus;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
               routes2bus[routes[i][j]].push_back(i);
            }
        }
        int res = 0;
        queue<int> q;
        q.push(S);
        unordered_set<int> visited;
        while (!q.empty()) {
            res++;
            int m_size = q.size();
            for (int i = 0; i < m_size; i++) {
                int node = q.front();
                q.pop();
                for (int b : routes2bus[node]) {
                    if (visited.count(b))
                        continue;
                    visited.insert(b);
                    for (int n : routes[b]) {
                        if (n == T)
                            return res;
                        q.push(n);
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int> > routes = {{1, 2, 7}, {3, 6, 7}};
    int S = 1, T = 6;
    cout << s.numBusesToDestination(routes, S, T) << endl;
    return 0;
}
