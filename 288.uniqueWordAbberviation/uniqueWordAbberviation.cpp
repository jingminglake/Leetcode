class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (string& word : dictionary) {
            string abbr = getAbbr(word);
            if (m.count(abbr)) {
                if (word != m[abbr])
                    m[abbr] = "";                    
            } else {
                m[abbr] = word;
            }
        }
    }
    
    bool isUnique(string word) {
        string abbr = getAbbr(word);
        return !m.count(abbr) || m[abbr] == word;
    }
    string getAbbr(string word) {
        if (word.length() <= 2)
            return word;
        return word[0] + to_string(word.length() - 2) + word.back();
    }
    unordered_map<string, string> m;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
