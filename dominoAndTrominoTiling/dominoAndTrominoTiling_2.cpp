#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTilings(int N) {
        const int kMod = 1000000007;
        vector<long> dp1(N + 1, 0), dp2 = dp1, dp3 = dp1;
        dp1[0] = dp1[1] = dp2[1] = dp3[1] = 1;
        for (int i = 2; i <= N; i++) {
            dp1[i] = (dp1[i - 1] + dp1[i - 2] + dp2[i - 2] + dp3[i - 2]) % kMod;
            dp2[i] = (dp1[i - 1] + dp3[i - 1]) % kMod;
            dp3[i] = (dp1[i - 1] + dp2[i - 1]) % kMod;
        }
        return dp1[N];
    }
};

int main() {
    Solution s;
    cout << s.numTilings(5) << endl;
    return 0;
}
