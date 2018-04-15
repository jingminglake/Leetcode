#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int n = nums.size();
        int mid = (n - 1) / 2;
        int index = 0;
        for (int i = 0; i <= mid; i++) {
            nums[index] = tmp[mid - i];
            if (index + 1 < n) {
                nums[index + 1] = tmp[n - 1 - i];
            }
            index += 2;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 5, 1, 1, 6, 4};
    s.wiggleSort(nums);
    for (int n : nums)
        cout << n << " ";
    cout << endl;
    return 0;
}
