#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        vector<vector<int> > count(2 * n + 1, vector<int>(2 * n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 0)
                    continue;
                for (int i2 = 0; i2 < n; i2++) {
                    for (int j2 = 0; j2 < n; j2++) {
                        if (B[i2][j2] == 1)
                            count[i - i2 + n][j - j2 + n]++;
                    }
                }
            }
        } // for
        int res = 0;
        for (auto& row : count) {
            for (int c : row)
                res = max (res, c);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int> > A = {{1,1,0},
                     {0,1,0},
                     {0,1,0}};
    vector<vector<int> > B = {{0,0,0},
                     {0,1,1},
                     {0,0,1}};
    cout << s.largestOverlap(A, B) << endl;
    return 0;
}
