#include <iostream>
#include <vector>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Compare {
public:
  bool operator()(const Interval& i1, const Interval& i2) const {
    return i1.start < i2.start;
  }
};

class Solution {
public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    if (intervals.size() == 0)
      return true;
    sort(intervals.begin(), intervals.end(), Compare());
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i - 1].end > intervals[i].start)
	return false;
    }
    return true;
  }
};

int main()
{
  Solution s;
  Interval i1(0, 30), i2(5, 10), i3(15, 20);
  vector<Interval> intervals = {i1, i2, i3};
  cout << s.canAttendMeetings(intervals) << endl;
  return 0;
}
