// clang++ maximumSwap.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  int maximumSwap(int num) {
    string ans = maximumSwapHelper(to_string(num));
    return stoi(ans);
  }
  string maximumSwapHelper(string num) {
    int len = num.length();
    if (len <= 1)
      return num;
    int maxIndex = 0;
    int maxNum = num[0] - '0';
    for (int i = 1; i < len; i++) {
      if (num[i] - '0' >= maxNum) {
	maxNum = num[i] - '0';
	maxIndex = i;
      }
    }
    if (maxIndex != 0 && num[maxIndex] - '0' > num[0] - '0') {
      swap(num[0], num[maxIndex]);
      return num;
    }
    else {
      return num[0] + maximumSwapHelper(num.substr(1));
    }
  }
};

int main()
{
  Solution s;
  cout << s.maximumSwap(98368) << endl;
  cout << s.maximumSwap(9973) << endl;
  return 0;
}
