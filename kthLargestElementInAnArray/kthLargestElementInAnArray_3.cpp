// clang++ kthLargestElementInAnArray_3.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargestHelper(nums, 0, nums.size() - 1, nums.size() - k);
    }
    int findKthLargestHelper(vector<int>& nums, int start, int end, int index) {
        //cout << start << "  " << end << endl;
        if (start >= end)
            return nums[start];
        int pivot = nums[start];
        int last = start;
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[++last]);
            }
        }
        swap (nums[start], nums[last]);
        if (index == last) {
            return nums[last];
        }
        else if (index < last) {
            return findKthLargestHelper(nums, start, last - 1, index);
        } else {
            return findKthLargestHelper(nums, last + 1, end, index);
        }
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
