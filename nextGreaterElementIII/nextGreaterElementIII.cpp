#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int nextGreaterElements(int n) {
    string s = to_string(n);
    int size = s.length();
    int i = size - 1;
    while (i >= 1 && s[i-1] >= s[i]) {
      i--;
    }
    if (i == 0)
      return -1;
    int p1 = i - 1;
    while (i < size) {
      if (s[++i] <= s[p1]) {
	swap(s[i-1], s[p1]);
	reverse(s.begin() + p1 + 1, s.end());
	break;
      }
    }
    long ans =  stol(s);
    return ans > INT_MAX ? -1 : ans;
  }
};

int main()
{
  Solution s;
  cout << s.nextGreaterElements(1999999999);
  cout << endl;
  return 0;
}
