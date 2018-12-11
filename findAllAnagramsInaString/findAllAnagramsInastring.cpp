#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int s_len = s.length();
        int p_len = p.length();
        if (s_len < p_len)
            return res;
        int hash[26] = {0};
        for (int i = 0; i < p_len; i++)
            hash[p[i] - 'a']++;
        int count = p_len;
        int left = 0, right = 0;
        while (right < s_len) {
            if (--hash[s[right++] - 'a'] >= 0)
                count--;
            if (count == 0)
                res.push_back(left);
            if (right - left == p_len) {
                if (++hash[s[left++] - 'a'] > 0)
                    count++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string ss = "abab";
    string p = "ab";
    vector<int> ans = s.findAnagrams(ss, p);
    vector<int>::iterator it = ans.begin();
    while (it != ans.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    return 0;
}
