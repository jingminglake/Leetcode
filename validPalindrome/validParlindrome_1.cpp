#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (!isAlphanumeric(s[left]) && left < right) left++;
            while (!isAlphanumeric(s[right]) && left < right) right--;
            if (left > right) return false;
            char c1 = isNumberic(s[left]) ? s[left] : toLower(s[left]);
            char c2 = isNumberic(s[right]) ? s[right] : toLower(s[right]);
            if (c1 != c2) return false;
            left++;right--;
        }
        return true;
    }
    
    bool isNumberic(char c) {
        return c >= '0' && c <= '9';
    }
    
    bool isAlphanumeric(char c) {
        if (c >= 'a' && c <= 'z') return true;
        else if (c >= 'A' && c <= 'Z') return true;
        else if (c >= '0' && c <= '9') return true;
        else return false;
    }
    
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') return c - 'A' + 'a' ;
        return c;
    }
};

int main()
{
    Solution s;
    //string str = "A man, a plan, a canal: Panama";
    string str = "0P";
    cout << s.isPalindrome(str) << endl;
    return 0;
}
