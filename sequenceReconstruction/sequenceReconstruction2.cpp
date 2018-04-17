#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, vector<int> > neighbors;
        unordered_map<int, int> indegree;
        for (vector<int>& seq : seqs) {
            for (int i = 0; i < seq.size(); i++) {
                if (!indegree.count(seq[i]))
                    indegree[seq[i]] = 0;
                if (i > 0) {
                    neighbors[seq[i - 1]].push_back(seq[i]);
                    indegree[seq[i]]++;
                }
            }
        }
        if (org.size() != indegree.size()) {
            return false;
        }
        queue<int> q;
        for (auto& p : indegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }
        int index = 0;
        while (!q.empty()) {
            if (q.size() > 1)
                return false;
            int cur = q.front();
            q.pop();
            if (org[index++] != cur)
                return false;
            for (int neighbor : neighbors[cur]) {
                if (--indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        return index == org.size();
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
