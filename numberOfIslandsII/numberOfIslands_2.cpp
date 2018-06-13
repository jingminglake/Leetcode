#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int count;
    unordered_map<int, int> parent;
    int find_op(int index) {
        if (!parent.count(index))
            return parent[index] = index;
        else if (parent[index] == index)
            return index;
        else
            return parent[index] = find_op(parent[index]);
    }
    void union_op(int index_1, int index_2) {
        int parent_1 = find_op(index_1);
        int parent_2 = find_op(index_2);
        if (parent_1 != parent_2) {
            parent[parent_1] = parent_2;
            count--;
        }
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m < 0 || n < 0)
            return res;
        count = 0;
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (auto& pos : positions) {
            int index_1 = n * pos.first + pos.second;
            parent[index_1] = index_1;
            count++;
            for (auto& dir : dirs) {
                int x = pos.first + dir.first;
                int y = pos.second + dir.second;
                int index_2 = n * x + y;
                if (x < 0 || x >= m || y < 0 || y >= n || !parent.count(index_2))
                    continue;
                union_op(index_1, index_2);
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
