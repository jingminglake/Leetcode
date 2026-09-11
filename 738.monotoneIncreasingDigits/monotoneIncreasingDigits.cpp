#include <iostream>
using namespace std;

class Solution{
public:
  int monotoneIncreasingDigits(int N) {
    string number = to_string(N);
    int k = number.size();
    for (int i = number.size() - 1; i > 0; i--) {
      if (number[i] < number[i - 1]) {
	k = i;
	number[i - 1] = number[i - 1] - 1;
      }
    }
    for (int i = k; i < number.size(); i++)
      number[i] = '9';
    return stoi(number);
  }
};

int main()
{
  Solution s;
  int N = 1444367;
  int N2 = 0000;
  cout << s.monotoneIncreasingDigits(N) << endl;
  cout << s.monotoneIncreasingDigits(N2) << endl;
  return 0;
}
