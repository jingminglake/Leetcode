#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int left = 0, right = 0;
        while (right < nums.size()) {
            right++;
            while (right < nums.size() && nums[right] == nums[right - 1] + 1)
                right++;
            if (nums[left] == nums[right - 1])
                res.push_back(to_string(nums[left]));
            else
                res.push_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
            left = right;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[4] = {0,1,5,7};
    vector<int> vec(a, a+4);
    vector<string> res = s.summaryRanges(vec);
    for (string s : res) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
