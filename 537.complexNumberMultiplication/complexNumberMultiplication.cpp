// clang++ complexNumberMultiplication.cpp -std=c++11

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;


class Solution{
public:
  string complexNumberMultiply(string a, string b) {
    string ans = "";
    istringstream iss(a), iss2(b);
    string realPartA, voidPartA, realPartB, voidPartB;
    getline(iss, realPartA, '+');
    getline(iss, voidPartA, 'i');
    getline(iss2, realPartB, '+');
    getline(iss2, voidPartB, 'i');
    ans = to_string(stoi(realPartA) * stoi(realPartB) - stoi(voidPartA) * stoi(voidPartB)) + "+" + to_string(stoi(realPartA) * stoi(voidPartB) + stoi(voidPartA) * stoi(realPartB)) + "i";
    return ans;
  }
};

int main()
{
  Solution s;
  string s1 = "1+-1i";
  string s2 = "1+-1i";
  cout << s.complexNumberMultiply(s1, s2);
  cout << endl;
  return 0;
}
