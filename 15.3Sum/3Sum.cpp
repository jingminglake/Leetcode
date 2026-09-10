#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 3; i++) {
            int n1 = nums[i];
            if (n1 > 0) break;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum + n1 == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++; right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum + n1 > 0) {
                    right--;
                } else {
                    left++;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[6] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(a, a+6);
    vector<vector<int> > vec = s.threeSum(nums);
    vector<vector<int> >::iterator it = vec.begin();
    while(it != vec.end()) {
        vector<int>::iterator it2 = (*it).begin();
        while(it2 != (*it).end()) {
            cout << *it2 << " ";
            ++it2;
        }
        cout << endl;
        ++it;
    }
    return 0;
}
