#include <iostream>
#include <vector>
using namespace std;

class Compare {
public:
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.second < p2.second;
    }
};

class Solution{
public:
  int findMinArrowShots(vector<pair<int, int>>& points) {
    int res = 0;
    if (points.size() == 0)
      return res;
    sort(points.begin(), points.end(), Compare());
    int arrowPos = points[0].second;
    res = 1;
    for (int i = 1; i < points.size(); i++) {
      if (points[i].first <= arrowPos)
	continue;
      res++;
      arrowPos = points[i].second;
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<pair<int, int> > points = {make_pair(10, 16), make_pair(2, 8), make_pair(1, 6), make_pair(7, 12)};
  cout << s.findMinArrowShots(points) << endl;
  return 0;
}
