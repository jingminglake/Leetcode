#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char, int> m;
        for (char c : s)
            m[c]++;
        vector<string> bucket(s.length() + 1, "");
        for (auto& p : m) {
            bucket[p.second] += string(p.second, p.first);
        }
        for (int i = bucket.size() - 1; i > 0; i--)
            res += bucket[i];
        return res;
    }
};

int main()
{
    Solution s;
    string ss = "tree";
    cout << s.frequencySort(ss);
    cout << endl;
    return 0;
}
