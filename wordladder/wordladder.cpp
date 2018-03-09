#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 0;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord))
            return res;
        if (!bfs(beginWord, endWord, wordSet, res))
            return 0;
        else
            return res;
    }
    bool bfs(string beginWord, string endWord, unordered_set<string>& wordSet, int& res) {
        unordered_set<string> start, end;
        start.insert(beginWord);
        end.insert(endWord);
        res++;
        while (!start.empty() && !end.empty()) {
            if (start.size() > end.size())
                start.swap(end);
            unordered_set<string> next;
            res++;
            for (string word : start) {
                for (int i = 0; i < word.length(); i++) {
                    string nextWord = word;
                    for (int j = 0; j < 26; j++) {
                        if (word[i] == 'a' + j)
                            continue;
                        nextWord[i] = 'a' + j;
                        if (!wordSet.count(nextWord))
                            continue;
                        if (end.count(nextWord)) {
                            return true;
                        } else {
                            next.insert(nextWord);
                        }
                    }//for
                }//for
		wordSet.erase(word);
            }//for
            start = next;
        }//while
        return false;
    }
};

int main()
{
  Solution s;
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "lot", "log", "cog"};
  cout << s.ladderLength(beginWord, endWord, wordList) << endl;
  return 0;
}
