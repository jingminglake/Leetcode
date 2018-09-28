#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string res;
        vector<int> matched(S.length(), -1);
        for (int i = 0; i < sources.size(); i++) {
            if (S.substr(indexes[i], sources[i].length()) == sources[i]) {
                matched[indexes[i]] = i;
            }
        }
        int i = 0;
        while (i < S.length()) {
            if (matched[i] != -1) {
                res += targets[matched[i]];
                i += sources[matched[i]].length();
            }
            else {
                res += S[i];
                i++;
            }
        }
        return res;
    }
};

int main() {
    string S = "abcd";
    vector<int> indexes = {0,2};
    vector<string> sources = {"ab","ec"}, targets = {"eee","ffff"};
    Solution s;
    cout << s.findReplaceString(S, indexes, sources, targets) << endl;
    return 0;
}
