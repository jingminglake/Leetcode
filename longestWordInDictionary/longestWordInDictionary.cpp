#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        string res;
        sort(words.begin(), words.end());
        unordered_set<string> s;
        for (string word : words) {
            string prev = word.substr(0, word.length() - 1);
            if (prev.empty() || s.count(prev)) {
                s.insert(word);
                if (word.size() > res.size())
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
