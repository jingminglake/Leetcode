#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution{
public:
  static bool comp(const Interval& a, const Interval& b){
      return a.start < b.start;
  }
  
  vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> ans;
    int size = intervals.size();
    if (size == 0)
      return ans;
    sort(intervals.begin(), intervals.end(), comp);
    // sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
    ans.push_back(intervals[0]);
    for (int i = 1; i < size; i++) {
      if (intervals[i].start > ans.back().end)
	ans.push_back(intervals[i]);
      else
	ans.back().end = max(ans.back().end, intervals[i].end);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  struct Interval interv1(1, 3);
  struct Interval interv2(2, 6);
  struct Interval interv3(8, 10);
  struct Interval interv4(15, 18);
  vector<Interval> vec;
  vec.push_back(interv1);
  vec.push_back(interv2);
  vec.push_back(interv3);
  vec.push_back(interv4);
  vector<Interval> res = s.merge(vec);
  for (Interval &in : res)
    cout << in.start << " " << in.end << endl;
  return 0;
}
