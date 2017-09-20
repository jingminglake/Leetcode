// clang++ canIWin.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (maxChoosableInteger >= desiredTotal)
      return true;
    if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
      return false;
    unordered_map<int, bool> m;
    return canWin(maxChoosableInteger, desiredTotal, 0, m);
  }
  bool canWin(int length, int total, int used, unordered_map<int, bool>& m) {
    if (m.count(used))
      return m[used];
    for (int i = 0; i < length; i++) {
      int cur = (1 << i); // 2^i, length <= 20
      if ((cur & used) == 0) { // not used
	if (total <= i + 1 || !canWin(length, total - (i + 1), cur | used, m)) {
	  m[used] = true;
	  return true;
	}
      }
    }
    m[used] = false;
    return false;
  }
};

int main()
{
  Solution s;
  cout << s.canIWin(10, 11) << endl;
  return 0;
}
