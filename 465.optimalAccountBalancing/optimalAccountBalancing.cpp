#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> m;
        for (auto& t : transactions) {
            m[t[0]] -= t[2];
            m[t[1]] += t[2];
        }
        vector<int> accounts;
        for (auto& p : m) {
            if (p.second != 0)
                accounts.push_back(p.second);
        }
        return dfs(accounts, 0, 0);
    }
    int dfs (vector<int>& accounts, int start, int depth) {
        while (start < accounts.size() && accounts[start] == 0) // get next non-zero account
            start++;
        int res = INT_MAX;
        for (int i = start + 1; i < accounts.size(); i++) {
            if ( (accounts[i] < 0) ^ (accounts[start] < 0) ) {
                accounts[i] += accounts[start];
                res = min (res, dfs(accounts, start + 1, depth + 1));
                accounts[i] -= accounts[start];
            }
        }
        return res == INT_MAX ? depth : res;
    }
};

int main() {
    Solution s;
    vector<vector<int> > transactions = {{0,1,10}, {2,0,5}};
    cout << s.minTransfers(transactions) << endl;
    return 0;
}
