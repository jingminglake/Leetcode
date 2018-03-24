#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if (s.length() < 2)
            return res;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '+' && s[i] == s[i - 1]) {
                string temp = s;
                temp[i - 1] = temp[i] = '-';
                res.push_back(temp);
            }
        }
        return res;
    }
};

int main() {
  Solution s;
  for(string& ss : s.generatePossibleNextMoves("++++")) {
    cout << ss << endl;
  }
  return 0;
}
