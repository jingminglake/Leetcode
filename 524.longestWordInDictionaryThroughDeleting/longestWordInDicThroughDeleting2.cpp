#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for (string& str : d) {
            if (str.size() < res.size())
                continue;
            int i = 0;
            for (char c : s) {
                if (i < str.size() && c == str[i])
                    i++;
            }
            if (i == str.size()) {
                if (i > res.size() || (i == res.size() && str < res))
                    res = str;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string s1 = "abpcplea";
    vector<string> dic = {"ale", "apple", "monkey", "plea"};
    cout << s.findLongestWord(s1, dic);
    cout << endl;
    return 0;
}
