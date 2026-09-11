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
    int res = 0;
    for (int i = 0; i < 8 * sizeof(int); i++) {
      if ((n & 1) == 1)
	res++;
      n >>= 1;
    }
    return res;
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
