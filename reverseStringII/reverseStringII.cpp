#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  string reverseStr(string s, int k) {
    int size = s.length();
    int count = size / k * 0.5;
    bool flag = false;
    if (size % (2*k) >= k)
      count++;
    else
      flag = true;
    for (int i = 0; i < count; i++) {
      swap(s, i * k * 2, i * k * 2 + k - 1);
    }
    if (flag){
      swap(s,  count * 2 * k, size - 1);
    }
    return s;
  }
  void swap(string &s, int l, int r) {
    while (l < r) {
      char temp = s[l];
      s[l] = s[r];
      s[r] = temp;
      l++;
      r--;
    }
  }
};

int main()
{
  Solution s;
  string str = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
  cout << s.reverseStr(str, 39) << endl;
  return 0;
}
