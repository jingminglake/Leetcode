#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int removeElement(vector<int>& nums, int val) {
    int size = nums.size();
    if (size < 1)
      return size;
    
    int numOfInstance = 0;
    for (int i = 0; i < size; i++) {
      if (nums[i] == val)
	numOfInstance++;
      else
	nums[i-numOfInstance] = nums[i];
    }
    while (numOfInstance--)
      nums.pop_back();
    return nums.size();
  }
};

int main()
{
  Solution s;
  int a[4] = {3,2,2,3};
  vector<int> vec(a, a+4);
  cout << s.removeElement(vec, 3);
  cout << endl;
  vector<int>::iterator it = vec.begin();
  while (it != vec.end()) {
    cout << *it << "";
    ++it;
  }
  cout << endl;
  return 0;
}
