#include <iostream>
using namespace std;

bool isBadVersion(int num) {
    if (num >= 8)
        return true;
    else
        return false;
}

/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        if (n == 1 && isBadVersion(1)) return 1;
        int left = 1, right = n;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (isBadVersion(left)) return left;
        if (isBadVersion(right)) return right;
        return -1;
    }
}

int main()
{
    Solution s;
    cout << s.firstBadVersion(10) << endl;
    return 0;
}
