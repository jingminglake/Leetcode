#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
  string decodeString(string s) {
    string ans;
    int size = s.length();
    stack<int> kStack;
    stack<string> encoded_stringStack;
    int i = 0;
    while (i < size) {
      char c = s[i];
      if (isalpha(c)) {
	while (isalpha(s[i])) {
	  ans += s[i++];
	}
      } else if (isdigit(c)) {
	 int start = i;
	 while (isdigit(s[i]))
	   i++;
	 int k = i > start ? stoi(s.substr(start, i - start)) : 0;
	 kStack.push(k);
      } else if (c == '[') {
	encoded_stringStack.push(ans);
	ans = "";
	i++;
      } else if (c == ']') {
	string temp = encoded_stringStack.top();
	encoded_stringStack.pop();
	int repeatTimes =  kStack.top();
	kStack.pop();
	for (int j = 0; j < repeatTimes; j++) {
	  temp += ans;
	}
	ans = temp;
	i++;
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string ss = "3[a2[c]]";
  cout << s.decodeString(ss);
  cout << endl;
  return 0;
}
