class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            m[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& v1 = m[word1];
        vector<int>& v2 = m[word2];
        int left = 0, right = 0;
        int res = INT_MAX;
        while (left < v1.size() && right < v2.size()) {
            res = min (res, abs(v1[left] - v2[right]));
            if (v1[left] < v2[right]) left++;
            else right++;
        }
        return res;
    }
    unordered_map<string, vector<int> > m;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
