#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
  bool isValid(string s) {
    if (s.empty())
      return true;
    stack<char> ss;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
	ss.push(s[i]);
      } else if (s[i] == ')') {
	if (!ss.empty() && ss.top() == '(') 
	  ss.pop();
	else
	  return false;
      } else if (s[i] == '}') {
	if (!ss.empty() && ss.top() == '{')
	  ss.pop();
	else
	  return false;
      } else if (s[i] == ']') {
	if (!ss.empty() && ss.top() == '[')
	  ss.pop();
	else
	  return false;
      }
    }
    return ss.empty();
  }
};

int main()
{
  Solution s;
  cout << s.isValid(string("{}{}{}{}[][]")) << endl;
  return 0;
}
