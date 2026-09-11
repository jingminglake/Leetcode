#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int completeNum = target - nums[i];
            if (m.count(completeNum)) {
                res = {m[completeNum], i};
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    //  nums.push_back(15);
    int target = 6;
    try{
        vector<int> result = s.twoSum(nums, target);
        vector<int>::const_iterator ptr = result.begin();
        while (ptr != result.end())
        {
            cout << *ptr << endl;
            ++ptr;
        }
    }
    catch(const string &msg)
    {
        cout << msg << endl;
    }
    return 0;
}
