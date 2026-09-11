#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int64_t num = x;
        int sign = 1;
        if (x < 0) {
            sign = -1;
            num = -num;
        }
        int64_t res = 0;
        while (num) {
            res = 10 * res + num % 10;
            num /= 10;
            if (res > INT_MAX)
                return 0;
        }
        return res * sign;
    }
};

int main()
{
    Solution s;
    int a = -2143857412;
    cout << s.reverse(a) << endl;
    cout << INT_MAX << endl;
    return 0;
}
