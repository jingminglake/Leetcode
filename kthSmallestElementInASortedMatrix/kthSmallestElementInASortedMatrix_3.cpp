// clang++ kthSmallestElementInASortedMatrix_3.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (n == 0)
            return -1;
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = countLessEqualTarget(matrix, mid);
            if (cnt < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    int countLessEqualTarget(vector<vector<int> >& matrix, int target) {
        int n = matrix.size(), i = n - 1, j = 0, res = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                res += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return res;
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
