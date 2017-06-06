#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution{
public:
  int numberOfBoomerangs(vector<pair<int, int> >& points) {
    int ans = 0;
    int size = points.size();
    unordered_map<double, int> map;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
	if (i == j)
	  continue;
	map[hypot(points[i].first - points[j].first, points[i].second - points[j].second)]++;
      }
      for (auto val : map)
	if (val.second > 1)
	  ans += val.second * (val.second - 1);
      map.clear();
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
