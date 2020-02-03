#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            m[key].push_back(str);
        }
        for (auto& p : m) {
            res.push_back(p.second);
        }
        return res;
    }
};

int main()
{
    Solution s;
    string ss[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> vec(ss, ss+6);
    vector<vector<string> > res = s.groupAnagrams(vec);
    for (vector<string>& v : res) {
        for (string s : v)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}
