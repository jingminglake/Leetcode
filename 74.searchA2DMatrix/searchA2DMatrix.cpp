// clang++ searchA2DMatrix.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int i = mid / n;
            int j = mid % n;
            if (matrix[i][j] < target) {
                left = mid;
            } else if (matrix[i][j] > target) {
                right = mid;
            } else {
                return true;
            }
        }
        if (matrix[left / n][left % n] == target || matrix[right / n][right % n] == target) return true;
        else return false;
    }
};

int main()
{
    Solution s;
    vector<int> row1 = {1,3,5,7};
    vector<int> row2 = {10,11,16,20};
    vector<int> row3 = {23,30,34,50};
    vector<int> row4 = {30,32,38,61};
    vector<vector<int> > matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);
    cout << s.searchMatrix(matrix, 3) << endl;
    return 0;
}
