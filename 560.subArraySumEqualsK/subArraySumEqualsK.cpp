#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        if (nums.size() == 0)
            return res;
        int preSum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            if (m.count(preSum - k))
                res += m[preSum - k];
            m[preSum]++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[3] = {-1,-1,1};
    vector<int> vec(a, a+3);
    cout << s.subarraySum(vec, 0);
    cout << endl;
    return 0;
}
