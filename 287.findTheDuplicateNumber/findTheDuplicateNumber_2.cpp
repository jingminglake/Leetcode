#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int num : nums) {
                if (num < mid) count++;
            }
            if (count < mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};

int main()
{
    Solution s;
    int a[4] = {1,2,3,1};
    vector<int> vec(a, a+2);
    cout <<  s.findDuplicate(vec);
    cout << endl;
    return 0;
}
