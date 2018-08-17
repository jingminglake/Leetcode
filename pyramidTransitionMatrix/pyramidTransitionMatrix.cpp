#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, unordered_set<char> > neighbors;
        for (string& s : allowed)
            neighbors[s.substr(0, 2)].insert(s.back());
        unordered_set<string> visited;
        return dfs(bottom, neighbors, visited);
    }
    bool dfs(string& bottom, unordered_map<string, unordered_set<char> >& neighbors, unordered_set<string>& visited) {
        if (bottom.length() == 1)
            return true;
        vector<string> nextLevel;
        string path;
        getNextLevel(0, path, bottom, neighbors, nextLevel);
        for (string& next : nextLevel) {
            if (visited.count(next))
                continue;
            visited.insert(next);
            if (dfs(next, neighbors, visited))
                return true;
        }
        return false;
    }
    void getNextLevel(int i, string& path, string& bottom, unordered_map<string, unordered_set<char> >& neighbors, vector<string>& nextLevel) {
        if (i == bottom.length() - 1) {
            nextLevel.push_back(path);
            return;
        }
        for (char c : neighbors[bottom.substr(i, 2)]) {
            path += c;
            getNextLevel(i + 1, path, bottom, neighbors, nextLevel);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    string bottom = "XYZ";
    vector<string> allowed = {"XYD", "YZE", "DEA", "FFF"}; 
    cout << s.pyramidTransition(bottom, allowed) << endl;
    return 0;
}
