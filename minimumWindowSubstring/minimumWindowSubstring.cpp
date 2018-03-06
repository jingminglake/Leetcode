#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        if (s.length() == 0 || t.length() == 0)
            return res;
        vector<int> hash(256, 0);
        for (char c : t)
            hash[c]++;
        int count = t.length();
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int start = 0;
        while (right < s.length()) {
            if (hash[s[right]]-- > 0)
                count--;
            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                if (++hash[s[left++]] > 0)
                    count++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main()
{
  Solution s;
  string S = "ADOBECODEBANC";
  string T = "ABC";
  cout << s.minWindow(S, T) << endl;
  return 0;
}
