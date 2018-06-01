// clang++ kthLargestElementInAnArray_3.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return -1;
        return findKthLargestHelper(nums, nums.size() - k, 0, nums.size() - 1);
    }
    int findKthLargestHelper(vector<int>& nums, int k, int left, int right) {
        if (left >= right)
            return nums[left];
        int pos = rand() % (right - left) + left;
		swap(nums[pos], nums[left]);
        int pivot = nums[left];
        int last = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < pivot)
                swap (nums[i], nums[++last]);
        }
        swap (nums[left], nums[last]);
        if (last == k)
            return nums[last];
        else if (last > k)
            return findKthLargestHelper(nums, k, left, last - 1);
        else
            return findKthLargestHelper(nums, k, last + 1, right);
    }
};

int main()
{
  Solution s;
  vector<int> vec = {3,2,1,5,6,4}; 
  cout << s.findKthLargest(vec, 2);
  cout << endl;
  return 0;
}
