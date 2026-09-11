#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 > len2)
            return false;
        int hash[26] = {0};
        for (char c : s1)
            hash[c - 'a']++;
        int count = len1;
        int left = 0, right = 0;
        while (right < len2) {
            while (right - left < len1) {
                if (hash[s2[right++] - 'a']-- > 0) {
                    count--;
                }
                if (count == 0)
                    return true;
            }
            if (++hash[s2[left++] - 'a'] > 0)
                count++;
        }
        return false;
    }
};

int main()
{
    Solution s;
    string s1 = "abc";
    string s2 = "acobabacsd";
    cout << s.checkInclusion(s1, s2);
    cout << endl;
    return 0;
}
