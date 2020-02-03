#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int rightProduct = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= rightProduct;
            rightProduct  *= nums[i];
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[4] = {1,0,0,1};
    vector<int> vec(a, a+2);
    vector<int> res = s.productExceptSelf(vec);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
