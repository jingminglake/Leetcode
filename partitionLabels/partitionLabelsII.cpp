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
        unordered_map<char, int> m;
        for (int i = 0; i < S.length(); i++) {
            m[S[i]] = i;
        }
        int left = 0, right = 0;
        for (int i = 0; i < S.length(); i++) {
            right = max (right, m[S[i]]);
            if (right == i) {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
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
