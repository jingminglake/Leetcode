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
        m.insert(make_pair('6', '9'));
        m.insert(make_pair('9', '6'));
        m.insert(make_pair('8', '8'));
        m.insert(make_pair('1', '1'));
        m.insert(make_pair('0', '0'));
        if (n == 1) {
            res.push_back("0");
            res.push_back("1");
            res.push_back("8");
            return res;
        }
        string digits = "01689";
        string path;
        dfs (res, n, path, digits, 0);
        return res;
    }
    void dfs(vector<string>& res, int n, string& path, string& digits, int start) {
        if (start > n)
            return;
        if (start == n) {
            if (stol(path) > pow(10, n - 1) && isStrobogrammatic(path) )
                res.push_back(path);
            return;
        }
        for (int j = 0; j < digits.length(); j++) {
            path += digits[j];
            dfs (res, n, path, digits, start + 1);
            path.pop_back();
        }
    }
    bool isStrobogrammatic(string& str) {
        int left = 0, right = str.size() - 1;
        while (left <= right) {
            if (!m.count(str[left]) || !m.count(str[right]))
                return false;
            else if (m[str[left]] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    unordered_map<char, char> m;
};

int main()
{
  Solution s;
  string num = "101";
  string num2 = "69";
  string num3 = "818";
  string num4 = "919";
  cout << s.isStrobogrammatic(num) << endl;
  cout << s.isStrobogrammatic(num2) << endl;
  cout << s.isStrobogrammatic(num3) << endl;
  cout << s.isStrobogrammatic(num4) << endl;
  return 0;
}
