#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  string reverseString(string s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
      swap(s[i++], s[j--]);
    }
    return s;
  }
  void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
  }
};

int main()
{
  Solution s;
  string str = "hello";
  cout << s.reverseString(str) << endl;
  return 0;
}
