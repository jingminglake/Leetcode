// clang++ sumOfSquareNumbers.cpp

#include <iostream>
#include <cmath>
using namespace std;


class Solution{
public:
  bool judgeSquareSum(int c) {
    /*long left = 0, right = (int)sqrt(c);
      while (left <= right) {
        long sum = left * left + right * right;
        if (sum > c)
	      right--;
        else if(sum < c)
	      left++;
        else
	      return true;
      }
      return false; */
    for (int i = 0; i <= floor(sqrt(c)); i++) {
      if (floor(sqrt(c - i * i)) == sqrt(c - i * i))
	return true;
    }
    return false;
  }
};

int main()
{
  Solution s;
  cout << s.judgeSquareSum(3);
  cout << endl;
  return 0;
}
