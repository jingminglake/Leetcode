#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        int resLen = num.size() - k;
        for (char c : num) {
            while (k && res.length() && res.back() > c) {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }
        res.resize(resLen);
        res.erase(0, res.find_first_not_of('0'));
        if (res.empty())
            res = "0";
        return res;
    }
};

int main() {
  Solution s;
  string num = "10200";
  int k = 1;
  cout << s.removeKdigits(num, k) << endl;
  return 0;
}
