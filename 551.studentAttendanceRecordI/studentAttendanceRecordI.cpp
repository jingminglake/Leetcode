#include <iostream>
#include <sstream>
using namespace std;

class Solution{
public:
  bool checkRecord(string s) {
    int countA = 0, countL = 0;
    for(int i = 0; i < s.length(); i++) {
      if (s[i] == 'A')
	countA++;
      if (s[i] == 'L') {
	countL++;
	if (countL > 2)
	  return false;
      } else {
	countL = 0;
      }
    }
    return countA < 2;
  }
};

int main()
{
  Solution s;
  string str = "PPALLL";
  cout << s.checkRecord(str) << endl;
  return 0;
}
