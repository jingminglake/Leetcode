#include <iostream>
#include <vector>
using namespace std;

// Definition for an interval.
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if (intervals.size() == 0) {
            res.push_back(newInterval);
            return res;
        }
        int nStart = newInterval.start;
        int nEnd = newInterval.end;
        int i = 0;
        while (i < intervals.size()) {
            if (intervals[i].end < newInterval.start) {
                res.push_back(intervals[i]);
                i++;
            } else {
                break;
            }
        }
        if (i == intervals.size()) {
            res.push_back(newInterval);
            return res;
        }
        nStart = min (nStart, intervals[i].start);
        while (i < intervals.size()) {
            if (intervals[i].start <= nEnd) {
                nEnd = max (nEnd, intervals[i].end);
                i++;
            } else {
                break;
            }
        }
        Interval temp(nStart, nEnd);
        res.push_back(temp);
        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};

int main()
{
  Solution s;
  Interval t1(1,3);
  Interval t2(6, 9);
  vector<Interval> intervals;
  intervals.push_back(t1);
  intervals.push_back(t2);
  Interval t(2,5);
  for (Interval& i : s.insert(intervals, t)) {
    cout << "("<< i.start << ", " << i.end << ") ";
  }
  cout << endl;
  return 0;
}
