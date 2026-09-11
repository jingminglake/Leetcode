class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string& word : dict) {
            for (int i = 0; i < word.size(); i++) {
                char c = word[i];
                word[i] = '#';
                m[word].insert(c);
                word[i] = c;
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            word[i] = '#';
            if (m.count(word)) {
                if (!m[word].count(c) || m[word].size() > 1)
                    return true;
            }
            word[i] = c;
        }
        return false;
    }
    unordered_map<string, unordered_set<char> > m;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
