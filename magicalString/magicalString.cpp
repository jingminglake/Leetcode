#include <iostream>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if (n == 0)
            return 0;
        int res = 1;
        string s = "122";
        int p = 2;
        while (s.length() < n) {
            char temp = s.back() == '1' ? '2' : '1';
            s += string(s[p] - '0', temp);
            if (temp == '1')
                res += s[p] - '0';
            p++;
        }
        if (s.length() > n && s.back() == '1')
            res--;
        return res;
    }
};

int main() {
  Solution s;
  cout << s.magicalString(4) << endl;
  return 0;
}
