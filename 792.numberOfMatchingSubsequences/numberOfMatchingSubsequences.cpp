#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<char*> waiting[128];  //128 buckets
        for (string& w : words) {
            waiting[w[0]].push_back(const_cast<char*>(w.c_str() ) );
        }
        for (char c : S) {
            vector<char*> tempWords = waiting[c];
            waiting[c].clear();
            for (char* p : tempWords)
                waiting[*++p].push_back(p);
        }
        return waiting[0].size(); // 0 <=> '\0'
    }
};

int main() {
  Solution s;
  string S = "abcde";
  vector<string> words = {"a", "bb", "acd", "ace"};
  cout << s.numMatchingSubseq(S, words) << endl;
  return 0;
}
