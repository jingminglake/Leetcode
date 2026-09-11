#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    if ((m + n) % 2 != 0)
      return findKth(nums1, 0, nums2, 0, (m + n) / 2 + 1);
    else
      return (findKth(nums1, 0, nums2, 0, (m + n) / 2) + findKth(nums1, 0, nums2, 0, (m + n) / 2 + 1) ) / 2.0;
  }
  double findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k) {
    if (start1 >= nums1.size()) {
      return nums2[start2 + k - 1];
    }
    if (start2 >= nums2.size()) {
      return nums1[start1 + k - 1];
    }
    if (k == 1)
      return min (nums1[start1], nums2[start2]);
        
    int A_k = ( (start1 + k / 2 - 1) >= nums1.size() ) ? INT_MAX : nums1[start1 + k / 2 - 1];
    int B_k = ( (start2 + k / 2 - 1) >= nums2.size() ) ? INT_MAX : nums2[start2 + k / 2 - 1];
    if (A_k < B_k) {
      return findKth(nums1, start1 + k / 2, nums2, start2, k - k / 2);
    } else {
      return findKth(nums1, start1, nums2, start2 + k / 2, k - k / 2);
    }
  }
};

int main()
{
  Solution s;
  int a[4] = {2,3,4}; 
  int b[4] = {1};
  vector<int> v1(a, a+3);
  vector<int> v2(b, b+1);
  cout << s.findMedianSortedArrays(v1, v2) << endl;
  return 0;
}
