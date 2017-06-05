#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    if (k == 0)
      return;
    int step = size - k % size;
    reverse(nums.begin(), nums.begin() + step);
    reverse(nums.begin() + step, nums.end());
    reverse(nums.begin(), nums.end());
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
