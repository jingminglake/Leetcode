#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int totalHammingDistance(vector<int>& nums) {
    int res = 0;
    if (nums.size() == 0)
      return res;
    for (int i = 0; i < sizeof(int) * 8; i++) {
      int countOne = 0;
      for (int num : nums) {
	num >>= i;
	if ((num & 1) == 1)
	  countOne++;
      }
      res += (countOne) * (nums.size() - countOne);
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> vec = {4,14,2};
  cout << s.totalHammingDistance(vec);
  cout << endl;
  return 0;
}
