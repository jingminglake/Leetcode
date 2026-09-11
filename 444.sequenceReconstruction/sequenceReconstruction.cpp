#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (org.size() == 0 || seqs.size() == 0)
            return false;
        unordered_map<int, int> m;
        unordered_set<int> s;
        for (int i = 0; i < org.size(); i++)
            m[org[i]] = i;
        bool exists = false;
        for (vector<int>& seq : seqs) {
            for (int i = 0; i < seq.size(); i++) {
                exists = true;
                if (!m.count(seq[i]))
                    return false;
                if (i == seq.size() - 1)
                    continue;
                int cur = seq[i], next = seq[i + 1];
                if (m[cur] >= m[next])
                    return false;
                else if (!s.count(seq[i]) && m[cur] + 1 == m[next])
                    s.insert(seq[i]);
            }
        }
        return exists && s.size() == org.size() - 1;
    }
};

int main() {
    Solution s;
    vector<int> org = {1,2,3};
    vector<vector<int> > seqs = {{1,2}, {1,3}, {2,3}};
    cout <<  s.sequenceReconstruction(org, seqs);
    cout << endl;
    return 0;
}
