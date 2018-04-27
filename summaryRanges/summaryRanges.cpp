#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            int start = nums[i];
            while (i < nums.size() - 1 && nums[i + 1] == nums[i] + 1)
                i++;
            if (start == nums[i])
                res.push_back(to_string(start));
            else
                res.push_back(to_string(start) + "->" + to_string(nums[i]));
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
