#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return false;
        vector<int> leftMin(n, INT_MAX), rightMax(n, INT_MIN);
        leftMin[0] = nums[0], rightMax[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min (leftMin[i - 1], nums[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max (rightMax[i + 1], nums[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > leftMin[i] && nums[i] < rightMax[i])
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    int a[6] = {6, 5, 6, 0, 1, 7};
    vector<int> vec(a, a+6);
    cout << s.increasingTriplet(vec);
    cout << endl;
    return 0;
}
