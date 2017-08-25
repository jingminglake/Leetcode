// clang++ bullsAndCows.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  string getHint(string secret, string guess) {
    int numOfBulls = 0, numOfCows = 0;
    int len = secret.length();
    vector<int> hash(10, 0);
    for (int i = 0; i < len; i++) {
      if (secret[i] == guess[i]) {
	numOfBulls++;
      }
      else {
	++hash[secret[i] - '0'];
      }
    }
    for (int i = 0; i < len; i++) {
      if (secret[i] != guess[i] && --hash[guess[i] - '0'] >= 0)
	numOfCows++;
    }
    string ans = to_string(numOfBulls) + "A" + to_string(numOfCows) + "B";
    return ans;
  }
};

int main()
{
  Solution s;
  string s1 = "1122";
  string s2 = "2211";
  cout << s.getHint(s1, s2);
  cout << endl;
  return 0;
}
