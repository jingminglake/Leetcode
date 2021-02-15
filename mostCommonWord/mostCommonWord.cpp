class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_m(banned.begin(), banned.end());
        for (char& c : paragraph) {
            if (isalpha(c)) c = tolower(c);
            else c = ' ';
        }
        unordered_map<string, int> m;
        istringstream iss(paragraph);
        string word = "";
        while (iss >> word) {
            if (!banned_m.count(word)) {
                m[word]++;
            }
        }
        string res = "";
        int maxN = 0;
        for (auto& p : m) {
            if (p.second > maxN) {
                res = p.first;
                maxN = p.second;
            }
        }
        return res;
    }
};
