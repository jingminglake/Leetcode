#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> s;
        for (string& word : words) s.insert(word);
        string res;
        for (string word : words) {
            bool flag = true;
            for (int i = 1; i <= word.length(); i++) {
                string w = word.substr(0, i);
                if (!s.count(w)) {
                    flag = false;
                    break;
                }
            }
            if (flag && (word.length() > res.length() || (word.length() == res.length() && word < res))) {
                res = word;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"a","banana", "app", "appl", "ap", "apply", "apple"};
    cout << s.longestWord(words) << endl;
    return 0;
}
