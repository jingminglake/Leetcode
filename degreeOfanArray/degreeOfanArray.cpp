#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    class NumInfo {
    public:
        int freq;
        int firstLoc;
        int lastLoc;
    };
    int findShortestSubArray(vector<int>& nums) {
        int res = INT_MAX;
        unordered_map<int, NumInfo> m;
        int degree = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            degree = max (degree, ++m[num].freq);
            if (m[num].freq == 1) {
                m[num].firstLoc = i;
                m[num].lastLoc = i;
            } else {
                m[num].lastLoc = i;
            }
        }
        for (auto& p : m) {
            NumInfo& nf = p.second;
            if (nf.freq == degree) {
                res = min (res, nf.lastLoc - nf.firstLoc + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> ss = {1,2,2,3,1};
    vector<int> ss1 = {1,2,2,3,1,4,2};
    cout << s.findShortestSubArray(ss) << endl;
    cout << s.findShortestSubArray(ss1) << endl;
    return 0;
}
