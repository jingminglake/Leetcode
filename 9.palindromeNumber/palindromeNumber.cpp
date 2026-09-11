#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int64_t res = 0;
        int64_t num = x;
        while (num) {
            res = res * 10 + num % 10;
            num = num / 10;
        }
        return x == res;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome(10) << endl;
    return 0;
}
