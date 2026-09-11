// clang++ slidingWindowMaximum.cpp -std=c++11

#include <iostream>
#include <vector>
#include <deque>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return vector<int>();
        vector<int> res(n - k + 1);
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();
            while (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            dq.push_back(i);
            if (i >= k - 1)
                res[i - k + 1] = nums[dq.front()];
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int>  nums = {1,3,-1,-3,5,3,6,7};
    vector<int> res = s.maxSlidingWindow(nums, 3);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
