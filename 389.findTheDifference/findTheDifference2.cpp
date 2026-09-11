#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = t.back();
        for (int i = 0; i < s.length(); i++) {
            c ^= s[i];
            c ^= t[i];
        }
        return c;
    }
};

int main()
{
  Solution s;
  string ss = "abcd";
  string p = "abcde";
  cout << s.findTheDifference(ss, p);
  cout << endl;
  return 0;
}
