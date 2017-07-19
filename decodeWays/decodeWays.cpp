#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int numDecodings(string s) {
    int size = s.length();
    if (size == 0)
      return 0;
    vector<int> m(size, 0);
    m[0] = s[0] == '0' ? 0 : 1;
    if (size == 1)
      return m[0];
    int oneBit = stoi(s.substr(1, 1));
    int twoBits = stoi(s.substr(0, 2)); 
    if (oneBit >= 1 && oneBit <= 9)
      m[1] += m[0];
    if (twoBits >= 10 && twoBits <= 26)
      m[1] += 1;
    if (size == 2)
      return m[1];
    for (int i = 2; i < size; i++) {
      oneBit = stoi(s.substr(i, 1));
      if(oneBit >= 1 && oneBit <= 9) {
	m[i] += m[i-1];
      }
      twoBits = stoi(s.substr(i-1, 2));
      if (twoBits >= 10 && twoBits <= 26)
	m[i] += m[i-2];
    }
    return m[size-1];
  }
};

int main()
{
  Solution s;
  string ss = "27";
  cout << s.numDecodings(ss);
  cout << endl;
  return 0;
}
