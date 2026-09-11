// clang++ kthSmallestElementInASortedMatrix.cpp_2 -std=c++11

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution{
public:
    // 71.48%
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        while (left < right) {
            long mid = left + (right - left)/2;
            long num = 0;
            for (int i = 0; i < n; i++) {
                num += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (num < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main()
{
    Solution s;
    vector<int> row1 = {1,5,9};
    vector<int> row2 = {10,11,13};
    vector<int> row3 = {12,13,15};
    vector<vector<int> > matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    cout << s.kthSmallest(matrix, 8);
    cout << endl;
    return 0;
}
