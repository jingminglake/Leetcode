#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (cnt == 0) {
                res = nums[i];
                cnt++;
            } else if (cnt > 0) {
                if (nums[i] != res) cnt--;
                else cnt++;
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
