#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> countBits(int num) {
    vector<int> ans(num+1, 0);
    for (int i = 1; i <= num; i++) {
      ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> res = s.countBits(5);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
