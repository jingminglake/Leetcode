#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.length() == 0)
            return res;
        dfs(res, "", num, target, 0, 0, 0);
        return res;
    }
    void dfs(vector<string>& res, string path, string num, int target, int start, long val, long pre) {
        if (start == num.length()) {
            if (target == val) {
                res.push_back(path);
            }
            return;
        }
        for (int i = start; i < num.length(); i++) {
            if (i != start && num[start] == '0')
                break;
            string curS = num.substr(start, i - start + 1);
            long cur = stol(curS); 
            if (start == 0)
                dfs (res, path + to_string(cur), num, target, i + 1, cur, cur);
            else {
                dfs (res, path + "+" + curS, num, target, i + 1, val + cur, cur);
                dfs (res, path + "-" + curS, num, target, i + 1, val - cur, -cur);
                dfs (res, path + "*" + curS, num, target, i + 1, val - pre + pre * cur, pre * cur);
            }
        }
    }
};

int main()
{
  Solution s;
  string ss = "123";
  for(string& str : s.addOperators(ss, 6))
    cout << str << " ";
  cout << endl;
  return 0;
}
