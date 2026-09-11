#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        long num = stol(n);
        for (int m = log(num + 1)/ log(2); m >= 2; m--) {
            long leftK = 2, rightK = pow (num, 1.0 / (m - 1)) + 1;
            while (leftK < rightK) {
                long mid = leftK + (rightK - leftK) / 2;
                long sum = 0;
                for (int i = 0; i < m; i++) {
                    sum = sum * mid + 1;
                }
                if (sum == num)
                    return to_string(mid);
                else if (sum < num)
                    leftK = mid + 1;
                else
                    rightK = mid;
            }
        }
        return to_string(num - 1);
    }
};

int main() {
    Solution s;
    string ss = "4681";
    cout << s.smallestGoodBase(ss);
    cout << endl;
    return 0;
}
