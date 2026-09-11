//clang++ judgeRouteCircle.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  bool judgeCircle(string moves) {
    int v = 0, h = 0;
    for (char ch : moves) {
      switch(ch) {
      case 'U' : v++; break;
      case 'D' : v--; break;
      case 'R' : h++; break;
      case 'L' : h--; break;
      }
    }
    return v == 0 && h == 0;
  }
};
int main(void)
{
  Solution s;
  string moves = "UDLLRRU";
  cout << s.judgeCircle(moves) << endl;
  return 0;
}
