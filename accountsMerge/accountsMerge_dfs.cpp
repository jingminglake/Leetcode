#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > neighbors;
        for (vector<string>& account : accounts) {
            for (int i = 2; i < account.size(); i++) {
                neighbors[account[1]].push_back(account[i]);
                neighbors[account[i]].push_back(account[1]);
            }
        }
        unordered_set<string> visited;
        for (vector<string>& account : accounts) {
            vector<string> path;
            path.push_back(account[0]);
            if (!visited.count(account[1])) {
                dfs (neighbors, visited, account[1], path);
                sort(path.begin(), path.end());
                res.push_back(path);
            }
            
        }
        return res;
    }
    void dfs (unordered_map<string, vector<string> >& neighbors, unordered_set<string>& visited, string& node, vector<string>& path) {
        path.push_back(node);
        visited.insert(node);
        for (string& neighbor : neighbors[node]) {
            if (!visited.count(neighbor)) {
                dfs (neighbors, visited, neighbor, path);
                visited.insert(node);
            }
        }
    }
};

int main()
{
  Solution s;
  vector<vector<string> > accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
  for (vector<string>& vec : s.accountsMerge(accounts))
    for (string ss : vec)
      cout << ss << " ";
  cout << endl;
  return 0;
}
