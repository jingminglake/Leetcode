#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      ans ^= nums[i];
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[7] = {1,3,2,2,5,3,5};
  vector<int> vec(a, a+7);
  cout << s.singleNumber(vec);
  cout << endl;
  return 0;
}
