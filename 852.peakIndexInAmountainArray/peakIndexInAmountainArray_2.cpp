#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for (int i = 1; i < A.size() - 1; i++) {
            if (A[i] > A[i - 1] && A[i] > A[i + 1])
                return i;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> A = {0,2,1,0};
    cout << s.peakIndexInMountainArray(A) << endl;
    return 0;
}
