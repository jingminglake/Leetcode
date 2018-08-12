#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> temp;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
            res[i] = it - temp.begin();
            temp.insert(it, nums[i]);
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
