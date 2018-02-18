 #include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        for (int i = 0; i < n; i++) {
            father.push_back(i);
        }
        for (pair<int, int>& edge : edges) {
            if (find(edge.first) == find(edge.second))
                return false;
            else
                union_op(edge.first, edge.second);
        }
        return n == edges.size() + 1;
    }
    int find(int x) {
        if (father[x] == x)
            return x;
        return father[x] = find(father[x]);
    }
    void union_op(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y)
            father[root_x] = root_y;
    }
    vector<int> father;
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
