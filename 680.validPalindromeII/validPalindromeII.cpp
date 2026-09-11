#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
               return validPalindromeHelper(s, left + 1, right) || validPalindromeHelper(s, left, right - 1); 
            } else {
               left++; right--;
            }
        }
        return true;
    }
    bool validPalindromeHelper(string s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string ss = "aba";
    string ss1 = "abca";
    cout << s.validPalindrome(ss) << endl;
    cout << s.validPalindrome(ss1) << endl;
    return 0;
}
