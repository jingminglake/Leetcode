#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        if (n == 0)
            return res;
        if (n == 1)
            return {"0", "1", "8"};
        vector<char> s_digits = {'0', '1', '6', '8', '9'};
        unordered_map<char, char> m;
        m['0'] = '0';
        m['1'] = '1';
        m['6'] = '9';
        m['8'] = '8';
        m['9'] = '6';
        string path;
        dfs(n / 2, s_digits, 0, path, res);
        if (n >= 2)
            extendRes(n, m, res);
        return res;
    }
    void dfs(int n, vector<char>& s_digits, int index, string& path, vector<string>& res) {
        if (index == n) {
            res.push_back(path);
            return;
        }
        for (char c : s_digits) {
            if (c == '0' && index == 0)
                continue;
            path.push_back(c);
            dfs(n, s_digits, index + 1, path, res);
            path.pop_back();
        }
    }
    void extendRes(int n, unordered_map<char, char>& m, vector<string>& res) {
        vector<string> new_res;
        vector<char> d = {'0', '1', '8'};
        if (n % 2) {
            for (char c : d) {
                for (string& str :res) {
                    new_res.push_back(str + c);
                }
            }
        } else {
            new_res = res;
        }
        int len = n / 2;
        for (string& str : new_res) {
            for (int i = len - 1; i >= 0; i--) {
                str += m[str[i]];
            }
        }
        res = new_res;
    }
};

int main()
{
    Solution s;
    for(string ss : s.findStrobogrammatic(10)) {
      cout << ss << " ";
    }
    return 0;
}
