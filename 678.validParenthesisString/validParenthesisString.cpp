#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else {
                if (!left.empty())
                    left.pop();
                else if (!star.empty())
                    star.pop();
                else
                    return false;
            }
        }// for
        while (!left.empty() && !star.empty()) {
            if (left.top() > star.top()) {
                return false;
            }
            else {
                left.pop();
                star.pop();
            }
        }
        return left.empty();
    }
};

int main()
{
  Solution s;
  string p = "*(";
  string p2 = "(*)";
  string p3 = "(*))";
  string p4 = "((***)";
  cout << s.checkValidString(p) << endl;
  cout << s.checkValidString(p2) << endl;
  cout << s.checkValidString(p3) << endl;
  cout << s.checkValidString(p4) << endl;
  return 0;
}
