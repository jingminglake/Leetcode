#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int start = -1, end = -2;
        int curMax = INT_MIN, curMin = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] >= curMax)
                curMax = nums[i];
            else
                end = i;
            if (nums[n - 1 - i] <= curMin)
                curMin = nums[n - 1 - i];
            else
                start = n - 1 - i;
        }
        return end - start + 1;
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
