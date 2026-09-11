#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int i = digits.size() - 1;
        int carry = 1;
        while (i >= 0 || carry == 1) {
            int sum = carry;
            if (i >= 0) {
                sum += digits[i];
                i--;
            }
            carry = sum / 10;
            res.push_back(sum % 10);
        }
        reverse(res.begin(), res.end());
        return res;
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
