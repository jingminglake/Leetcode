#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  string originalDigits(string s) {
    string res = "";
    int count[10] = {0};
    int size = s.length();
    // unique letters : z,w,u,x,g
    for (int i = 0; i < size; i++) {
      switch (s[i]) {
      case 'z':
	count[0]++; // 0 -> z
	break;
      case 'w':
	count[2]++; // 2 -> w
	break;
      case 'u':
	count[4]++; // 4 -> u
	break;
      case 'x':
	count[6]++; // 6 -> x
	break;
      case 'g': // 8 -> g
	count[8]++;
	break;
      case 's': // 6,7 -> s
	count[7]++;
	break;
      case 'f': // 4,5 -> f
	count[5]++;
	break;
      case 'h': // 3,8 -> h
	count[3]++;
	break;
      case 'i':
	count[9]++; // 5,6,8,9 -> i
	break;
      case 'o':
	count[1]++; // 0,1,2,4 -> o
	break;
      }// switch
    }//for
    count[7] -= count[6];
    count[5] -= count[4];
    count[3] -= count[8];
    count[9] = count[9] - count[5] - count[6] - count[8];
    count[1] = count[1] - count[0] - count[2] - count[4]; 
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < count[i]; j++)
	res += i + '0';
    }
    return res;
  }
};

int main()
{
  Solution s;
  string ss = "owoztneoer";
  cout << s.originalDigits(ss) << endl;
  return 0;
}
