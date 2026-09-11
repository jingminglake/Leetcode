#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if (words.size() == 0)
            return false;
        int m = words.size(), n = words[0].size();
        if (m != n)
            return false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (i == j)
                    continue;
                if (j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i])
                    return false;
            }
        }
        return true;
    }
};

int main() {
  vector<string> words = {"abcd", "bnrt", "crm", "dt"};
  Solution s;
  cout << s.validWordSquare(words) << endl;
  return 0;
}
