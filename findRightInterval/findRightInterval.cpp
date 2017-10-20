// clang++ findRightInterval.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution{
public:
  vector<int> findRightInterval(vector<Interval>& intervals) {
    vector<int> res, starts;
    unordered_map<int, int> m;
    for (int i = 0; i < intervals.size(); i++) {
      starts.push_back(intervals[i].start);
      m[intervals[i].start] = i;
    }
    sort(starts.begin(), starts.end());
    for (auto &iter : intervals) {
      int left = 0, right = starts.size() - 1;
      int i = 0;
      bool find = false;
      while (left <= right) {
	int mid = left + (right - left) / 2;
	if (starts[mid] > iter.end)
	  right = mid - 1;
	else if (starts[mid] < iter.end)
	  left = mid + 1;
	else {
	  i = mid;
	  find = true;
	  break;
	}
      }
      if (!find)
	i = left;
      res.push_back((i >= 0 && i < starts.size() ) ? m[starts[i]] : -1);
    }
    return res;
  }
};

int main()
{
  Solution s;
  Interval i1(3,4), i2(2,3), i3(1,2);
  vector<Interval> intervals;
  intervals.push_back(i1);
  intervals.push_back(i2);
  intervals.push_back(i3);
  vector<int> res;
  res = s.findRightInterval(intervals);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
