#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  void moveZeros(vector<int>& nums) {
    int numOfZero = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      if (0 == nums[i]) {
	numOfZero++;
      }
      else 
        swap(nums[i], nums[i-numOfZero]);
    }
  }
};

int main()
{
  Solution s;
  int a[5] = {0,1,0,3,12};
  vector<int> vec(a, a+5);
  s.moveZeros(vec);
  vector<int>::iterator it = vec.begin();
  while (it != vec.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  return 0;
}
