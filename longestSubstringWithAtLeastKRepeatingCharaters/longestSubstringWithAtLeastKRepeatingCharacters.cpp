#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {        
        return longestSubstringHelper(s, k, 0, s.length() - 1);
    }
    int longestSubstringHelper(string& s, int k, int start, int end) {
        int hash[26] = {0};
        for (int i = start; i <= end; i++)
            hash[s[i] - 'a']++;
        // pruning
        while (start < end && hash[s[start] - 'a'] < k)
            start++;
        while (start < end && hash[s[end] - 'a'] < k)
            end--;
        for (int i = start; i <= end; i++) {
            if (hash[s[i] - 'a'] > 0 && hash[s[i] - 'a'] < k) {
                int left_res = longestSubstringHelper(s, k, start, i - 1);
                int right_res = longestSubstringHelper(s, k, i + 1, end);
                return max (left_res, right_res);
            }
        }
        return end - start + 1;
    }
};


int main()
{
  string s = "ababbc";
  Solution sl;
  cout << sl.longestSubstring(s, 2) << endl;
}
