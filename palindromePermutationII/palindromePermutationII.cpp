#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;
        for (char c : s) m[c]++;
        string half;
        string mid = "";
        int odd = 0;
        for (auto& p : m) {
            if (p.second % 2) {
                mid += p.first;
                odd++;
            }
            half += string(p.second / 2, p.first);
            if (odd > 1) return res;
        }
        vector<bool> visited(half.length(), false);
        string path;
        generatePerm(res, mid, half, visited, path);
        return res;
    }
    void generatePerm(vector<string>& res, string& mid, string& half, vector<bool>& visited, string& path) {
        if (path.length() == half.length()) {
            string r_path = path;
            reverse(r_path.begin(), r_path.end());
            res.push_back(path + mid + r_path);
            return;
        }
        for (int i = 0; i < half.length(); i++) {
            if (i != 0 && half[i] == half[i - 1] && !visited[i - 1])
                continue;
            if (!visited[i]) {
                path += half[i];
                visited[i] = true;
                generatePerm(res, mid, half, visited, path);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
};

int main() {
    Solution s;
    string str = "aaabb";
    for (string ss : s.generatePalindromes(str))
        cout << ss << " ";
    cout << endl;
    return 0;
}
