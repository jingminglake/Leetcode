#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                count++;
                res = nums[i];
            } else if (nums[i] == res) {
                count++;
            } else {
                count--;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[7] = {2,6,4,8,10,9,15};
    vector<int> vec(a, a+7);
    cout << s.majorityElement(vec) << endl;
 
    return 0;
}
