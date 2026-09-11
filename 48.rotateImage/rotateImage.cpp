// clang++ rotateImage.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    void rotate(vector<vector<int> >& matrix) {
        reverse(matrix.begin(), matrix.end());
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> row1 = {5,1,9,11};
    vector<int> row2 = {2,4,8,10};
    vector<int> row3 = {13,3,6,7};
    vector<int> row4 = {15,14,12,16};
    vector<vector<int> > matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);
    s.rotate(matrix);
    int rowLen = matrix.size();
    int colLen = matrix[0].size();
    for (int i = 0; i < rowLen; i++) {
        for (int j = 0; j < colLen; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
