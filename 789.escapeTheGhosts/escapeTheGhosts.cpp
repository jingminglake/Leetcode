#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        long dis = abs(target[0]) + abs(target[1]);
        for (vector<int>& p : ghosts) {
            long dx = abs (target[0] - p[0]);
            long dy = abs (target[1] - p[1]);
            if (dx + dy <= dis)
                return false;
        }
        return true;
    }
};

int main() {
  Solution s;
  vector<vector<int>> ghosts = {{1, 0}};
  vector<int> target = {2, 0};
  cout << s.escapeGhosts(ghosts, target) << endl;
  return 0;
}
