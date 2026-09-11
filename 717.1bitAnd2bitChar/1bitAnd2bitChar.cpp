#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool isOneBitCharacter(vector<int>& bits) {
    int size = bits.size();
    int i = 0;
    while (i < size - 1) {
      if (bits[i] == 1)
	i += 2;
      else
	i++;
    }
    return i == size - 1;
  }
};

int main()
{
  Solution s;
  vector<int> ss1 = {1,0,0};
  vector<int> ss2 = {1,1,1,0};
  vector<int> ss3 = {0,0,1,1,0,0,1,1};
  cout << s.isOneBitCharacter(ss1) << endl;
  cout << s.isOneBitCharacter(ss2) << endl;
  cout << s.isOneBitCharacter(ss3) << endl;
  return 0;
}
