#include <iostream>
using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        if (q == 0)
            return 0;
        int lcm = p * q / gcd(p, q);
        int v = lcm / p; // vertical bar number = vertical total len / p
        if (v % 2 == 0) // even
            return 0;
        int len_x = p * lcm / q;
        int h = len_x / p;
        if (h % 2)
            return 1;
        else
            return 2;
    }
    int gcd (int p, int q) {
        if (q == 0)
            return p;
        return gcd(q, p % q);
    }
};

int main() {
    Solution s;
    cout << s.mirrorReflection(2, 1) << endl;
    return 0;
}
