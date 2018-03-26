#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.length() == 0 || k == 0)
            return s;
        int cnt = s.length() / k;
        for (int i = 0; i <= cnt; i++) {
            if (i % 2 == 0) {
                if (i * k + k < s.length())
                    reverseHelper(s, i*k, i*k + k - 1);
                else
                    reverseHelper(s, i*k, s.length() - 1);
            }
        }
        return s;
    }
    void reverseHelper(string& s, int i, int j) {
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
};

int main()
{
  Solution s;
  string str = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
  cout << s.reverseStr(str, 39) << endl;
  return 0;
}
