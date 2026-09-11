#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> grayCode(int n) {
    vector<int> ans;
    for (int i = 0; i < (1 << n); i++)
      ans.push_back(i ^ i>>1);
    return ans;
  }
  unsigned int binaryToGray(unsigned int num) {
    return (num >> 1)^num;
  }
  unsigned int grayToBinary(unsigned int num) {
    for (unsigned int mask = num >> 1; mask != 0; mask = mask >> 1) {
      num = num ^ mask;
    }
    return num;
  }
};

int main()
{
  Solution s;
  vector<int> res = s.grayCode(3);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
