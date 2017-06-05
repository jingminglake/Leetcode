#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    while (m > 0 && n > 0) {
      cout << "-----" << endl;
      if (nums1[m-1] > nums2[n-1]) {
	nums1[m+n-1] = nums1[m-1];
	m--;
      } else {
	nums1[m+n-1] = nums2[n-1];
	n--;
      }
    }
    while (n--) {
      nums1[n] = nums2[n];
    }
   
  }
};

int main()
{
  Solution s;
  int a[10] = {2,4,8,10,15,0,0,0,0,0};
  int b[5] = {3,4,6,8,11};
  vector<int> vec1(a, a+10);
  vector<int> vec2(b, b+5);
  s.merge(vec1, 5, vec2, 5);
  vector<int>::iterator it = vec1.begin();
  while (it != vec1.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
 
  return 0;
}
