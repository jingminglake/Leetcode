#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> wordSet;
        for (string& word : words) wordSet.insert(word);
        unordered_map<string, bool> buildable;
        string longestWord;
        for (string& word : words) {
            if (word.length() < longestWord.length()) continue;
            if (word.length() == longestWord.length() && word >= longestWord) continue;
            if (dfs(word, buildable, wordSet)) {
                longestWord = word;
            }
        }
        return longestWord;
     }
    bool dfs(string word, unordered_map<string, bool>& buildable, unordered_set<string>& wordSet) {
        if (word.length() == 1 && wordSet.count(word)) {
            return buildable[word] = true;
        }
        if (buildable.count(word)) {
            return buildable[word];
        }
        if (!wordSet.count(word)) {
            return buildable[word] = false;
        }
        string prev = word.substr(0, word.length() - 1);
        return buildable[word] = dfs(prev, buildable, wordSet);
    }
};

int main()
{
    Solution s;
    vector<string> words = {"a","banana", "app", "appl", "ap", "apply", "apple"};
    cout << s.longestWord(words) << endl;
    return 0;
}
