#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res;
        if (s.empty()) return res;
        int i = 0;
        reverse(s);
        while (i < s.length()) {
            while (i < s.length() && s[i] == ' ')
                i++;
            string word;
            while (i < s.length() && s[i] != ' ') {
                word += s[i++];
            }
            if (word.length() > 0) {
                reverse(word);
                res += word + " ";
            }
        }
        if (res.length() > 0)
            res.pop_back();
        return res;
    }
    void reverse(string& s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            left++;
            right--;
        }
    }
};

int main()
{
  Solution s;
  string ss = "the   sky  is ";
  ss = s.reverseWords(ss);
  cout << ss;
  cout << endl;
  return 0;
}
