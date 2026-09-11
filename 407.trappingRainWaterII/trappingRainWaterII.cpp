// clang++ trappingRainWaterII.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty())
            return 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        int res = 0;
        auto comp = [&](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first > p2.first;
        };
        typedef priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp) > my_pq;
        my_pq q(comp);
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        vector<vector<int> > dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (int i = 0; i < m; i++) {
            q.push({heightMap[i][0], i * n + 0});
            q.push({heightMap[i][n - 1], i * n + n - 1});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            q.push({heightMap[0][j], 0 * n + j});
            q.push({heightMap[m - 1][j], (m - 1) * n + j});
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            int h = t.first, r = t.second / n, c = t.second % n;
            for (int i = 0; i < dirs.size(); i++) {
	            int x = r + dirs[i][0], y = c + dirs[i][1];
	            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y])
	                continue;
	            visited[x][y] = true;
	            res += max(0, h - heightMap[x][y]);
	            q.push({max (heightMap[x][y], h), x * n + y});
            }
        }
        return res;
    }
};

int main()
{
  Solution s;
  vector<vector<int> > height = {{1, 4, 3, 1, 3, 2} , {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
  cout << s.trapRainWater(height) << endl;;
  return 0;
}
