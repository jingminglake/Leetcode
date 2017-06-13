#include <iostream>
#include <sstream>
using namespace std;

class Solution{
public:
  string reverseWords(string s) {
    string ans;
    istringstream iss(s);
    string word;
    while (getline(iss, word, ' ')) {
      reverse(word);
      ans += word + ' ';
    }
    ans.pop_back();
    return ans;
  }
  void reverse(string& s) {
    int i = 0;
    int j = s.length() - 1;
    char temp;
    while (i < j) {
      temp = s[i];
      s[i] = s[j];
      s[j] = temp;
      i++;
      j--;
    }
  }
};

int main()
{
  Solution s;
  string str = "hello world";
  cout << s.reverseWords(str) << endl;
  return 0;
}
