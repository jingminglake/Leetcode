#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<string> readBinaryWatch(int num) {
    vector<string> ans;
    for (int h = 0; h < 12; h++)
      for (int m = 0; m < 60; m++) {
	if (bitCount(h * 64 + m) == num) {
	  char buffer[5];
	  sprintf(buffer, "%d:%02d", h, m);
	  string str = buffer;
	  ans.push_back(str);
	}
      }
    return ans;
  }
  int bitCount(int n) {
    size_t numOf1 = 0;
    for (size_t i = 0; i < CHAR_BIT * sizeof(n); i++) {
      if ((n & 1) == 1)
	numOf1++;
      n >>= 1;
    }
    return numOf1;
  }
};

int main()
{
  Solution s;
  vector<string> vec = s.readBinaryWatch(1);
  for (string s : vec)
    cout << s << " ";
  cout << endl;
  return 0;
}
