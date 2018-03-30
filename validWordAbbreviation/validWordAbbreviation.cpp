#include <iostream>
using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if (word.size() == 0 || abbr.size() == 0)
            return false;
        int i = 0, j = 0;
        while (i < abbr.size()) {
            if (word[j] == abbr[i]) {
                j++;
                i++;
                continue;
            }
            if (abbr[i] <= '0' || abbr[i] > '9')
                return false;
            int k = i;
            while (i < abbr.size() && abbr[i] >= '0' && abbr[i] <= '9') {
                i++;
            }
            int num = stoi(abbr.substr(k, i - k));
            j += num;
        }
        return j == word.size();
    }
};

int main() {
  Solution s;
  cout << s.validWordAbbreviation("internationalization", "i12iz4n") << endl;
  return 0;
}
