#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution{
public:
  int numberOfBoomerangs(vector<pair<int, int> >& points) {
    int ans = 0;
    for (auto point : points) {
      unordered_map<double, int> map;
      for (auto point2 : points)
	map[hypot(point.first - point2.first, point.second - point2.second)]++;
      for (auto val : map)
	if (val.second > 1)
	  ans += val.second * (val.second - 1);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<pair<int, int> > vec;
  vec.push_back(make_pair(0,0));
  vec.push_back(make_pair(1,0));
  vec.push_back(make_pair(2,0));
  cout << s.numberOfBoomerangs(vec);
  cout << endl;
  return 0;
}
