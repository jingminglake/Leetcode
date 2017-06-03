#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    if (size < 2)
      return size;
    int numOfDup = 0;
    int current = nums[0];
    for (int i = 1; i < size; i++) {
      if (nums[i] == current)
	numOfDup++;
      else
	current = nums[i];
      nums[i - numOfDup] = nums[i];
    }
    while (numOfDup--) {
      nums.pop_back();
    }
    return nums.size();
  }
};

int main()
{
  Solution s;
  int a[5] = {1,1,2,4,5};
  vector<int> vec(a, a+5);
  cout << s.removeDuplicates(vec);
  cout << endl;
  vector<int>::iterator it = vec.begin();
  while (it != vec.end()) {
    cout << *it << "";
    ++it;
  }
  cout << endl;
  return 0;
}
