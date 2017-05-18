#include <iostream>
using namespace std;

class Solution{
public:
  bool isPalindrome(int x) {
    if(x < 0)
      return false;
    bool ans = true;
    int high = 1, low = 1;
    int xx = x;
    while(xx >= 10) {
      high *= 10;
      xx = xx / 10;
    }
    while(high > low) {
      if( ((x / high) % 10) != ((x / low) % 10) ){	
	ans = false;
	break;
      }
      high = high / 10;
      low = low * 10;
    }
    //cout << high << endl;
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.isPalindrome(10) << endl;
  return 0;
}
