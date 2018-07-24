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
    int numOfMatch(string& w1, string& w2) {
        int res = 0;
        for (int i = 0; i < w1.length(); i++)
            if (w1[i] == w2[i])
                res++;
        return res;
    }
    void shrinkWordList(vector<string>& wordlist, string& word, int matches) {
        vector<string> next_wordlist;
        for (string& w : wordlist) {
            if (numOfMatch(w, word) == matches)
                next_wordlist.push_back(w);
        }
        wordlist = next_wordlist;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        string word = wordlist[rand() % wordlist.size()];
        for (int i = 0; i < 10; i++) {
            int matches = master.guess(word);
            if (matches == 6)
                return;
            shrinkWordList(wordlist, word, matches);
            word = wordlist[rand() % wordlist.size()];
        }
    }
};
