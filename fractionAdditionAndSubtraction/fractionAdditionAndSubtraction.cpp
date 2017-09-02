// clang++ fractionAdditionAndSubtraction.cpp -std=c++11

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;


class Solution{
public:
  string fractionAddition(string expression) {
    string ans = "";
    istringstream iss(expression);
    long leftNumerator = 0, leftDenominator = 1, rightNumerator, rightDenominator;
    char op;
    while (iss >> rightNumerator >> op >> rightDenominator) {
      leftNumerator = leftNumerator * rightDenominator + leftDenominator * rightNumerator;
      leftDenominator *= rightDenominator;
      long g = abs(__gcd(leftNumerator, leftDenominator));
      leftNumerator /= g;
      leftDenominator /= g;
    }
    return to_string(leftNumerator) + "/" + to_string(leftDenominator);
  }
};

int main()
{
  Solution s;
  string exp = "-1/2+1/2+1/3";
  cout << s.fractionAddition(exp);
  cout << endl;
  return 0;
}
