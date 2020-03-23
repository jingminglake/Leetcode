#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
   vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> res = image;
        int color = res[sr][sc];
        if (color == newColor) return res;
        queue<vector<int> > q;
        q.push({sr, sc});
        res[sr][sc] = newColor;
        vector<vector<int> > dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while (!q.empty()) {
            vector<int> node = q.front(); q.pop();
            for (vector<int>& dir : dirs) {
                int next_i = node[0] + dir[0];
                int next_j = node[1] + dir[1];
                if (next_i < 0 || next_i >= res.size() || next_j < 0 || next_j >= res[0].size() || res[next_i][next_j] != color)
                    continue;
                res[next_i][next_j] = newColor;
                q.push({next_i, next_j});
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > image;
    vector<int> r1 = {0, 0, 0};
    vector<int> r2 = {0, 1, 1};
    //vector<int> r3 = {1, 0, 1};
    image.push_back(r1);
    image.push_back(r2);
    //image.push_back(r3);
    vector<vector<int> > res = s.floodFill(image, 1, 1, 1);
    for (vector<int>& vec : res) {
        for (int p : vec) {
            cout << p << " ";
        }
        cout << endl;
    }
    return 0;
}
