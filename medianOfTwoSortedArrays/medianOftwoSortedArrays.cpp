#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double median;
    int size1 = nums1.size();
    int size2 = nums2.size();
    if (size1 == 0 && size2 == 0)
      return 0;
    if (size1 == 0 && size2 != 0) {
      if(size2 % 2 != 0)
	return nums2[size2 / 2];
      else
	return (nums2[size2 / 2 - 1] + nums2[size2 / 2]) * 1.0 / 2;
    }
    if(size1 !=0 && size2 ==0) {
       if(size1 % 2 != 0)
	return nums1[size1 / 2];
      else
	return (nums1[size1 / 2 - 1] + nums1[size1 / 2]) * 1.0 / 2;
    }
    int left1 = 0, left2 = 0;
    int right1 = size1 - 1, right2 = size2 - 1;
    int m1 = 0, m2 = 0;
    int mid =  (size1 + size2 - 1) / 2;
    double med1 = 0.0, med2 = 0.0;
    if (size1 <= size2) {
      while (left1 <= right1) {
        m1 = (left1 + right1) / 2;
        m2 = mid - m1;
        if(nums1[m1] >= nums2[m2]) {
          right1 = m1 - 1;
        }
        else {
          left1 = m1 + 1;
        }
      }
       med1 = max(left1 > 0 ? nums1[right1]:INT_MIN, nums2[mid - left1]);
       med2 = min(left1 < size1 ? nums1[left1]:INT_MAX, mid - right1 < size2 ? nums2[mid - right1]:INT_MAX);
    }else {
      while (left2 <= right2) {
        m2 = (left2 + right2) / 2;
        m1 = mid - m2;
        if(nums2[m2] >= nums1[m1]) {
          right2 =  m2 - 1;
        }
        else {
          left2 = m2 + 1;
        }
      }
      med1 = max(left2 > 0 ? nums2[right2]:INT_MIN, nums1[mid - left2]);
      med2 = min(left2 < size2 ? nums2[left2]:INT_MAX, mid - right2 < size1 ? nums1[mid - right2]:INT_MAX);
    }
    //cout << left1 << "--1-- " << right1 << endl;
    //cout << left2 << "--2-- " << right2 << endl;
    if((size1 + size2) % 2 != 0)
      median = med1;
    else
      median = (med1 + med2)/2;
    return median;
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
