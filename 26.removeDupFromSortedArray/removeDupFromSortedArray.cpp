#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[res++] = nums[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[5] = {1,1,2,4,5};
    vector<int> vec(a, a+5);
    int size = s.removeDuplicates(vec);
    for (int i = 0; i < size; i++)
        cout << vec[i] << " ";
    cout << endl;
    return 0;
}
