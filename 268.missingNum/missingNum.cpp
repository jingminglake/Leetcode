#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
  int missingNumber(vector<int>& nums) {
    int size = nums.size();
    int sum = size * (size + 1) / 2;
    for (const int& num : nums)
      sum -= num;
    return sum;
  }
};

int main()
{
  Solution s;
  int a[8] = {1,2,3,4,5,6,7,8};
  vector<int> vec(a, a+3);
  cout << s.missingNumber(vec) << endl;
 
  return 0;
}
