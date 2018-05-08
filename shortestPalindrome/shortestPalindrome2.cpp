// clang++ shortestPalindrome.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j])
                i++;
        }
        if (i == n)
            return s;
        string remain_rev = s.substr(i, n);
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};

int main()
{
  Solution s;
  string ss = "aacecaaa";
  cout << s.shortestPalindrome(ss) << endl;
  return 0;
}
