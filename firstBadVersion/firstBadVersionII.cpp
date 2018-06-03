#include <iostream>
using namespace std;

bool isBadVersion(int num) {
    if (num >= 8)
        return true;
    else
        return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (isBadVersion(left))
            return left;
        return right;
    }
};

int main()
{
    Solution s;
    cout << s.firstBadVersion(10) << endl;
    return 0;
}
