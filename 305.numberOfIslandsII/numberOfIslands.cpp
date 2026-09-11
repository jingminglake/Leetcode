#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int count;
    int find_op(vector<int>& root, int index) {
        if (root[index] == index)
            return index;
        return root[index] = find_op(root, root[index]);
    }
    void union_op(vector<int>& root, int index1, int index2) {
        int root1 = find_op(root, index1);
        int root2 = find_op(root, index2);
        if (root1 != root2) {
            root[root1] = root2;
            count--;
        }
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m < 0 || n < 0)
            return res;
        count = 0;
        vector<int> root(m * n, -1);
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (auto& pos : positions) {
            int index1 = n * pos.first + pos.second;
            root[index1] = index1;
            count++;
            for (auto& dir : dirs) {
                int x = pos.first + dir.first;
                int y = pos.second + dir.second;
                int index2 = n * x + y;
                if (x < 0 || x >= m || y < 0 || y >= n || root[index2] == -1)
                    continue;
                union_op(root, index1, index2);
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
