#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0, right = A.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] < A[mid + 1])
                left = mid;
            else
                right = mid;
        }
        return right;
    }
};

int main() {
    Solution s;
    vector<int> A = {0,2,1,0};
    cout << s.peakIndexInMountainArray(A) << endl;
    return 0;
}
