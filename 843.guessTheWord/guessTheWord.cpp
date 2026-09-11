/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        string word = wordlist[rand() % wordlist.size()];
        for (int i = 0; i < 10; i++) {
            int res = master.guess(word);
            if (res == 6)
                return;
            shrinkWordlist(wordlist, res, word);
            word = wordlist[rand() % wordlist.size()];
        }
    }
    void shrinkWordlist(vector<string>& wordlist, int res, string& word) {
        vector<string> new_wordlist;
        for (auto& w : wordlist) {
            if (isSimilarWord(w, res, word))
                new_wordlist.push_back(w);
        }
        wordlist = new_wordlist;
    }
    bool isSimilarWord(string& word1, int res, string& word2) {
        int count = 0;
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] == word2[i])
                count++;
        }
        return count == res;
    }
};
