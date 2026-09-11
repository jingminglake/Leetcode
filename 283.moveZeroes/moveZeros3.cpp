#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap (nums[left++], nums[i]);
            }
        }
    }
};

int main()
{
    Solution s;
    int a[5] = {0,1,0,3,12};
    vector<int> vec(a, a+5);
    s.moveZeroes(vec);
    vector<int>::iterator it = vec.begin();
    while (it != vec.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    return 0;
}
