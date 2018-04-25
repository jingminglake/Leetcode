#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size())
            return false;
        unordered_map<string, string> parent;
        for (auto& p : pairs) {
            union_op(parent, p.first, p.second);
        }
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] != words2[i] && find_op(parent, words1[i]) != find_op(parent, words2[i]))
                return false;
        }
        return true;
    }
    void union_op(unordered_map<string, string>& parent, string node1, string node2) {
        string p1 = find_op(parent, node1);
        string p2 = find_op(parent, node2);
        if (p1 != p2) {
            parent[p1] = p2;
        }
    }
    string find_op(unordered_map<string, string>& parent, string node) {
        if (!parent.count(node))
            parent[node] = node;
        if (parent[node] == node)
            return node;
        return parent[node] = find_op(parent, parent[node]);
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
