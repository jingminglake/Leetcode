#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid;
            else 
                right = mid;
        }
        return min (nums[left], nums[right]);
    }
};

int main()
{
    Solution s;
    int a[7] = {3,1,2,7,0,1,2};
    vector<int> vec(a, a+3);
    cout << s.findMin(vec);
    cout << endl;
    return 0;
}
