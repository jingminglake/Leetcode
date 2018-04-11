#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_set<string> invalid;
        unordered_map<string, vector<char> > neighbors;
        for (string s : allowed) {
            neighbors[s.substr(0, 2)].push_back(s[2]);
        }
        return helper(bottom, invalid, neighbors);
    }
    bool helper(string bottom, unordered_set<string>& invalid, unordered_map<string, vector<char> >& neighbors) {
        if (bottom.length() <= 1)
            return true;
        if (invalid.count(bottom))
            return false;
        for (int i = 0; i < bottom.size() - 2; i++) {
            string key = bottom.substr(i, 2);
            if (!neighbors.count(key)) {
                invalid.insert(key);
                return false;
            }
        }
        string next(bottom.length() - 1, ' '); // decrease by one in next level
        if (dfs(bottom, invalid, neighbors, next, 0))
            return true;
        invalid.insert(bottom);
        return false;
    }
    bool dfs(string bottom, unordered_set<string>& invalid, unordered_map<string, vector<char> >& neighbors, string& next, int start) {
        if (start == bottom.size() - 1)
            return helper(next, invalid, neighbors);
        string key = bottom.substr(start, 2);
        for (char c : neighbors[key]) {
            next[start] = c;
            if (dfs(bottom, invalid, neighbors, next, start + 1))
                return true;
        }
        return false;
    }
};

int main() {
  Solution s;
  string bottom = "XYZ";
  vector<string> allowed = {"XYD", "YZE", "DEA", "FFF"}; 
  cout << s.pyramidTransition(bottom, allowed) << endl;
  return 0;
}
