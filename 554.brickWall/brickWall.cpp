#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
  int leastBricks(vector<vector<int> >& wall) {
    if (wall.size() == 0)
      return 0;
    int maxPreSumNum = 0;
    unordered_map<int, int> m;
    for (vector<int>& bricks : wall) {
      int preSum = 0;
      for (int i = 0; i < bricks.size() - 1; i++) {
	preSum += bricks[i];
	maxPreSumNum = max (maxPreSumNum, ++m[preSum]);
      }
    }
    return wall.size() - maxPreSumNum;
  }
};

int main()
{
  Solution s;
  int a0[4] = {1,2,2,1};
  int a1[3] = {3,1,2};
  int a2[3] = {1,3,2};
  int a3[2] = {2,4};
  int a4[3] = {3,1,2};
  int a5[4] = {1,3,1,1};
  vector<int> vec0(a0, a0+4);
  vector<int> vec1(a1, a1+3);
  vector<int> vec2(a2, a2+3);
  vector<int> vec3(a3, a3+2);
  vector<int> vec4(a4, a4+3);
  vector<int> vec5(a5, a5+4);
  vector<vector<int> > wall;
  wall.push_back(vec0);
  wall.push_back(vec1);
  wall.push_back(vec2);
  wall.push_back(vec3);
  wall.push_back(vec4);
  wall.push_back(vec5);
  cout << s.leastBricks(wall);
  cout << endl;
  return 0;
}
