#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int res = (1 << (n - 1)) * m;
        for (int i = 0; i < m; i++) {
            if (A[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    A[i][j] += (A[i][j] == 1 ? -1 : 1);
                }
            }
        }
        for (int j = 1; j < n; j++) {
            int col_ones = 0;
            for (int i = 0; i < m; i++) {
                col_ones += A[i][j];
            }
            res += max (col_ones, m - col_ones) * (1 << (n - j - 1));
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int> > A = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    cout << s.matrixScore(A) << endl;
    return 0;
}
