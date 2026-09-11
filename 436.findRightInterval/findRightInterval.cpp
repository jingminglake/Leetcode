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

class Solution {
public:
    static bool compare (const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first == p2.first) return p1.second < p2.second;
        else return p1.first < p2.first;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int m = intervals.size();
        if (m == 1) return { -1 };
        vector<pair<int, int> > start;
        for (int i = 0; i < m; i++) {
            start.emplace_back(intervals[i][0], i);
        }
        sort(start.begin(), start.end(), compare);
        
        vector<int> res;
        for (int i = 0; i < m; i++) {
            res.push_back(findFirstGreater(start, intervals[i][1]));
        }
        return res;
    }
    
    int findFirstGreater(vector<pair<int, int> >& start, int endJ) {
        int left = 0, right = start.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (start[mid].first >= endJ) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (start[left].first >= endJ) return start[left].second;
        else if (start[right].first >= endJ) return start[right].second;
        else return -1;
    }
};

int main()
{
    Solution s;
    //Interval i1(3,4), i2(2,3), i3(1,2);
    vector<int> v1 = {3, 4};
    vector<int> v2 = {2, 3};
    vector<int> v3 = {1, 2};
    vector<vector<int> > intervals;
    
    intervals.push_back(v1);
    intervals.push_back(v2);
    intervals.push_back(v3);
    vector<int> res;
    res = s.findRightInterval(intervals);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
