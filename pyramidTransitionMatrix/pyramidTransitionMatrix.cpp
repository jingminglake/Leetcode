#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char> > allowed_map;
        for (string s : allowed) {
            allowed_map[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom, allowed_map);
    }
    bool dfs(string bottom, unordered_map<string, vector<char> >& allowed_map) {
        if (bottom.size() == 1) {
            return true;
        }
        // check if it could generateNextLevel
        for (int i = 0; i < bottom.length() - 1; i++) {
            if (!allowed_map.count(bottom.substr(i, 2)))
                return false;
        }
        vector<string> allNext;
        string path;
        generateNextLevel(bottom, allNext, 0, path, allowed_map);
        for (string& next : allNext) {
            if (dfs (next, allowed_map))
                return true;
        }
        return false;
    }
    void generateNextLevel(string cur, vector<string>& res, int index, string& path, unordered_map<string, vector<char> >& allowed_map) {
        if (index == cur.length() - 1) {
            res.push_back(path);
            return;
        }
        string key = cur.substr(index, 2);
        for (char c : allowed_map[key]) {
            path += c;
            generateNextLevel (cur, res, index + 1, path, allowed_map);
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
