#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, string> parent;
    string find_op(string& word) {
        if (!parent.count(word))
            return parent[word] = word;
        else if (parent[word] == word)
            return word;
        else
            return parent[word] = find_op(parent[word]);
    }
    void union_op(string& word1, string& word2) {
        string p1 = find_op(word1);
        string p2 = find_op(word2);
        if (p1 != p2) {
            parent[p1] = p2;
        }
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size())
            return false;
        for (auto& p : pairs) {
            union_op(p.first, p.second);
        }
        for (int i = 0; i < words1.size(); i++) {
            if (find_op(words1[i]) != find_op(words2[i]))
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<string> words1 = {"great", "acting", "skills"};
    vector<string> words2 = {"fine", "drama", "talent"};
    vector<pair<string, string> > pairs = {{"great", "good"}, {"fine", "good"}, {"acting","drama"}, {"skills","talent"}};
    cout << s.areSentencesSimilarTwo(words1, words2, pairs) << endl;
    return 0;
}
