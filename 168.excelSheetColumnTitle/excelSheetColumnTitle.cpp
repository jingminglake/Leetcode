#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
  string convertToTitle(int n) {
     string ans = "";
     convert(n, ans);
     return ans;
  }
  void convert(int n, string& ans) {
    if (n <= 26) {
      ans += 'A' + n - 1;
    }
    else {
      convert((n-1)/26, ans);
      ans += 'A' + (n-1)%26;
      // cout << ans << "---" << endl;
    }
  }
};

int main()
{
  Solution s;
  cout << s.convertToTitle(10000)<< endl;
  return 0;
}
