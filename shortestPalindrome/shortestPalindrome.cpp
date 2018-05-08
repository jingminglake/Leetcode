// clang++ shortestPalindrome.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string res;
        string rs(s.rbegin(), s.rend());
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s.substr(0, n - i) == rs.substr(i)) {
                return rs.substr(0, i) + s;
            }
        }
        return res;
    }
};

int main()
{
  Solution s;
  string ss = "aacecaaa";
  cout << s.shortestPalindrome(ss) << endl;
  return 0;
}
