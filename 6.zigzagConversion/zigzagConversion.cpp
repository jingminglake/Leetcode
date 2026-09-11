#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        int i = 0;
        while (i < s.length()) {
            for (int j = 0; j < numRows && i < s.length(); j++) { // up to down
                rows[j] += s[i++];
            }
            for (int j = numRows - 2; j >= 1 && i < s.length(); j--) {
                rows[j] += s[i++];
            }
        }
        string res = "";
        for (string& row : rows)
            res += row;
        return res;
    }
};

int main()
{
  Solution s;
  string ss = "ABCDE";
  cout << s.convert(ss, 3) << endl;
  return 0;
}
