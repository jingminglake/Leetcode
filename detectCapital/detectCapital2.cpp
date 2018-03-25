#include <iostream>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 0)
            return true;
        if (word[0] >= 'A' && word[0] <= 'Z') {
            return allCap(word, 1, word.size() - 1) || allSml(word, 1, word.size() - 1);
        } else {
            return allSml(word, 1, word.size() - 1);
        }
    }
    bool allCap(string word, int i, int j) {
        for (int k = i; k <= j; k++) {
            if (word[k] < 'A' || word[k] > 'Z')
                return false;
        }
        return true;
    }
    bool allSml(string word, int i, int j) {
        for (int k = i; k <= j; k++) {
            if (word[k] < 'a' || word[k] > 'z')
                return false;
        }
        return true;
    }
};

int main()
{
  Solution s;
  string str = "aa";
  cout << s.detectCapitalUse(str) << endl;
  return 0;
}
