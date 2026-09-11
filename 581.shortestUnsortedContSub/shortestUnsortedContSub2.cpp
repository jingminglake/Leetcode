#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        if (n < 1)
            return res;
        stack<int> s;
        int left = n - 1;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[i] < nums[s.top()]) {
                left = min (left, s.top());
                s.pop();
            }
            s.push(i);
        }
        s = stack<int>();
        int right = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[i] > nums[s.top()]) {
                right = max (right, s.top());
                s.pop();
            }
            s.push(i);
        }
        return right > left ? right - left + 1 : 0;
    }
};

int main()
{
    Solution s;
    int a[7] = {2,6,4,8,10,9,15};
    vector<int> vec(a, a+7);
    cout << s.findUnsortedSubarray(vec) << endl;
 
    return 0;
}
