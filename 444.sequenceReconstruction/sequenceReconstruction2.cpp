#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<vector<int> > neighbors(n + 1);
        unordered_set<int> nodes(org.begin(), org.end()), nodes_2 = nodes;
        vector<int> indegree(n + 1, 0);
        for (auto& seq : seqs) {
            for (int i = 0; i < seq.size(); i++) {
                if (!nodes.count(seq[i]))
                    return false;
                nodes_2.erase(seq[i]);
                if (i != 0) {
                    neighbors[seq[i - 1]].push_back(seq[i]);
                    indegree[seq[i]]++;
                }
            }
        }
        if (nodes_2.size())
            return false;
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        if (q.size() != 1)
            return false;
        int index = 0;
        while (!q.empty()) {
            if (q.size() != 1)
                return false;
            int node = q.front();
            q.pop();
            if (org[index++] != node)
                return false;
            for (int neighbor : neighbors[node]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return index == n; 
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
