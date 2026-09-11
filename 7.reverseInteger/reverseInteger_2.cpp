#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int64_t res = 0;
        while (x) {
            res = 10 * res + x % 10;
            x /= 10;
        }
        return (res > INT_MAX || res < INT_MIN) ? 0 : res;
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
