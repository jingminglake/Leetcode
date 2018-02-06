#include <iostream>
using namespace std;

class Solution{
public:
  bool isOneEditDistance(string s, string t) {
        for (int i = 0; i < min (s.length(), t.length()); i++) {
            if (s[i] != t[i]) {
                int diff = ((int)s.length() - (int)t.length());
                if (diff == 0)
                    return s.substr(i + 1) == t.substr(i + 1);
                else if (diff == 1)
                    return s.substr(i + 1) == t.substr(i);
                else if (diff == -1)
                    return s.substr(i) == t.substr(i + 1);
                else
                    return false;
            }
        }
        return abs((int)s.length() - (int)t.length()) == 1;
    }
};

int main()
{
  Solution s;
  string ss = "ab";
  string tt = "abc";
  cout << s.isOneEditDistance(ss, tt) << endl;
  return 0;
}
