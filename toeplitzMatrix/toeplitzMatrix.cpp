#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return false;
        for (int i = 0; i < matrix[0].size() - 1; i++) {
            int nextI = 0, nextJ = i;
            int num = matrix[nextI][nextJ];
            while (nextI >= 0 && nextI < matrix.size() && nextJ >= 0 && nextJ < matrix[0].size()) {
                if (num != matrix[nextI][nextJ])
                    return false;
                nextI++;
                nextJ++;
            }
        }
        for (int i = 1; i < matrix.size() - 1; i++) {
            int nextI = i, nextJ = 0;
            int num = matrix[nextI][nextJ];
            while (nextI >= 0 && nextI < matrix.size() && nextJ >= 0 && nextJ < matrix[0].size()) {
                if (num != matrix[nextI][nextJ])
                    return false;
                nextI++;
                nextJ++;
            }
        }
        return true;
    }
};

int main() {
  Solution s;
  vector<vector<int>> matrix = {{1,2,3,4}, {5,1,2,3}, {9,5,1,2}};
  cout << s.isToeplitzMatrix(matrix) << endl;
  return 0;
}
