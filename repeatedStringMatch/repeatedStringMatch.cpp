#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int repeatedStringMatch(string A, string B) {
    int res = 0;
    string AS = "";
    while (AS.length() < B.length()) {
      AS += A;
      res++;
    }
    if (AS.find(B) != string::npos)
      return res;
    AS += A;
    if (AS.find(B) != string::npos)
      return res + 1;
    return -1;
  }
};

int main()
{
  Solution s;
  string A = "abcd";
  string B = "cdabcdab";
  cout << s.repeatedStringMatch(A, B) << endl;
  return 0;
}
