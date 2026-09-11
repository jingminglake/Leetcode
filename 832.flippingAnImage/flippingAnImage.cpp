#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& row : A)
            reverse(row.begin(), row.end());
        for (auto& row : A)
            for (int& b : row)
                b ^= 1;
        return A;
    }
};

int main() {
    Solution s;
    vector<vector<int> > A = {{1,1,0},{1,0,1},{0,0,0}};
    for (auto& row : s.flipAndInvertImage(A)) {
        for (int b : row)
            cout << b << " ";
        cout << endl;
    }
    return 0;
}
