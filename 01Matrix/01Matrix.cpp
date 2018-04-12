#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return matrix;
        queue<pair<int, int> > q;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    q.push(make_pair(i, j));
                } else {
                    matrix[i][j] = INT_MAX;
                }
            }
        }
        vector<vector<int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int dis = 0;
        while (!q.empty()) {
            int size = q.size();
            dis++;
            for (int i = 0; i < size; i++) {
                pair<int, int> cur = q.front();
                q.pop();
                for (auto& dir : dirs) {
                    int nextI = cur.first + dir[0];
                    int nextJ = cur.second + dir[1];
                    if (nextI < 0 || nextI >= matrix.size() || nextJ < 0 || nextJ >= matrix[0].size() || matrix[nextI][nextJ] < dis)
                        continue;
                    matrix[nextI][nextJ] = dis;
                    q.push(make_pair(nextI, nextJ));
                }
            }
        }
        return matrix;
    }
};

int main()
{
  Solution s;
  int a1[3] = {0,0,0};
  int a2[3] = {0,1,0};
  int a3[3] = {1,1,1};
  vector<int> vec1(a1, a1+3);
  vector<int> vec2(a2, a2+3);
  vector<int> vec3(a3, a3+3);
  vector<vector<int> > matrix;
  matrix.push_back(vec1);
  matrix.push_back(vec2);
  matrix.push_back(vec3);
  s.updateMatrix(matrix);
  for (vector<int>& v : matrix) {
    for (int i : v)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
