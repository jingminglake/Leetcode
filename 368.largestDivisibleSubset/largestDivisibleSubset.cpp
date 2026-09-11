// clang++ largestDivisibleSubset.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if (n == 0)
            return res;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int max_len = 1, last_index = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (dp[i] > max_len) {
                        max_len = dp[i];
                        last_index = i;
                    }
                }
            }
        }
        //cout << last_index << endl;
        while (last_index != -1) {
            res.push_back(nums[last_index]);
            last_index = parent[last_index];
        }
        //reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4,8,9};
    vector<int> res = s.largestDivisibleSubset(nums);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
