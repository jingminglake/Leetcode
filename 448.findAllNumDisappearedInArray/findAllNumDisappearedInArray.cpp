#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int n : nums) {
            int index = abs(n) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) res.push_back(i + 1);
            else nums[i] = -nums[i];
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[8] = {4,3,2,7,8,2,3,1};
    vector<int> vec(a, a+8);
    vector<int> vec2 = s.findDisappearedNumbers(vec);
    vector<int>::iterator it = vec2.begin();
    while (it != vec2.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    return 0;
}
