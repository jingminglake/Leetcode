#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int res = 0;
        map<int, int> m;
        for (auto& i : intervals) {
            m[i.start]++;
            m[i.end]--;
        }
        int ongoing = 0;
        for (auto& p : m) {
            ongoing += p.second;
            res = max (res, ongoing);
        }
        return res;
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
