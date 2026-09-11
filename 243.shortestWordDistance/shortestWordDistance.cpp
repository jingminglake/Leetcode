#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX;
        pair<int, int> prev = {0, 0}; // first -> wordx ; second ->index
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                if (prev.first == 2) {
                    res = min (res, i - prev.second);
                }
                prev = {1, i};
            } else if (words[i] == word2) {
                if (prev.first == 1) {
                    res = min (res, i - prev.second);
                }
                prev = {2, i};
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    string word1 = "coding";
    string word2 = "practice";
    cout << s.shortestDistance(words, word1, word2) << endl;
    return 0;
}
