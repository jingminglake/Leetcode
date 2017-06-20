#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<string> fizzBuzz(int n) {
    vector<string> ans;
    string str[3] = {"Fizz", "Buzz", "FizzBuzz"};
    for (int i = 1; i <= n; i++) {
      if (i % 15 == 0)
	ans.push_back(str[2]);
      else if (i % 5 == 0)
	ans.push_back(str[1]);
      else if (i % 3 == 0)
	ans.push_back(str[0]);
      else
	ans.push_back(to_string(i));
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<string> vec = s.fizzBuzz(20);
  for (string str : vec)
    cout << str << endl;
  return 0;
}
