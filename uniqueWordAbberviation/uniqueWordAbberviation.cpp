class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (string& word : dictionary) {
            string key = getKey(word);
            if (m.count(key)) {
                if (m[key] != word) {
                    m[key] = "";
                }
            } else {
                m[key] = word;
            }
        }
    }
    
    bool isUnique(string word) {
        string key = getKey(word);
        return !m.count(key) || m[key] == word;
    }
    string getKey(string& word) {
        if (word.length() < 2)
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
