#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> plusOne(vector<int>& digits) {
    int size = digits.size();
    vector<int> ans(size, 0);
    int carry = 1;
    for (int i = size-1; i >= 0; i--) {
      int sum = digits[i] + carry;
      ans[i] = (sum % 10);
      carry = sum / 10;
    }
    if (carry == 1)
      ans.insert(ans.begin(), 1);
    return ans;
  }
};

int main()
{
  Solution s;
  int a[5] = {9,9,9,9,9};
  vector<int> vec(a, a+5);
  vector<int> res = s.plusOne(vec);
  vector<int>::iterator it = res.begin();
  while (it != res.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  return 0;
}
