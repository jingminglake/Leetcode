#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size()), temp;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int left = 0, right = temp.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (temp[mid] >= nums[i])
                    right = mid;
                else
                    left = mid + 1;
            }
            res[i] = right;
            temp.insert(temp.begin() + right, nums[i]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 2, 6, 1};
    for(int n : s.countSmaller(nums))
        cout << n << " ";
    cout << endl;
    return 0;
}
