// clang++ kthLargestElementInAnArray.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int findKthLargest(vector<int> nums, int k) {
    int size = nums.size();
    return findHelper(nums, 0, size, k);
  }
  int findHelper(vector<int>& nums, int begin, int end, int k) {
    int pivot = nums[begin];
    int last = begin;
    for (int i = begin + 1; i < end; i++) {
      if (nums[i] >= pivot)
	swap(nums[i], nums[++last]);
    }
    swap(nums[begin], nums[last]);
    int rank = last - begin + 1;
    if (rank == k)
      return nums[last];
    else if (rank < k) 
      return findHelper(nums, last + 1, end, k - rank);
    else if (rank > k)
      return findHelper(nums, begin, last, k);
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
