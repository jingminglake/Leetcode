#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int len_A = A.size();
        vector<int> preSum(len_A + 1);
        for (int i = 1; i <= len_A; i++)
            preSum[i] = preSum[i - 1] + A[i - 1];
        deque<int> dq;
        int res = len_A + 1;
        for (int i = 0; i <= len_A; i++) {
            while (!dq.empty() && preSum[i] - preSum[dq.front()] >= K) {
                res = min (res, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && preSum[i] <= preSum[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res == len_A + 1 ? -1 : res;
    }
};

int main() {
    Solution s;
    vector<int> A = {2,-1,2};
    int K = 3;
    cout << s.shortestSubarray(A, K) << endl;
    return 0;
}
