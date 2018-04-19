#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        if (S.length() == 0)
            return res;
        unordered_map<char, pair<int, int> > m;
        for (int i = 0; i < S.length(); i++) {
            if (!m.count(S[i])) {
                 m[S[i]].first = i;
                 m[S[i]].second = i;
            } else {
                 m[S[i]].second = i;
            }
        }
        int left = m[S[0]].first, right = m[S[0]].second;
        for (int i = 1; i < S.length(); i++) {
            if (m[S[i]].first > right) {
                res.push_back(right - left + 1);
                left = m[S[i]].first;
                right = m[S[i]].second;
            } else {
                right = max (right, m[S[i]].second);
            }
        }
        res.push_back(right - left + 1);
        return res;
    }
};

int main() {
    Solution s;
    string S = "ababcbacadefegdehijhklij";
    for(int& v : s.partitionLabels(S))
        cout << v << " ";
    cout << endl;
    return 0;
}
