#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
  int evalRPN(vector<string>& tokens) {
    if (tokens.size() == 0)
      return 0;
    stack<int> s;
    for (string token : tokens) {
      if (token == "+") {
	int num1 = s.top();
	s.pop();
	int num2 = s.top();
	s.pop();
	s.push(num1 + num2);
      } else if (token == "-") {
	int num1 = s.top();
	s.pop();
	int num2 = s.top();
	s.pop();
	s.push(num2 - num1);
      } else if (token == "*") {
	int num1 = s.top();
	s.pop();
	int num2 = s.top();
	s.pop();
	s.push(num2 * num1);
      } else if (token == "/") {
	int num1 = s.top();
	s.pop();
	int num2 = s.top();
	s.pop();
	s.push(num2 / num1);
      } else {
	s.push(stoi(token));
      }
    }
    return s.top();
  }
};

int main()
{
  Solution s;
  vector<string> vec = {"4", "13", "5", "/", "+"};
  cout << s.evalRPN(vec);
  cout << endl;
  return 0;
}
