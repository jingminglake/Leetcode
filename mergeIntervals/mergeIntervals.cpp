#include <iostream>
#include <vector>
using namespace std;

class Compare {
public:
    bool operator() (const vector<int>& v1, const vector<int>& v2) const {
        return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] < v2[1]);
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), Compare());
        vector<vector<int>> res;
        for (vector<int>& interval : intervals) {
            if (!res.empty() && interval[0] <= res.back()[1]) {
                res.back()[1] = max (res.back()[1], interval[1]);
            } else {
                res.push_back(interval);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
    vector<vector<int>> res = s.merge(intervals);
    for (auto &in : res)
        cout << in[0] << " " << in[1] << endl;
    return 0;
}
