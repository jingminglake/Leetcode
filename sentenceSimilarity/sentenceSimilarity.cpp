#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size())
            return false;
        unordered_map<string, unordered_set<string> > m;
        for (auto& p : pairs) {
            m[p.first].insert(p.second);
            m[p.second].insert(p.first);
        }
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] != words2[i] && !m[words1[i]].count(words2[i]) && !m[words2[i]].count(words1[i])) {
                return false;
            }
        }
        return true;
    }
};

int main() {
  Solution s;
  vector<pair<string, string>> pairs = {{"great","fine"},{"drama","acting"},{"skills","talent"}};
  vector<string> words1 = {"great","acting","skills"};
  vector<string> words2 = {"fine","drama","talent"};
  cout << s.areSentencesSimilar(words1, words2, pairs) << endl;
  return 0;
}
