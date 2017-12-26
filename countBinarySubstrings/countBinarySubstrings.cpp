#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int countBinarySubstrings(string s) {
    int res = 0;
    int prevLength = 0; // length of pre sequence 0 or 1
    int curLength = 1;
    for (int i = 1; i < s.length(); i++) {
      if (s[i] == s[i - 1])
	curLength++;
      else {
	prevLength = curLength;
	curLength = 1;
      }
      if (prevLength >= curLength)
	res++;
    }
    return res;
  }
};

int main()
{
  Solution s;
  string ss = "00110011";
  cout << s.countBinarySubstrings(ss) << endl;
  return 0;
}
