// clang++ kthSmallestElementInASortedMatrix.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Compare {
public:
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int res = 0;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int> >, Compare > pq;
        for (int i = 0; i < matrix.size(); i++)
            pq.emplace(matrix[i][0], i * n);
        for (int index = 0; index < k; index++) {
            pair<int, int> p = pq.top();
            pq.pop();
            res = p.first;
            int i = p.second / n;
            int j = p.second % n;
            if (j + 1 < n)
                pq.emplace(matrix[i][j + 1], i * n + j + 1);
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
