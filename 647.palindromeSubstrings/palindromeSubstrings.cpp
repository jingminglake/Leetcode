// clang++ palindromeSubstrings.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int countSubstrings(string s) {
    int res = 0;
    int size = s.length();
    if (size == 0)
      return 0;
    for (int i = 0; i < size; i++) { //i is mid point
      extendPalindrome(s, i, i, res);//odd
      extendPalindrome(s, i, i + 1, res);//even
    }
    return res;
  }
  void extendPalindrome(string s, int left, int right, int& res) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
      res++;
      left--;
      right++;
    }
  }
};

int main()
{
  Solution s;
  string ss1 = "abc";
  string ss2 = "aaa";
  cout << s.countSubstrings(ss1) << endl;
  cout << s.countSubstrings(ss2) << endl;
  return 0;
}
