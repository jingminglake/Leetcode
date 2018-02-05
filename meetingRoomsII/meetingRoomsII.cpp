#include <iostream>
#include <vector>
#include <queue>
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
  int minMeetingRooms(vector<Interval>& intervals) {
    int res = 0;
    if (intervals.size() == 0)
      return res;
    sort(intervals.begin(), intervals.end(), Compare());
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(intervals[0].end);
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i].start < pq.top()) {
	pq.push(intervals[i].end);
      } else {
	pq.pop();
	pq.push(intervals[i].end);
      }
    }
    return pq.size();
  }
};

int main()
{
  Solution s;
  Interval i1(0, 30), i2(5, 10), i3(15, 20);
  vector<Interval> intervals = {i1, i2, i3};
  cout << s.minMeetingRooms(intervals) << endl;
  return 0;
}
