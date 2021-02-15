#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int p = n - k % n - 1;
        reverseHelper(nums, 0, p);
        reverseHelper(nums, p + 1, n - 1);
        reverseHelper(nums, 0, n - 1);
    }
    void reverseHelper(vector<int>& nums, int start, int end) {
        while (start < end) {
            int n = nums[start];
            nums[start] = nums[end];
            nums[end] = n;
            start++; end--;
        }
    }
};

int main()
{
    Solution s;
    int a[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> vec(a,a+4);
    s.rotate(vec, 2);
    vector<int>::iterator it = vec.begin();
    while (it != vec.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    return 0;
}
