#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 0)
            return;
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right] != 0)
                swap(nums[left++], nums[right++]);
            else
                right++;
        }
    }
};

int main()
{
  Solution s;
  int a[5] = {0,1,0,3,12};
  vector<int> vec(a, a+5);
  s.moveZeroes(vec);
  vector<int>::iterator it = vec.begin();
  while (it != vec.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  return 0;
}
